#include<iostream>
#include<vector>
#define MAXN 25
using namespace std;

int record[MAXN][45];
int data[MAXN];
int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        int a;
        cin>>a;
        data[i]=a;
    }
    for(int i=0;i<=40;i++){
        record[1][i]=0;
    }
    record[1][0]=1;
    if(data[1]<=40) record[1][data[1]]=1;
    for(int i=2;i<=N;i++){
        for(int j=0;j<=40;j++){
            int a1=0,a2=0;
            a1=record[i-1][j];
            if(j>=data[i])  a2=record[i-1][j-data[i]];
            record[i][j]=a1+a2;
        }
    }
    cout<<record[N][40]<<endl;
    return 0;
}
