#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#define MAXN 110
using namespace std;

int dist[MAXN][MAXN];
char visited[MAXN];
struct Node{
    int d;
    int w;
    Node(int d,int w){this->d=d;this->w=w;}
};
bool operator >(const Node& n1,const Node& n2){
    return n1.w>n2.w;
}
vector<vector<Node> > g;

int main(){
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            dist[i][j]=-1;
        }
    }
    g.resize(N+1);
    for(int i=0;i<M;i++){
        int s,d;
        cin>>s>>d;
        g[s].push_back(Node(d,1));
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            visited[j]=0;
        }
        priority_queue<Node,vector<Node>,greater<Node> > pq;
        pq.push(Node(i,0));
        while(!pq.empty()){
            Node cn=pq.top();
            pq.pop();
            int cd=cn.d;
            int cw=cn.w;
            if(visited[cd]==1) continue;
            visited[cd]=1;
            dist[i][cd]=cw;
            for(int k=0;k<g[cd].size();k++){
                int nd=g[cd][k].d;
                int nw=g[cd][k].w;
                int ntw=nw+cw;
                if(visited[nd]==0){
                    pq.push(Node(nd,ntw));
                }
            }
        }
    }
    int result=0;
    for(int i=1;i<=N;i++){
        int score=0;
        for(int j=1;j<=N;j++){
            if(dist[i][j]>0 || dist[j][i]>0) score++;
        }
        if(score==(N-1)) result++;
    }
    cout<<result<<endl;
    return 0;
}
