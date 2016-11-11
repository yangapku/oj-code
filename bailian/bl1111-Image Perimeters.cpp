#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define MAXN 30
using namespace std;

char g[MAXN][MAXN];
bool visited[MAXN][MAXN];
int m,n,x,y;

int cal(int x,int y){
    int peri=0;
    if(x==0) peri++;
    else if(g[x-1][y]!='X') peri++;
    if(y==0) peri++;
    else if(g[x][y-1]!='X') peri++;
    if(x==(m-1)) peri++;
    else if(g[x+1][y]!='X') peri++;
    if(y==(n-1)) peri++;
    else if(g[x][y+1]!='X') peri++;
    return peri;
}

int main(){
    while(1){
        cin>>m>>n>>x>>y;
        if(m==0 && n==0) break;
        for(int i=0;i<MAXN;i++){
            for(int j=0;j<MAXN;j++){
                visited[i][j]=0;
            }
        }
        for(int i=0;i<m;i++){
            string line;
            cin>>line;
            for(int j=0;j<n;j++){
                g[i][j]=line[j];
            }
        }
        int sx=x-1;
        int sy=y-1;
        queue<int> q;
        q.push(sx*n+sy);
        visited[sx][sy]=1;
        int result=0;
        while(!q.empty()){
            int cpos=q.front();
            q.pop();
            int cx=cpos/n;
            int cy=cpos%n;
            result+=cal(cx,cy);
            if(cx>0){
                if(cy>0 && g[cx-1][cy-1]=='X' && visited[cx-1][cy-1]==0){
                    visited[cx-1][cy-1]=1;
                    q.push((cx-1)*n+(cy-1));
                }
                if(g[cx-1][cy]=='X' && visited[cx-1][cy]==0){
                    visited[cx-1][cy]=1;
                    q.push((cx-1)*n+cy);
                }
                if(cy<(n-1) && g[cx-1][cy+1]=='X' && visited[cx-1][cy+1]==0){
                    visited[cx-1][cy+1]=1;
                    q.push((cx-1)*n+(cy+1));
                }
            }
            if(cx<(m-1)){
                if(cy>0 && g[cx+1][cy-1]=='X' && visited[cx+1][cy-1]==0){
                    visited[cx+1][cy-1]=1;
                    q.push((cx+1)*n+(cy-1));
                }
                if(g[cx+1][cy]=='X' && visited[cx+1][cy]==0){
                    visited[cx+1][cy]=1;
                    q.push((cx+1)*n+cy);
                }
                if(cy<(n-1) && g[cx+1][cy+1]=='X' && visited[cx+1][cy+1]==0){
                    visited[cx+1][cy+1]=1;
                    q.push((cx+1)*n+(cy+1));
                }
            }
            if(cy>0 && g[cx][cy-1]=='X' && visited[cx][cy-1]==0){
                visited[cx][cy-1]=1;
                q.push(cx*n+(cy-1));
            }
            if(cy<(n-1) && g[cx][cy+1]=='X' && visited[cx][cy+1]==0){
                visited[cx][cy+1]=1;
                q.push(cx*n+(cy+1));
            }
        }
        cout<<result<<endl;
    }
    return 0;
}
