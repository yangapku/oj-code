#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

struct node
{
	int des;
	int len;
	int money;
	node(int a,int b,int c):des(a),len(b),money(c){}
	node(){}
};

int result=9999999;
vector<node> data[110];
int limitlen[110][10005];

void DFS(int st,int ed,int usedmoney,int usedlen,int totalmoney)
{
	if(st==ed)	{if(usedlen<result) result=usedlen;return;}
	int goal,mon,length;
	for(int i=0;i<data[st].size();i++)
	{
		goal=data[st][i].des;
		mon=data[st][i].money;
		length=data[st][i].len;
		if(mon+usedmoney>totalmoney||length+usedlen>result)
			continue;
		if(length+usedlen>limitlen[goal][mon+usedmoney]) continue;
		limitlen[goal][mon+usedmoney]=length+usedlen;
		DFS(goal,ed,mon+usedmoney,length+usedlen,totalmoney);
	}
	return ;
}

int main()
{
	for(int i=0;i<110;i++)
		for(int j=0;j<10005;j++)
			limitlen[i][j]=9999999;
	int n,k,r;
	cin>>k;
	cin>>n;
	cin>>r;
	int start,finish,L,T;
	for(int i=0;i<r;i++)
	{
		cin>>start>>finish>>L>>T;
		data[start].push_back(node(finish,L,T));
	}
	DFS(1,n,0,0,k);
	if(result==9999999) cout<<-1<<endl;
	else cout<<result<<endl;
	return 0;
}
