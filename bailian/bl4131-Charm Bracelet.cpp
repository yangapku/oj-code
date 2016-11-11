#include<iostream>
#include<vector>
#define MAXM 13000
#define MAXN 3500
using namespace std;

int weight[MAXN];
int charm[MAXN];
int r1[MAXM];
int r2[MAXM];
int main(){
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        int w,d;
        cin>>w>>d;
        weight[i]=w;
        charm[i]=d;
    }
    for(int i=0;i<=M;i++){
        r2[i]=0;
    }
    if(weight[1]<=M) r2[weight[1]]=charm[1];
    for(int i=0;i<=M;i++){
        r1[i]=r2[i];
    }
    for(int i=2;i<=N;i++){
        for(int j=0;j<=M;j++){
            int a1=0,a2=0;
            a1=r1[j];
            if(j>=weight[i]) a2=r1[j-weight[i]]+charm[i];
            r2[j]=max(a1,a2);
        }
        for(int t=0;t<=M;t++){
            r1[t]=r2[t];
        }
    }
    int res=-1;
    for(int i=0;i<=M;i++){
        if(r1[i]>=res) res=r1[i];
    }
    cout<<res<<endl;
    return 0;
}

