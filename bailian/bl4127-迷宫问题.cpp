#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int maze[5][5];
int visited[5][5];
vector<int> v=vector<int>();

int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int t;
            cin>>t;
            maze[i][j]=t;
            visited[i][j]=-1;
        }
    }
    queue<int> q=queue<int>();
    visited[0][0]=0;
    q.push(0);
    while(!q.empty()){
        int pos=q.front();
        q.pop();
        int x=pos/5;
        int y=pos%5;
        if(x==4 && y==4) break;
        if(x>0 && maze[x-1][y]==0 && visited[x-1][y]==-1){
            q.push((x-1)*5+y);
            visited[x-1][y]=pos;
        }
        if(x<4 && maze[x+1][y]==0 && visited[x+1][y]==-1){
            q.push((x+1)*5+y);
            visited[x+1][y]=pos;
        }
        if(y>0 && maze[x][y-1]==0 && visited[x][y-1]==-1){
            q.push(x*5+(y-1));
            visited[x][y-1]=pos;
        }
        if(y<4 && maze[x][y+1]==0 && visited[x][y+1]==-1){
            q.push(x*5+(y+1));
            visited[x][y+1]=pos;
        }
    }
    int x=4,y=4;
    while(!(x==0 && y==0)){
        v.push_back(x*5+y);
        int ppos=visited[x][y];
        x=ppos/5;
        y=ppos%5;
    }
    cout<<"(0, 0)"<<endl;
    for(int j=v.size()-1;j>=0;j--){
        cout<<"("<<v[j]/5<<", "<<v[j]%5<<")"<<endl;
    }
    return 0;
}