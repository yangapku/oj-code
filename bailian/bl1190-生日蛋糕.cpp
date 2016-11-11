#include<iostream>
#include<cmath>
#define MAX 9999999
using namespace std;

int n,m;
int area=0;
int res=MAX;
int minV[25];
int minA[25];

int mv(int level,int r,int h){
    int v=0;
    for(int i=0;i<level;i++){
        v+=(r-i)*(r-i)*(h-i);
    }
    return v;
}

void DFS(int v,int level,int maxR,int maxH){
    if(level==0){
        if(v==0&&area<res){
            res=area;
        }
        return;
    }
    if(v<minV[level]) return;
    if(minA[level]+area>=res) return;
    if(mv(level,maxR,maxH)<v) return;
    if(maxR<level||maxH<level) return;
    for(int r=maxR;r>=level;r--){
        if(level==m){
            area=r*r;
        }
        for(int h=maxH;h>=level;h--){
            area+=2*h*r;
            if(r*r*h<=v)
                DFS(v-r*r*h,level-1,r-1,h-1);
            area-=2*h*r;
        }
    }
}

int main(){
    minV[0]=0;
    minA[0]=0;
    cin>>n>>m;
    for(int i=1;i<25;i++){
        minV[i]=minV[i-1]+i*i*i;
        minA[i]=minA[i-1]+2*i*i;
    }
    int maxH=(n-minV[m-1])/(m*m)+1;
    int maxR=sqrt(double(n-minV[m-1])/(1.0*m))+1;
    DFS(n,m,maxR,maxH);
    if(res==MAX){
        cout<<0<<endl;
    }
    else{
        cout<<res<<endl;
    }
    return 0;
}
