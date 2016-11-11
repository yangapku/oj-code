#include<iostream>
#include<algorithm>
using namespace std;

int exp(int a,int b)
{
	int result=1;
	for(int i=0;i<b;i++)
		result*=a;
	return result;
}
bool sum(int num,int m,int q)
{
	int count=0;
	for(int i=0;i<m;i++)
		if(num&exp(2,i)) count++;
	return(count<=q);
}

int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	int value[2000]={0};
	for(int i=0;i<n;i++)
		cin>>value[i];
	int process[2][2000]={0};
	for(int i=0;i<exp(2,m);i++)
	{
		if(sum(i,m,q)==false) continue;
		if(i&1)
		{
			process[0][i]=value[0];
		}
		else
		{
			process[0][i]=0;
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<exp(2,m);j++)
		{
			if(sum(j,m,q)==false) continue;
			process[1][(j*2+1)&(exp(2,m)-1)]=max(process[1][(j*2+1)&(exp(2,m)-1)],process[0][j]+value[i]);
			process[1][(j*2)&(exp(2,m)-1)]=max(process[1][(j*2)&(exp(2,m)-1)],process[0][j]);
		}
		for(int z=0;z<exp(2,m);z++)
			process[0][z]=process[1][z];
		for(int z=0;z<exp(2,m);z++)
			process[1][z]=0;
	}
	int result=0;
	for(int j=0;j<exp(2,m);j++)
	{
		if(sum(j,m,q)&&process[0][j]>result) result=process[0][j];
	}
	cout<<result<<endl;
	return 0;
}
