#include<iostream>
#include<string>
using namespace std;

struct node{
char info;
int num;
node* next[26];
node(char alpha='#'){this->info=alpha;this->num=0;for(int i=0;i<26;i++) this->next[i]=NULL;}
};

struct tree{
node* root;
tree(){root=new node;}
void enrich(string& word);
int stat(string& subword);
};

void tree::enrich(string& word)
{
    node* ptr=root;
    int length=word.size();
    char key;
    for(int i=0;i<length;i++)
    {
        key=word[i];
        if(!ptr->next[key-'a'])
            ptr->next[key-'a']=new node(key);
        ptr=ptr->next[key-'a'];ptr->num++;
    }
}

int tree::stat(string& subword)
{
    node* ptr=root;
    int length=subword.size();
    char key;
    for(int i=0;i<length;i++)
    {
        key=subword[i];
        if(!ptr->next[key-'a'])
            return 0;
        ptr=ptr->next[key-'a'];
    }
    return ptr->num;
}

int main()
{
    int n,m;string word;tree mytree;
    cin>>n;
    for(int i=0;i<n;i++)
    {cin>>word;mytree.enrich(word);}
    cin>>m;
    for(int i=0;i<m;i++)
    {cin>>word;cout<<mytree.stat(word)<<endl;}
    return 0;
}
