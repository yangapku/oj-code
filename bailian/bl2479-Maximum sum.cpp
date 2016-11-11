#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#define MAXN 50010
using namespace std;

int data[MAXN];
int l[MAXN];
int r[MAXN];
int rm[MAXN];
int T;

int main(){
	scanf("%d",&T);
	for(int ccc=0;ccc<T;ccc++){
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			int t;
			scanf("%d",&t);
			data[i]=t;
		}
		l[0]=data[0];
		for(int i=1;i<N;i++){
			l[i]=max(l[i-1]+data[i],data[i]);
		}
		r[N-1]=data[N-1];
		rm[N-1]=data[N-1];
		for(int i=(N-2);i>=0;i--){
			r[i]=max(r[i+1]+data[i],data[i]);
			rm[i]=max(rm[i+1],r[i]);
		}
		int result=l[0]+rm[1];
		for(int i=0;i<(N-1);i++){
			result=max(l[i]+rm[i+1],result);
		}
		cout<<result<<endl;
	}
}