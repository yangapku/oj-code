#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<functional>
#define MAXN 510
#define MAXL 999999999
using namespace std;

char visited[MAXN];
char ved[MAXN];
char inst[MAXN];
stack<int> st;
int tim=-1;
struct Info{
    int dst;
    int low;
};
struct Node{
    int d;
    int w;
    Node(int d,int w){this->d=d;this->w=w;}
};
vector<Node> g[MAXN];
vector<Node> newg[MAXN];
Info data[MAXN];
int flag[MAXN];
int flagc=0;
int dist[MAXN][MAXN];
int N,E;
char solved[MAXN];

bool operator >(const Node& n1,const Node& n2){
    return n1.w>n2.w;
}

void tarjan(int pos){
    data[pos].dst=tim;
    data[pos].low=tim;
    st.push(pos);
    inst[pos]=1;
    for(int i=0;i<g[pos].size();i++){
        int d=g[pos][i].d;
        if(visited[d]==0){
            tim++;
            visited[d]=1;
            tarjan(d);
            data[pos].low=min(data[pos].low,data[d].low);
        }
        else if(inst[d]==1){
            data[pos].low=min(data[pos].low,data[d].dst);
        }
    }
    if(data[pos].low==data[pos].dst){
        while(1){
            int r=st.top();
            st.pop();
            inst[r]=0;
            flag[r]=flagc;
            if(r==pos) break;
        }
        flagc++;
    }
}

void solve(int i){
    priority_queue<Node,vector<Node>,greater<Node> > pq;
    for(int j=0;j<flagc;j++){
        ved[j]=0;
    }
    pq.push(Node(i,0));
    while(!pq.empty()){
        Node cn=pq.top();
        pq.pop();
        int cs=cn.d;
        if(ved[cs]==1) continue;
        ved[cs]=1;
        int cw=cn.w;
        dist[i][cs]=cw;
        for(int j=0;j<newg[cs].size();j++){
            int nd=newg[cs][j].d;
            if(ved[nd]==0){
                int nw=newg[cs][j].w;
                pq.push(Node(nd,nw+cw));
            }
        }
    }
    solved[i]=1;
}

int main(){
    while(1){
        scanf("%d%d",&N,&E);
        if(N==0) break;
        st=stack<int>();
        tim=-1;
        flagc=0;
        for(int i=1;i<=N;i++){
            g[i].clear();
            visited[i]=0;
            inst[i]=0;
            flag[i]=-1;
        }
        for(int i=0;i<E;i++){
            int s,d,w;
            scanf("%d%d%d",&s,&d,&w);
            g[s].push_back(Node(d,w));
        }
        for(int i=1;i<=N;i++){
            if(visited[i]==0){
                tim++;
                visited[i]=1;
                tarjan(i);
            }
        }
        for(int i=0;i<flagc;i++){
            newg[i].clear();
        }
        for(int i=1;i<=N;i++){
            int fs=flag[i];
            for(int j=0;j<g[i].size();j++){
                int d=g[i][j].d;
                int fd=flag[d];
                if(fs!=fd){
                    int w=g[i][j].w;
                    newg[fs].push_back(Node(fd,w));
                }
            }
        }
        for(int i=0;i<flagc;i++){
            solved[i]=0;
            for(int j=0;j<flagc;j++){
                dist[i][j]=MAXL;
            }
        }
        int T;
        scanf("%d",&T);
        for(int i=0;i<T;i++){
            int ss,dd;
            scanf("%d%d",&ss,&dd);
            int flags=flag[ss];
            int flagd=flag[dd];
            if(flags==flagd){
                printf("0\n");
            }
            else{
                if(solved[flags]==0){
                    solve(flags);
                }
                int res=dist[flags][flagd];
                if(res==MAXL){
                    printf("Nao e possivel entregar a carta\n");
                }
                else{
                    printf("%d\n",res);
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
