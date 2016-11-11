#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

vector<int> data;
vector<bool> isused;
bool flag=false;

void DFS(int index,int last,int len)
{
	int j,pre=-1;
	isused[index]=true;
	if(data[index]==last)
	{
		for(j=0;j<data.size();j++)
			if(!isused[j]) break;
		if(j==data.size()) {flag=true;return;}
		DFS(j,len,len);
	}
	else{
	for(int i=index+1;i<data.size()&&flag==false;i++)
	{
		if(isused[i]==true||data[i]>last-data[index]||data[i]==pre) continue;
		DFS(i,last-data[index],len);
		if(last-data[index]==0) break;
		pre=data[i];
	}}
	isused[index]=false;
}

void solve()
{
	int sum=0;
	for(int i=0;i<data.size();i++)
		sum+=data[i];
	int maxlen=*max_element(data.begin(),data.end());
	for(int length=maxlen;(length<=sum);length++)
	{
		if(sum%length!=0) continue;
		DFS(0,length,length);
		if(flag) {cout<<length<<endl;return;}
	}
	cout<<"no solution"<<endl;
}

int main()
{
	int count,stick;
	while(1)
	{
		cin>>count;
		if(!count) break;
		data.clear();
		isused.clear();
		flag=false;
		for(int i=0;i<count;i++)
		{
			cin>>stick;
			data.push_back(stick);
			isused.push_back(false);
		}
		sort(data.begin(),data.end(),greater<int>());
		solve();
	}
	return 0;
}
