#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cstdio>
using namespace std;
const int MAXN=10000;

vector<int> g[MAXN];
vector<int> revg[MAXN];
stack<int> st;
char visited[MAXN];
char inst[MAXN];
struct Info{
    int dst;
    int low;
};
Info data[MAXN];
int flag[MAXN];
int flagc=0;
int tim=-1;

void tarjan(int pos,int N){
    data[pos].dst=tim;
    data[pos].low=tim;
    st.push(pos);
    inst[pos]=1;
    for(int i=0;i<g[pos].size();i++){
        int d=g[pos][i];
        if(visited[d]==0){
            tim++;
            visited[d]=1;
            tarjan(d,N);
            data[pos].low=min(data[pos].low,data[d].low);
        }
        else if(inst[d]==1){
            data[pos].low=min(data[pos].low,data[d].dst);
        }
    }
    if(data[pos].dst==data[pos].low){
        while(1){
            int r=st.top();
            st.pop();
            flag[r]=flagc;
            inst[r]=0;
            if(r==pos) break;
        }
        flagc++;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for(int ccc=0;ccc<T;ccc++){
        for(int i=0;i<MAXN;i++) {g[i].clear();revg[i].clear();}
        st=stack<int>();
        tim=-1;
        flagc=0;
        int N,M;
        scanf("%d%d",&N,&M);
        for(int i=0;i<M;i++){
            int s,d;
            scanf("%d%d",&s,&d);
            g[s].push_back(d);
            revg[d].push_back(s);
        }
        for(int i=1;i<=N;i++){
            visited[i]=0;
            inst[i]=0;
            flag[i]=-1;
        }
        for(int i=1;i<=N;i++){
            if(visited[i]==0){
                tim++;
                visited[i]=1;
                tarjan(i,N);
            }
        }
        int inc=0,outc=0;
        for(int i=0;i<flagc;i++){
            bool noout=true;
            for(int j=1;j<=N;j++){
                if(noout==true && flag[j]==i){
                    for(int t=0;t<g[j].size();t++){
                        int d=g[j][t];
                        if(flag[d]!=flag[j]){
                            noout=false;
                            break;
                        }
                    }
                }
            }
            if(noout) outc++;
        }
        for(int i=0;i<flagc;i++){
            bool noin=true;
            for(int j=1;j<=N;j++){
                if(noin==true && flag[j]==i){
                    for(int t=0;t<revg[j].size();t++){
                        int s=revg[j][t];
                        if(flag[s]!=flag[j]){
                            noin=false;
                            break;
                        }
                    }
                }
            }
            if(noin) inc++;
        }
        if(inc==1 && outc==1){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
