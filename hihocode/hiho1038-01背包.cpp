#include<iostream>
#include<algorithm>
using namespace std;

int need[600]={0};
int value[600]={0};
int main()
{
	int process[2][150000]={0};
	int n;
	cin>>n;
	int sum;
	cin>>sum;
	for(int i=0;i<n;i++)
	{
		cin>>need[i]>>value[i];
	}
	for(int t=need[0];t<=sum;t++) process[0][t]=value[0];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
			if(j>=need[i])
				process[1][j]=max(process[0][j],process[0][j-need[i]]+value[i]);
			else process[1][j]=process[0][j];
		for(int t=0;t<=sum;t++)
			process[0][t]=process[1][t];
	}
	cout<<process[0][sum]<<endl;
}