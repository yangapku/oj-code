#include<iostream>
#include<vector>
#include<queue>
#define MAXN 110
#define MAXL 999999999
using namespace std;

struct Node{
    int d;
    int w;
    Node(int d,int w){this->d=d;this->w=w;}
};
vector<vector<Node> > g;
char visited[MAXN];
int dist[MAXN];
int great[MAXN][MAXN];
int record[MAXN][MAXN];
int pprev[MAXN];
int gmat[MAXN][MAXN];

int main(){
    int t;
    cin>>t;
    for(int ccc=0;ccc<t;ccc++){
        int N,M;
        cin>>N>>M;
        for(int i=1;i<=N;i++){
            visited[i]=0;
            dist[i]=MAXL;
            pprev[i]=-1;
            for(int j=1;j<=N;j++){
                record[i][j]=0;
                great[i][j]=-1;
                gmat[i][j]=MAXL;
            }
        }
        g.clear();
        g.resize(N+1);
        for(int i=0;i<M;i++){
            int s,d,w;
            cin>>s>>d>>w;
            g[s].push_back(Node(d,w));
            g[d].push_back(Node(s,w));
            gmat[s][d]=w;
            gmat[d][s]=w;
        }
        for(int i=0;i<g[1].size();i++){
            int d=g[1][i].d;
            int w=g[1][i].w;
            dist[d]=w;
            pprev[d]=1;
        }
        visited[1]=1;
        dist[1]=0;
        int turn;
        for(turn=0;turn<(N-1);turn++){
            int id=-1,temp=MAXL;
            for(int i=1;i<=N;i++){
                if(pprev[i]!=-1 && visited[i]==0 && dist[i]<temp){
                    temp=dist[i];id=i;
                }
            }
            if(id==-1) {break;}
            visited[id]=1;
            int p=pprev[id];
            record[p][id]=1;
            record[id][p]=1;
            for(int i=0;i<g[id].size();i++){
                int d=g[id][i].d;
                int w=g[id][i].w;
                if(visited[d]==0 && w<dist[d]){
                    pprev[d]=id;
                    dist[d]=w;
                }
            }
            for(int i=1;i<=N;i++){
                if(i==p){
                    great[id][i]=dist[id];
                    great[i][id]=dist[id];
                }
                else if(visited[i]==1 && i!=id){
                    great[id][i]=max(great[i][p],dist[id]);
                    great[i][id]=max(great[i][p],dist[id]);
                }
            }
        }
        if(turn<(N-1)){
            cout<<0<<endl;
            continue;
        }
        int mst=0,smst=MAXL;
        for(int i=1;i<=N;i++){
            mst+=dist[i];
        }
        for(int i=1;i<=N;i++){
            for(int j=0;j<g[i].size();j++){
                int d=g[i][j].d;
                int w=g[i][j].w;
                if(record[i][d]==0){
                    int cmst=mst+w-great[i][d];
                    if(cmst<smst) smst=cmst;
                }
            }
        }
        if(smst==mst){
            cout<<"Not Unique!"<<endl;
        }
        else{
            cout<<mst<<endl;
        }
    }
}
