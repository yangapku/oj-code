#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#define MAXN 1000010
#define MAXL 100000000000LL
using namespace std;

struct Edge{
    long long int w;
    int d;
    int next;
}data1[MAXN],data2[MAXN];

int g[MAXN],revg[MAXN];

void addEdge(Edge* data,int id,int s,int* gg){
    if(gg[s]==-1){
        data[id].next=-1;
        gg[s]=id;
        return;
    }
    data[id].next=gg[s];
    gg[s]=id;
}

char inq[MAXN];
long long int dist[MAXN];

int main(){
    int N;
    scanf("%d",&N);
    for(int ccc=0;ccc<N;ccc++){
        int P,Q;
        long long int result=0LL;
        scanf("%d%d",&P,&Q);
        memset(g,-1,(P+2)*sizeof(int));
        memset(revg,-1,(P+2)*sizeof(int));
        for(int i=1;i<=P;i++){
            dist[i]=MAXL;
            inq[i]=0;
        }
        for(int i=0;i<Q;i++){
            int s,d;
            long long int w;
            scanf("%d%d%lld",&s,&d,&w);
            data1[i].d=d;
            data1[i].w=w;
            data2[i].d=s;
            data2[i].w=w;
            addEdge(data1,i,s,g);
            addEdge(data2,i,d,revg);
        }
        queue<int> q1,q2;
        q1.push(1);
        dist[1]=0LL;
        inq[1]=1;
        while(!q1.empty()){
            int cs=q1.front();
            q1.pop();
            inq[cs]=0;
            for(int eid=g[cs];eid!=-1;eid=data1[eid].next){
                int cd=data1[eid].d;
                long long int nw=data1[eid].w+dist[cs];
                if(nw<dist[cd]){
                    dist[cd]=nw;
                    if(inq[cd]==0){
                        inq[cd]=1;
                        q1.push(cd);
                    }
                }
            }
        }
        for(int i=1;i<=P;i++){
            result+=dist[i];
        }
        for(int i=1;i<=P;i++){
            dist[i]=MAXL;
            inq[i]=0;
        }
        q2.push(1);
        dist[1]=0LL;
        inq[1]=1;
        while(!q2.empty()){
            int cs=q2.front();
            q2.pop();
            inq[cs]=0;
            for(int eid=revg[cs];eid!=-1;eid=data2[eid].next){
                int cd=data2[eid].d;
                long long int nw=data2[eid].w+dist[cs];
                if(nw<dist[cd]){
                    dist[cd]=nw;
                    if(inq[cd]==0){
                        inq[cd]=1;
                        q2.push(cd);
                    }
                }
            }
        }
        for(int i=1;i<=P;i++){
            result+=dist[i];
        }
        printf("%lld\n",result);
    }
    return 0;
}
