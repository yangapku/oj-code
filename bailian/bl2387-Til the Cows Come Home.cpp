#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#define MAXL 9999999
#define MAXN 1050
using namespace std;

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
priority_queue<Node,vector<Node>,greater<Node> > pq;

int main(){
    int T,N;
    cin>>T>>N;
    g.resize(N+1);
    for(int i=1;i<=N;i++){
        visited[i]=0;
    }
    for(int i=0;i<T;i++){
        int s,d,w;
        cin>>s>>d>>w;
        g[s].push_back(Node(d,w));
        g[d].push_back(Node(s,w));
    }
    pq.push(Node(N,0));
    while(!pq.empty()){
        Node cn=pq.top();
        pq.pop();
        int cd=cn.d;
        int cw=cn.w;
        if(visited[cd]==1) continue;
        if(cd==1){
            cout<<cw<<endl;
            break;
        }
        visited[cd]=1;
        for(int i=0;i<g[cd].size();i++){
            int nd=g[cd][i].d;
            int nw=g[cd][i].w;
            if(visited[nd]==0){
                pq.push(Node(nd,nw+cw));
            }
        }
    }
    return 0;
}
