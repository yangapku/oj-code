#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#define MAXN 22
#define UP 0
#define DOWN 1
using namespace std;

char visited[MAXN];
long long int record[MAXN][MAXN][2];
int K;
int cN=1;

void solve(int N,long long int C){
    memset(visited,0,sizeof(visited));
    if(N>cN){
        for(int i=cN+1;i<=N;i++){
            long long int dsum=0,usum=0;
            for(int j=1;j<=(i-1);j++){
                dsum+=record[i-1][j][DOWN];
                usum+=record[i-1][j][UP];
            }
            for(int j=1;j<=i;j++){
                record[i][j][UP]=dsum;
                record[i][i+1-j][DOWN]=usum;
                if(dsum>0) dsum-=record[i-1][j][DOWN];
                if(usum>0) usum-=record[i-1][i-j][UP];
            }
        }
        cN=N;
    }
    long long int remain=C;
    long long int canup=1,candown=1;
    int prev=0;
    for(int i=N;i>=1;i--){
        long long int sumid=0;
        int bid,eid;
        if(canup==1){
            bid=1;eid=prev;
        }
        else{
            bid=prev;eid=i;
        }
        if(i==N){
            bid=1;eid=N;
        }
        for(int j=bid;j<=eid;j++){
            sumid+=canup*record[i][j][UP]+candown*record[i][j][DOWN];
            if(sumid>=remain){
                int pos=0;
                for(int r=1;r<=N;r++){
                    if(visited[r]==0) pos++;
                    if(pos==j){
                        visited[r]=1;
                        prev=j;
                        cout<<r<<' ';
                        if(i==N){
                            long long int rr=sumid-record[i][j][UP]-record[i][j][DOWN];
                            if(rr+record[i][j][DOWN]>=remain){
                                remain=remain-(sumid-record[i][j][UP]-record[i][j][DOWN]);
                                canup=1;candown=0;
                            }
                            else{
                                remain=remain-(sumid-record[i][j][UP]);
                                canup=0;candown=1;
                            }
                        }
                        else{
                            remain=remain-(sumid-canup*record[i][j][UP]-candown*record[i][j][DOWN]);
                            canup=1-canup;
                            candown=1-candown;
                        }
                        break;
                    }
                }
                break;
            }
        }
    }
    cout<<endl;
}

int main(){
    record[1][1][UP]=1;
    record[1][1][DOWN]=1;
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        int N;
        long long int C;
        scanf("%d",&N);
        scanf("%lld",&C);
        solve(N,C);
    }
    return 0;
}
