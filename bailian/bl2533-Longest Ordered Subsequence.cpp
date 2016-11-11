#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	int data[2000]={0};
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>data[i];
	int result[2000]={0};
	for(int i=0;i<n;i++)
	{
		int count=0;
		for(int j=0;j<i;j++)
		{
			if(data[j]<data[i]&&result[j]>count) count=result[j];
		}
		result[i]=count+1;
	}
	cout<<*max_element(result,result+n);
	return 0;
}
