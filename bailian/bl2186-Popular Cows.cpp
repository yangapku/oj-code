#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#define MAXN 10100
using namespace std;

struct Node{
    int bet;
    int low;
};
Node info[MAXN];
char visited[MAXN];
int flag[MAXN];
vector<vector<int> > g;
char inst[MAXN];
int ttime;
int flagc;
stack<int> st;
int N,M;

void tarjan(int pos){
    info[pos].bet=ttime;
    info[pos].low=ttime;
    st.push(pos);
    inst[pos]=1;
    for(int i=0;i<g[pos].size();i++){
        int d=g[pos][i];
        if(visited[d]==0){
            ttime++;
            visited[d]=1;
            tarjan(d);
            info[pos].low=min(info[pos].low,info[d].low);
        }
        else if(inst[d]==1){
            info[pos].low=min(info[pos].low,info[d].bet);
        }
    }
    if(info[pos].low==info[pos].bet){
        while(1){
            int cid=st.top();
            st.pop();
            flag[cid]=flagc;
            inst[cid]=0;
            if(cid==pos) break;
        }
        flagc++;
    }
}

int main(){
    while(cin>>N>>M){
        st=stack<int>();
        g.clear();
        g.resize(N+1);
        for(int i=1;i<=N;i++){
            flag[i]=-1;
            visited[i]=0;
            inst[i]=0;
        }
        for(int i=0;i<M;i++){
            int s,d;
            cin>>s>>d;
            g[s].push_back(d);
        }
        ttime=-1;
        flagc=0;
        for(int i=1;i<=N;i++){
            if(visited[i]==0){
                ttime++;
                visited[i]=1;
                tarjan(i);
            }
        }
        int count=0,result=0;
        for(int i=0;i<flagc;i++){
            bool noc=true;
            int temp=0;
            for(int j=1;j<=N;j++){
                if(flag[j]==i){
                    temp++;
                    for(int t=0;t<g[j].size();t++){
                        int r=g[j][t];
                        if(flag[r]!=flag[j]){
                            noc=false;
                            break;
                        }
                    }
                }
            }
            if(noc) {count++;result=temp;}
        }
        if(count==1){
            cout<<result<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}