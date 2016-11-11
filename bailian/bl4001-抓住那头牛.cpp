#include<iostream>
#include<queue>
#include<vector>
#define MAXP 100005
using namespace std;

int visited[MAXP];
queue<int> s=queue<int>();
int main(){
    int N,K;
    cin>>N>>K;
    for(int i=0;i<MAXP;i++){
        visited[i]=-1;
    }
    s.push(N);
    visited[N]=0;
    while(!s.empty()){
        int pos=s.front();
        s.pop();
        int count=visited[pos];
        if(pos==K){
            cout<<count<<endl;
            break;
        }
        if(pos>0 && visited[pos-1]==-1){
            visited[pos-1]=count+1;
            s.push(pos-1);
        }
        if(pos<100000 && visited[pos+1]==-1){
            visited[pos+1]=count+1;
            s.push(pos+1);
        }
        if(pos*2<=100000 && visited[pos*2]==-1){
            visited[pos*2]=count+1;
            s.push(pos*2);
        }
    }
    return 0;
}