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
	for(int t=0;t<=sum;t++) process[0][t]=t/need[0]*value[0];
	for(int i=1;i<n;i++)
	{
		for(int t=0;t<=sum;t++)
		{
			int best=0;
			for(int combo=0;combo<=t/need[i];combo++)
			{
				best=max(best,process[0][t-combo*need[i]]+value[i]*combo);
			}
			process[1][t]=best;
		}
		for(int u=0;u<=sum;u++)
			process[0][u]=process[1][u];
	}
	cout<<process[0][sum]<<endl;
}
