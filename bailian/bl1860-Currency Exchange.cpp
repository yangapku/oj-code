#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#define MAXN 110
using namespace std;

char inq[MAXN];
double dist[MAXN];
int leng[MAXN];
queue<int> q;
struct Node{
    int d;
    double comm;
    double rat;
    Node(int d,double c,double r){
        this->d=d;
        this->comm=c;
        this->rat=r;
    }
};
vector<vector<Node> > g;

int main(){
    int N,M,S;
    double bp;
    scanf("%d",&N);
    scanf("%d",&M);
    scanf("%d",&S);
    scanf("%lf",&bp);
    g.clear();
    g.resize(N+1);
    for(int i=0;i<M;i++){
        int s,d;
        double r1,c1,r2,c2;
        scanf("%d",&s);
        scanf("%d",&d);
        scanf("%lf",&r1);
        scanf("%lf",&c1);
        scanf("%lf",&r2);
        scanf("%lf",&c2);
        g[s].push_back(Node(d,c1,r1));
        g[d].push_back(Node(s,c2,r2));
    }
    for(int i=1;i<=N;i++){
        inq[i]=0;
        dist[i]=0.0;
        leng[i]=-1;
    }
    leng[S]=0;
    dist[S]=-bp;
    q.push(S);
    inq[S]=1;
    while(!q.empty()){
        int cs=q.front();
        q.pop();
        for(int i=0;i<g[cs].size();i++){
            int cd=g[cs][i].d;
            double np=(dist[cs]+g[cs][i].comm)*g[cs][i].rat;
            if(np<dist[cd]){
                dist[cd]=np;
                leng[cd]=leng[cs]+1;
                if(inq[cd]==0){
                    q.push(cd);
                }
            }
        }
        if(leng[S]>0){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
