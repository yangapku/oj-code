#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#define MAXN 110
using namespace std;

struct Info{
    int dst;
    int low;
};
vector<vector<int> > g;
vector<vector<int> > revg;
stack<int> st;
Info data[MAXN];
char visited[MAXN];
int tim=-1;
int flag[MAXN];
int inst[MAXN];
int flagc=0;
int N;

void tarjan(int pos){
    data[pos].dst=tim;
    data[pos].low=tim;
    st.push(pos);
    inst[pos]=1;
    for(int i=0;i<g[pos].size();i++){
        int d=g[pos][i];
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
    cin>>N;
    g.resize(N+1);
    revg.resize(N+1);
    for(int i=1;i<=N;i++){
        visited[i]=0;
        flag[i]=-1;
        inst[i]=0;
        while(1){
            int d;
            cin>>d;
            if(d==0) break;
            g[i].push_back(d);
            revg[d].push_back(i);
        }
    }
    for(int i=1;i<=N;i++){
        if(visited[i]==0){
            tim++;
            visited[i]=1;
            tarjan(i);
        }
    }
    if(flagc==1){
        cout<<1<<endl;
        cout<<0<<endl;
    }
    else{
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
        cout<<inc<<endl;
        cout<<max(inc,outc)<<endl;
    }
    return 0;
}
