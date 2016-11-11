#include<iostream>
#include<string>
using namespace std;

int KMP(string& pattern,string& word)
{
	int* next=new int[pattern.size()];
	int k=-1,i;
	next[0]=-1;
	for(i=0;i<pattern.size()-1;)
	{
		if(k==-1) {next[i+1]=0;i++;k++;}
		else if(pattern[k]==pattern[i]) {next[i+1]=k+1;i++;k++;}
		else k=next[k];
	}
	int count=0;
	i=0,k=0;
	while(i<word.size())
	{
		if(k==pattern.size()-1) count++;
		if(k==-1||word[i]==pattern[k]){i++;k++;}
		else k=next[k];
	}
	if(k==pattern.size()-1) count++;
	return count;
}

int main()
{
	string pattern,word;
	int number,result=0;
	cin>>number;
	while(number)
	{
		result=0;
		cin>>pattern;
		cin>>word;
		pattern=pattern+"*";
		number--;
		result=KMP(pattern,word);
		cout<<result<<endl;
	}
	return 0;
}
