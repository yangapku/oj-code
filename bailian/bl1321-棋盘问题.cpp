#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define MAXN 100
using namespace std;

char visited[MAXN];
vector<int> pos;
int N,K;
int ccc=0;

bool isOK(int p,int epos){
    for(int i=0;i<epos;i++){
        if(visited[i]==1){
            int x1=pos[i]/N;
            int y1=pos[i]%N;
            int x2=p/N;
            int y2=p%N;
            if(x1==x2 || y1==y2) return false;
        }
    }
    return true;
}

void DFS(int cp,int step,int index){
    visited[index]=1;
    int nstep=step+1;
    if(nstep==K){
        ccc++;
        visited[index]=0;
        return;
    }
    for(int i=index+1;i<pos.size();i++){
        if(visited[i]==0){
            if(isOK(pos[i],i)){
                DFS(pos[i],nstep,i);
            }
        }
    }
    visited[index]=0;
}

int main(){
    while(1){
        cin>>N>>K;
        if(N==-1) break;
        memset(visited,0,sizeof(visited));
        pos.clear();
        string line;
        ccc=0;
        for(int i=0;i<N;i++){
            cin>>line;
            for(int j=0;j<N;j++){
                if(line[j]=='#') pos.push_back(i*N+j);
            }
        }
        for(int i=0;i<pos.size();i++){
            DFS(pos[i],0,i);
        }
        cout<<ccc<<endl;
    }
    return 0;
}
