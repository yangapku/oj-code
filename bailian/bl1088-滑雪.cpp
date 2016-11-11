#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAXN 110
using namespace std;

int g[MAXN][MAXN];
int record[MAXN][MAXN];

int main(){
    int R,C;
    cin>>R>>C;
    int maxid=-1,maxh=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            int h;
            cin>>h;
            g[i][j]=h;
            record[i][j]=-1;
            if(h>maxh){
                maxh=h;
                maxid=i*C+j;
            }
        }
    }
    record[maxid/C][maxid%C]=1;
    int solvenum=1;
    int result=1;
    while(solvenum<R*C){
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(record[i][j]==-1){
                    int maxr=0;
                    if(i>0 && g[i-1][j]>g[i][j]){
                        if(record[i-1][j]!=-1) maxr=max(maxr,record[i-1][j]);
                        else continue;
                    }
                    if(i<(R-1) && g[i+1][j]>g[i][j]){
                        if(record[i+1][j]!=-1) maxr=max(maxr,record[i+1][j]);
                        else continue;
                    }
                    if(j>0 && g[i][j-1]>g[i][j]){
                        if(record[i][j-1]!=-1) maxr=max(maxr,record[i][j-1]);
                        else continue;
                    }
                    if(j<(C-1) && g[i][j+1]>g[i][j]){
                        if(record[i][j+1]!=-1) maxr=max(maxr,record[i][j+1]);
                        else continue;
                    }
                    record[i][j]=maxr+1;
                    solvenum++;
                    if(record[i][j]>result) result=record[i][j];
                }
            }
        }
    }
    cout<<result<<endl;
}
