#include<iostream>
#include<vector>
#include<algorithm>
#define MAXN 7000
using namespace std;

int data[MAXN];
int record[MAXN];
int N,c=0;

void solve(){
    for(int i=0;i<N;i++){
        int prevmax=0;
        for(int j=0;j<i;j++){
            if(data[j]>=data[i] && prevmax<record[j]) prevmax=record[j];
        }
        record[i]=prevmax+1;
    }
    int result=0;
    for(int i=0;i<N;i++){
        if(result<record[i]) result=record[i];
    }
    cout<<"Test #"<<c<<":"<<endl;
    cout<<"  maximum possible interceptions: "<<result<<endl<<endl;
}

int main(){
    int t;
    while(cin>>t){
        if(t==-1){
            if(N==0) return 0;
            c++;
            solve();
            N=0;
        }
        else{
            data[N++]=t;
        }
    }
}
