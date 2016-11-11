#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAXN 55
using namespace std;

int record[MAXN][MAXN];
int N,K;
int result=0;

int main(){
    while(cin>>N>>K){
        for(int i=1;i<=K;i++){
        	record[i][1]=0;
        }
        for(int i=1;i<=N;i++){
        	record[1][i]=1;
        }
        for(int i=2;i<=N;i++){
        	for(int j=2;j<=K;j++){
        		int a1=record[j-1][i-1];
        		int a2;
        		if(i-j>0) a2=record[j][i-j];
        		else a2=0;
        		record[j][i]=a1+a2;
        	}
        }
        cout<<record[K][N]<<endl;
        for(int i=0;i<MAXN;i++){
            memset(record[i],0,sizeof(record[i]));
        }
        record[0][0]=1;
        for(int j=1;j<=N;j++){
            for(int r=0;r<=N;r++){
                int a1=record[j-1][r];
                int a2;
                if(r-j>=0) a2=record[j-1][r-j];
                else a2=0;
                record[j][r]=a1+a2;
            }
        }
        cout<<record[N][N]<<endl;
        for(int i=0;i<MAXN;i++){
            memset(record[i],0,sizeof(record[i]));
        }
        record[0][0]=1;
        for(int j=1;j<=N;j++){
            for(int r=0;r<=N;r++){
                if(j%2==0) record[j][r]=record[j-1][r];
                else{
                    int sum=0;
                    for(int t=0;r-t*j>=0;t++){
                        sum+=record[j-1][r-t*j];
                    }
                    record[j][r]=sum;
                }
            }
        }
        cout<<record[N][N]<<endl;
    }
}
