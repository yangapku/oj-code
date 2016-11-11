#include<iostream>
#include<vector>
#include<algorithm>
#define MAXN 1010
using namespace std;

int record[MAXN];
int data[MAXN];
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int t;
        cin>>t;
        data[i]=t;
    }
    for(int i=0;i<N;i++){
        int prevmax=0;
        for(int j=0;j<i;j++){
            if(data[j]<data[i] && prevmax<record[j]){
                prevmax=record[j];
            }
        }
        record[i]=prevmax+1;
    }
    int result=0;
    for(int i=0;i<N;i++){
        if(result<record[i]) result=record[i];
    }
    cout<<result;
}