#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#define MAXN 40
#define MAXL 999999999
using namespace std;

struct Node{
    int d;
    double w;
    Node(int d,double w){
        this->d=d;
        this->w=w;
    }
};
vector<Node> g[MAXN];
queue<int> q;
char inq[MAXN];
int leng[MAXN];
double dist[MAXN][MAXN];
map<string,int> proj;
int N,M;

int main(){
    int cnt=0;
    while(1){
        cnt++;
        cin>>N;
        if(N==0) break;
        proj=map<string,int>();
        for(int i=0;i<N;i++){
            string nm;
            cin>>nm;
            proj.insert(make_pair(nm,i));
        }
        for(int i=0;i<N;i++){
            g[i].clear();
            for(int j=0;j<N;j++){
                dist[i][j]=MAXL;
            }
        }
        cin>>M;
        for(int i=0;i<M;i++){
            string strs,strd;
            double rate;
            cin>>strs>>rate>>strd;
            int s=proj.find(strs)->second;
            int d=proj.find(strd)->second;
            g[s].push_back(Node(d,1.0/rate));
        }
        bool result=false;
        for(int i=0;i<N;i++){
            memset(inq,0,sizeof(inq));
            q=queue<int>();
            for(int j=0;j<N;j++){
                leng[j]=-1;
            }
            q.push(i);
            leng[i]=0;
            dist[i][i]=1.0;
            inq[i]=1;
            while(!q.empty()){
                int cs=q.front();
                q.pop();
                inq[cs]=0;
                for(int j=0;j<g[cs].size();j++){
                    int cd=g[cs][j].d;
                    double nw=g[cs][j].w*dist[i][cs];
                    if(nw<dist[i][cd]){
                        dist[i][cd]=nw;
                        leng[cd]++;
                        if(inq[cd]==0){
                            inq[cd]=1;
                            q.push(cd);
                        }
                    }
                }
                bool havelp=false;
                for(int j=0;j<N;j++){
                    if(leng[j]>=N){
                        havelp=true;
                        break;
                    }
                }
                if(havelp){
                    result=true;
                    break;
                }
            }
        }
        if(result){
            cout<<"Case "<<cnt<<": Yes"<<endl;
        }
        else{
            cout<<"Case "<<cnt<<": No"<<endl;
        }
        string tt;
        getline(cin,tt);
    }
    return 0;
}
