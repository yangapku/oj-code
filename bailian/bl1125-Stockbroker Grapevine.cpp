#include<iostream>
#include<vector>
#include<algorithm>
#define MAXN 110
#define MAXL 99999999
using namespace std;

int dist[MAXN][MAXN][MAXN];
int result[MAXN];
int main(){
    int N;
    while(1){
        cin>>N;
        if(N==0) break;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                for(int k=0;k<=N;k++){
                    dist[i][j][k]=MAXL;
                }
            }
        }
        for(int i=1;i<=N;i++){
            dist[i][i][0]=0;
            int count;
            cin>>count;
            for(int j=0;j<count;j++){
                int d,w;
                cin>>d>>w;
                if(w<dist[i][d][0]) dist[i][d][0]=w;
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                for(int k=1;k<=N;k++){
                    dist[j][k][i]=min(dist[j][k][i-1],(dist[j][i][i-1]+dist[i][k][i-1]));
                }
            }
        }
        for(int i=1;i<=N;i++){
            result[i]=-1;
            bool flag=true;
            int r=-1;
            for(int j=1;j<=N;j++){
                if(j==i) continue;
                int temp=dist[i][j][N];
                if(temp==MAXL) {flag=false;break;}
                if(temp>r) r=temp;
            }
            if(flag) result[i]=r;
        }
        int res=0,time=MAXL;
        for(int i=1;i<=N;i++){
            if(result[i]!=-1 && result[i]<time){res=i;time=result[i];}
        }
        cout<<res<<' '<<time<<endl;
    }
    return 0;
}
