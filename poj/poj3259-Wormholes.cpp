#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAXN 520
#define MAXL 9999999
using namespace std;

struct Node{
    int d;
    int w;
    Node(int d,int w){this->d=d;this->w=w;}
};
vector<vector<Node> > g;
int F;
char inq[MAXN];
int dist[MAXN];

int main(){
    cin>>F;
    for(int i=0;i<F;i++){
        bool result=false;
        int N,M,W;
        cin>>N>>M>>W;
        for(int j=1;j<=N;j++){
            inq[j]=0;
            dist[j]=MAXL;
        }
        g.clear();
        g.resize(N+1);
        for(int j=0;j<M;j++){
            int s,d,w;
            cin>>s>>d>>w;
            g[s].push_back(Node(d,w));
            g[d].push_back(Node(s,w));
        }
        for(int j=0;j<W;j++){
            int s,d,w;
            cin>>s>>d>>w;
            g[s].push_back(Node(d,-w));
        }
        dist[1]=0;
        queue<int> q=queue<int>();
        q.push(1);
        inq[1]=1;
        while(!q.empty()){
            int cs=q.front();
            q.pop();
            inq[cs]=0;
            for(int k=0;k<g[cs].size();k++){
                int w=g[cs][k].w+dist[cs];
                int d=g[cs][k].d;
                if(w<dist[d]){
                    dist[d]=w;
                    if(inq[d]==0){
                        q.push(d);
                        inq[d]=1;
                    }
                }
            }
            if(dist[1]<0){result=true;break;}
        }
        if(result) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
