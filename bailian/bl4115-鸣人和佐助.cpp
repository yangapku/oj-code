#include<iostream>
#include<queue>
#include<vector>
#define MAXD 210
using namespace std;

string maze[MAXD];
int visited[MAXD][MAXD];
int result=-1;
int M,N,C;
struct State{
    int x;
    int y;
    int c;
    int t;
};
int main(){
    cin>>M>>N>>C;
    int sx=-1,sy=-1,ex=-1,ey=-1;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            visited[i][j]=-1;
        }
    }
    for(int i=0;i<M;i++){
        string l;
        cin>>l;
        maze[i]=l;
        for(int j=0;j<N;j++){
            if(sx==-1 && maze[i][j]=='@'){sx=i;sy=j;}
            if(ex==-1 && maze[i][j]=='+'){ex=i;ey=j;}
        }
    }
    queue<State> q=queue<State>();
    State s=State();
    s.x=sx;
    s.y=sy;
    s.c=C;
    s.t=0;
    q.push(s);
    visited[sx][sy]=C;
    while(!q.empty()){
        State cs=q.front();
        q.pop();
        int cx=cs.x;
        int cy=cs.y;
        int cc=cs.c;
        int ct=cs.t;
        if(cx==ex && cy==ey){
            result=ct;break;
        }
        if(cx>0 && visited[cx-1][cy]<=(cc-1)){
            if(maze[cx-1][cy]=='#'){
                if(cc>0){
                    State ns=State();
                    ns.x=cx-1;ns.y=cy;ns.c=cc-1;ns.t=ct+1;
                    visited[cx-1][cy]=cc-1;
                    q.push(ns);
                }
            }
            else{
                State ns=State();
                ns.x=cx-1;ns.y=cy;ns.c=cc;ns.t=ct+1;
                visited[cx-1][cy]=cc;
                q.push(ns);
            }
        }
        if(cx<(M-1) && visited[cx+1][cy]<=(cc-1)){
            if(maze[cx+1][cy]=='#'){
                if(cc>0){
                    State ns=State();
                    ns.x=cx+1;ns.y=cy;ns.c=cc-1;ns.t=ct+1;
                    visited[cx+1][cy]=cc-1;
                    q.push(ns);
                }
            }
            else{
                State ns=State();
                ns.x=cx+1;ns.y=cy;ns.c=cc;ns.t=ct+1;
                visited[cx+1][cy]=cc;
                q.push(ns);
            }
        }
        if(cy>0 && visited[cx][cy-1]<=(cc-1)){
            if(maze[cx][cy-1]=='#'){
                if(cc>0){
                    State ns=State();
                    ns.x=cx;ns.y=cy-1;ns.c=cc-1;ns.t=ct+1;
                    visited[cx][cy-1]=cc-1;
                    q.push(ns);
                }
            }
            else{
                State ns=State();
                ns.x=cx;ns.y=cy-1;ns.c=cc;ns.t=ct+1;
                visited[cx][cy-1]=cc;
                q.push(ns);
            }
        }
        if(cy<(N-1) && visited[cx][cy+1]<=(cc-1)){
            if(maze[cx][cy+1]=='#'){
                if(cc>0){
                    State ns=State();
                    ns.x=cx;ns.y=cy+1;ns.c=cc-1;ns.t=ct+1;
                    visited[cx][cy+1]=cc-1;
                    q.push(ns);
                }
            }
            else{
                State ns=State();
                ns.x=cx;ns.y=cy+1;ns.c=cc;ns.t=ct+1;
                visited[cx][cy+1]=cc;
                q.push(ns);
            }
        }
    }
    cout<<result<<endl;
    return 0;
}