#include<iostream>
#include<vector>
#include<queue>
#define MAXD 210
using namespace std;

string maze[MAXD];
int visited[MAXD][MAXD];
int usetime[MAXD][MAXD];
int N,M;
int main(){
    int C;
    cin>>C;
    for(int i=0;i<C;i++){
        int sx=-1,sy=-1;
        int result=-1;
        cin>>N>>M;
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                visited[j][k]=0;
                usetime[j][k]=0;
            }
        }
        for(int j=0;j<N;j++){
            string l;
            cin>>l;
            maze[j]=l;
            for(int k=0;k<M;k++){
                if(sx==-1 && maze[j][k]=='r'){
                    sx=j;sy=k;
                }
            }
        }
        queue<int> q=queue<int>();
        q.push(sx*M+sy);
        visited[sx][sy]=1;
        while(!q.empty()){
            int cpos=q.front();
            q.pop();
            int cx=cpos/M;
            int cy=cpos%M;
            int ct=usetime[cx][cy];
            if(maze[cx][cy]=='a'){
                result=usetime[cx][cy];break;
            }
            if(maze[cx][cy]=='x' && visited[cx][cy]==1){
                visited[cx][cy]=2;
                usetime[cx][cy]=ct+1;
                q.push(cpos);
            }
            else{
                if(cx>0 && maze[cx-1][cy]!='#' && visited[cx-1][cy]==0){
                    visited[cx-1][cy]=1;
                    usetime[cx-1][cy]=ct+1;
                    int newpos=(cx-1)*M+cy;
                    q.push(newpos);
                }
                if(cx<(N-1) && maze[cx+1][cy]!='#' && visited[cx+1][cy]==0){
                    visited[cx+1][cy]=1;
                    usetime[cx+1][cy]=ct+1;
                    int newpos=(cx+1)*M+cy;
                    q.push(newpos);
                }
                if(cy>0 && maze[cx][cy-1]!='#' && visited[cx][cy-1]==0){
                    visited[cx][cy-1]=1;
                    usetime[cx][cy-1]=ct+1;
                    int newpos=cx*M+(cy-1);
                    q.push(newpos);
                }
                if(cy<(M-1) && maze[cx][cy+1]!='#' && visited[cx][cy+1]==0){
                    visited[cx][cy+1]=1;
                    usetime[cx][cy+1]=ct+1;
                    int newpos=cx*M+(cy+1);
                    q.push(newpos);
                }
            }
        }
        if(result==-1){
            cout<<"Impossible"<<endl;
        }
        else{
            cout<<result<<endl;
        }
    }
    return 0;
}