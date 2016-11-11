#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<queue>
#define MAXN 600
using namespace std;

int data[MAXN][MAXN];
int l[MAXN];
int sumdata[MAXN];
int result=-9999999;

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int t;
			scanf("%d",&t);
			data[i][j]=t;
		}
	}
	for(int i=0;i<N;i++){
		for(int r=0;r<N;r++){
			sumdata[r]=0;
		}
		for(int j=i;j<N;j++){
			for(int r=0;r<N;r++){
				sumdata[r]+=data[j][r];
			}
			l[0]=sumdata[0];
			result=max(result,l[0]);
			for(int r=1;r<N;r++){
				l[r]=max(l[r-1]+sumdata[r],sumdata[r]);
				if(l[r]>result) result=l[r];
			}
		}
	}
	cout<<result<<endl;
}