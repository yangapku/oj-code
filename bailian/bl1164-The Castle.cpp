#include<iostream>
#define MAXDIM 55
using namespace std;
int maxroom=0;
int roomcount=0;
int temproom=0;
bool isvisited[MAXDIM][MAXDIM]={};
int walls[MAXDIM][MAXDIM]={};
int main()
{
    void dfs(int r,int s);
    int m,n;
    cin>>m;
    cin>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>walls[i][j];
            isvisited[i][j]=false;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(isvisited[i][j]==false){
                roomcount++;
                temproom=0;
                dfs(i,j);
                if(temproom>=maxroom){
                    maxroom=temproom;
                }
            }
        }
    }
    cout<<roomcount<<endl;
    cout<<maxroom<<endl;
    return 0;
}

void dfs(int r,int s){
    //cout<<r+1<<' '<<s+1<<endl;
    isvisited[r][s]=true;
    temproom++;
    if((walls[r][s]/8==0) && isvisited[r+1][s]==false){
        dfs(r+1,s);
    }
    if(((walls[r][s]%8)/4==0) && isvisited[r][s+1]==false){
        dfs(r,s+1);
    }
    if((((walls[r][s]%8)%4)/2==0) && isvisited[r-1][s]==false){
        dfs(r-1,s);
    }
    if((((walls[r][s]%8)%4)%2==0) && isvisited[r][s-1]==false){
        dfs(r,s-1);
    }
}
