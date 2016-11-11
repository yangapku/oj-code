#include<iostream>
#include<vector>
#define MAXN 110
#define MAXL 99999999
using namespace std;

int g[MAXN][MAXN];
char visited[MAXN];
int dist[MAXN];
int main(){
    int N;
    while(cin>>N){
        for(int i=0;i<N;i++){
            visited[i]=0;
            dist[i]=MAXL;
            for(int j=0;j<N;j++){
                int w;
                cin>>w;
                g[i][j]=w;
            }
        }
        for(int i=0;i<N;i++){
            dist[i]=g[0][i];
        }
        for(int i=0;i<N;i++){
            int nid=-1,temp=MAXL;
            for(int j=0;j<N;j++){
                if(visited[j]==0 && dist[j]<temp){
                    temp=dist[j];
                    nid=j;
                }
            }
            visited[nid]=1;
            for(int j=0;j<N;j++){
                if(visited[j]==0 && g[nid][j]<dist[j]){
                    dist[j]=g[nid][j];
                }
            }
        }
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=dist[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}