#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define MAXN 1050
#define MAXL 99999999
using namespace std;

queue<int> q;
char inq[MAXN];
int dist[MAXN][MAXN];
char isstart[MAXN];
vector<vector<int> > g;
int K,N,M;

int main(){
    cin>>K>>N>>M;
    g.resize(N+1);
    for(int i=1;i<=N;i++){
        isstart[i]=0;
    }
    for(int i=0;i<K;i++){
        int s;
        cin>>s;
        isstart[s]=1;
    }
    for(int i=0;i<M;i++){
        int s,d;
        cin>>s>>d;
        g[s].push_back(d);
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            dist[i][j]=MAXL;
        }
    }
    for(int i=1;i<=N;i++){
        if(isstart[i]){
            q=queue<int>();
            for(int j=1;j<=N;j++){
                inq[j]=0;
            }
            q.push(i);
            inq[i]=1;
            dist[i][i]=0;
            while(!q.empty()){
                int cs=q.front();
                q.pop();
                inq[cs]=0;
                for(int j=0;j<g[cs].size();j++){
                    int cd=g[cs][j];
                    int cw=dist[i][cs]+1;
                    if(cw<dist[i][cd]){
                        dist[i][cd]=cw;
                        if(inq[cd]==0){
                            q.push(cd);
                            inq[cd]=1;
                        }
                    }
                }
            }
        }
    }
    int result=0;
    char can[MAXN];
    memset(can,1,sizeof(can));
    for(int i=1;i<=N;i++){
        if(isstart[i]==1){
            for(int j=1;j<=N;j++){
                if(dist[i][j]==MAXL){
                    can[j]=0;
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(can[i]==1) result++;
    }
    cout<<result<<endl;
}
