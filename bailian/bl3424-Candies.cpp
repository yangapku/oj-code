#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#define MAXN 30010
#define MAXL 99999999
using namespace std;

struct Node{
    int d;
    int w;
    Node(int d,int w){this->d=d;this->w=w;}
};
bool operator >(const Node& n1,const Node& n2){
    return n1.w>n2.w;
}

int N,M,result=MAXL;
vector<vector<Node> > g;
char visited[MAXN];
priority_queue<Node,vector<Node>,greater<Node> > pq;

int main(){
    cin>>N>>M;
    g.resize(N+1);
    for(int i=1;i<=N;i++){
        visited[i]=0;
    }
    for(int i=0;i<M;i++){
        int s,d,w;
        cin>>s>>d>>w;
        g[s].push_back(Node(d,w));
    }
    pq.push(Node(1,0));
    while(!pq.empty()){
        Node cn=pq.top();
        pq.pop();
        int cs=cn.d,cw=cn.w;
        if(visited[cs]) continue;
        if(cs==N) {result=cw;break;}
        visited[cs]=1;
        for(int i=0;i<g[cs].size();i++){
            int d=g[cs][i].d;
            if(visited[d]) continue;
            Node nn=Node(d,cw+g[cs][i].w);
            pq.push(nn);
        }
    }
    cout<<result<<endl;
    return 0;
}