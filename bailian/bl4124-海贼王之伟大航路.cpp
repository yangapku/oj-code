#include<stdio.h>
#include<vector>
#include<string.h>
#include<map>
using namespace std;
vector<int> data[16];
int limitlength[16][50000];
int result=99999999;
int calcu(int x,int y)
{
	int cal=1;
	for(int i=0;i<y;i++)
		cal*=x;
	return cal;
}

void DFS(int st,int len,int trace,int n)
{
	if((calcu(2,n-1)-1)==trace) {if(len+data[st][n-1]<result) result=len+data[st][n-1]; return;}
	map<int,int> temp;
	for(int i=1;i<=n-2;i++)
	{
		int foot=1<<i;
		if((0==(trace&foot))&&(len+data[st][i]<=result)&&(len+data[st][i]<=limitlength[i][trace]))
		{
			temp.insert(make_pair(data[st][i],i));
		}
	}
	map<int,int>::iterator j;
	for(j=temp.begin();j!=temp.end();j++)
	{
		int i=j->second;
		limitlength[i][trace]=len+data[st][i];
		DFS(i,len+data[st][i],trace|1<<i,n);
	}
}

int main()
{
	for(int i=0;i<16;i++)
		memset(limitlength[i],0x59,sizeof(limitlength[i]));
	int n,edge;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&edge);
			data[i].push_back(edge);
		}
	DFS(0,0,1,n);
	printf("%d",result);
}
