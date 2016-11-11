#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	int data[1000][1000]={0};
	cin>>n;
	for(int j=0;j<n;j++)
		for(int k=0;k<=j;k++)
			cin>>data[j][k];
	int tempadd[1000][1000]={0};
	tempadd[0][0]=data[0][0];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0) tempadd[i][j]=tempadd[i-1][0]+data[i][j];
			else if(j==i) tempadd[i][j]=tempadd[i-1][i-1]+data[i][i];
			else tempadd[i][j]=(tempadd[i-1][j-1]>tempadd[i-1][j]?tempadd[i-1][j-1]:tempadd[i-1][j])+data[i][j];
		}
	}
	cout<<*max_element(tempadd[n-1],tempadd[n-1]+n)<<endl;
}
