#include<iostream>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
#include<functional>
#include<stdio.h>
#define MAXN 5010
using namespace std;

int R,C,N;
int T;
char g[MAXN][MAXN];
vector<int> data;
int result=0;
int mincnt=3;

bool isprevin(int spos,int cpos){
    int sx=spos/C;
    int sy=spos%C;
    int cx=cpos/C;
    int cy=cpos%C;
    int prevx=2*sx-cx;
    int prevy=2*sy-cy;
    return(prevx>=0 && prevx<R && prevy>=0 && prevy<C);
}

void DFS1(int spos,int sid){
    int id;
    for(id=sid+1;id<data.size();id++){
        int cpos=data[id];
        int delta=cpos-spos;
        if(isprevin(spos,cpos)==0){
            int dx=cpos/C-spos/C;
            int dy=cpos%C-spos%C;
            int cx=cpos/C;
            int cy=cpos%C;
            if(cx+(mincnt-2)*dx>=R || cx+(mincnt-2)*dx<0 || cy+(mincnt-2)*dy>=C || cy+(mincnt-2)*dy<0) continue;
            int ccnt=2;
            int newpos=cpos+delta;
            bool complete=true;
            while(1){
                int nx=newpos/C;
                int ny=newpos%C;
                if(g[nx][ny]==0) {complete=false;break;}
                ccnt++;
                newpos=newpos+delta;
                if(nx+dx<0 || nx+dx>=R || ny+dy<0 || ny+dy>=C) break;
            }
            if(complete && ccnt>=mincnt){
                mincnt=ccnt;
                result=ccnt;
            }
        }
    }
}

int main(){
    scanf("%d%d",&R,&C);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            g[i][j]=0;
        }
    }
    T=R*C;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int r,c;
        scanf("%d%d",&r,&c);
        data.push_back((r-1)*C+(c-1));
        g[r-1][c-1]=1;
    }
    sort(data.begin(),data.end(),less<int>());
    for(int i=0;i<data.size();i++){
        DFS1(data[i],i);
    }
    cout<<result<<endl;
    return 0;
}
