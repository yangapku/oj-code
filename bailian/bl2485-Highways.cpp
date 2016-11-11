#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<stdio.h>
#define MAXN 550
#define MAXL 99999999
using namespace std;

int g[MAXN][MAXN];
int dist[MAXN];
int visited[MAXN];
int main(){
    int T;
    scanf("%d",&T);
    for(int ccc=0;ccc<T;ccc++){
        int N;
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            dist[i]=MAXL;
            visited[i]=0;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int l;
                scanf("%d",&l);
                g[i][j]=l;
            }
        }
        dist[0]=0;
        visited[0]=1;
        for(int i=1;i<N;i++){
            dist[i]=g[0][i];
        }
        for(int i=1;i<N;i++){
            int id=-1,temp=MAXL;
            for(int j=0;j<N;j++){
                if(visited[j]==0 && dist[j]<temp){
                    temp=dist[j];
                    id=j;
                }
            }
            visited[id]=1;
            for(int j=0;j<N;j++){
                if(visited[j]==0 && g[id][j]<dist[j]){
                    dist[j]=g[id][j];
                }
            }
        }
        int result=-1;
        for(int i=0;i<N;i++){
            if(dist[i]>result) result=dist[i];
        }
        cout<<result<<endl;
    }
}
