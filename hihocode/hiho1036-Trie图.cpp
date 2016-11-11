#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct trienode
{
	trienode* back;
	trienode* next[26];
	bool flag;
	trienode(){this->back=NULL;for(int i=0;i<26;i++) this->next[i]=NULL;flag=false;}
};

void addword(trienode& mytree,string& word)
{
	trienode* ptr=&mytree;
	int i;
	for(i=0;i<word.length();i++)
		if(ptr->next[word[i]-'a']) ptr=ptr->next[word[i]-'a'];
		else break;
	while(i<word.length())
	{
		ptr->next[word[i]-'a']=new trienode;
		ptr=ptr->next[word[i]-'a'];
		i++;
	}
	ptr->flag=true;
}

void addback(trienode& mytree)
{
	queue<trienode*> myqueue;
	trienode* ptr=NULL;
	myqueue.push(&mytree);
	mytree.back=NULL;
	while(!myqueue.empty())
	{
		ptr=myqueue.front();
		myqueue.pop();
		for(int j=0;j<26;j++)
			if(ptr->next[j]) myqueue.push(ptr->next[j]);
		for(int i=0;i<26;i++)
			if(ptr->next[i])
			{
				trienode* ptrback=ptr->back;
				while((ptrback!=NULL)&&(!ptrback->next[i])) ptrback=ptrback->back;
				if(ptrback==NULL) ptr->next[i]->back=&mytree;
				else ptr->next[i]->back=ptrback->next[i];
			}
	}
}

bool ACmachine(trienode& mytree,string& word)
{
	trienode* ptr=&mytree;
	for(int i=0;i<word.length();i++)
	{
		while(ptr!=NULL&&!ptr->next[word[i]-'a']) ptr=ptr->back;
		if(ptr!=NULL)
		{
			ptr=ptr->next[word[i]-'a'];
			if(ptr->flag) return true;
		}
		else ptr=&mytree;
	}
	return false;
}

int main()
{
	void addword(trienode& mytree,string& word);
	void addback(trienode& mytree);
	bool ACmachine(trienode& mytree,string& word);
	int n;
	cin>>n;
	trienode mytree;
	string word;
	for(int j=0;j<n;j++)
	{
		cin>>word;
		addword(mytree,word);
	}
	addback(mytree);
	cin>>word;
	if(ACmachine(mytree,word)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
