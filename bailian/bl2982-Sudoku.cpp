#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

struct node
{
	int x;
	int y;
	node(int a,int b){x=a;y=b;}
	node(){}
};

string data[9];
int matrix[9][9]={0};
vector<node> nodevex;
bool flag=false;

bool issafe(int x,int y,int num)
{
	for(int i=0;i<9;i++) if(matrix[i][y]==num||matrix[x][i]==num) return false;
	int a=x/3,b=y/3;
	for(int i=3*a;i<3*a+3;i++)
		for(int j=3*b;j<3*b+3;j++)
			if(matrix[i][j]==num) return false;
	return true;
}

void DFS(int index,int num)
{
	if(index==nodevex.size())
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
				cout<<matrix[i][j];
			cout<<endl;
		}
		flag=true;
		return ;
	}
	if(issafe(nodevex[index].x,nodevex[index].y,num))
	{
		matrix[nodevex[index].x][nodevex[index].y]=num;
		for(int i=1;flag==false&&i<=9;i++)
			DFS(index+1,i);
		matrix[nodevex[index].x][nodevex[index].y]=0;
	}
}

void solve()
{
	nodevex.clear();
	flag=false;
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
			matrix[i][j]=data[i][j]-'0';
			if(matrix[i][j]==0) nodevex.push_back(node(i,j));
		}
	for(int i=1;i<=9;i++)
		DFS(0,i);
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<9;j++)
			cin>>data[j];
		solve();
	}
	return 0;
}

