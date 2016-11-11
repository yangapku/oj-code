#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAXN 1000
#define MAXL 9999999
using namespace std;

struct Node{
    int dad;
    int lc;
    int rc;
    int info;
    Node(int info){
        this->info=info;
        this->dad=-1;
        this->lc=-1;
        this->rc=-1;
    }
};
vector<Node> data;

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int t;
        cin>>t;
        data.push_back(Node(t));
    }
    for(int i=0;i<(N-1);i++){
        int id1=-1,id2=-1,info1=MAXL,info2=MAXL;
        for(int j=0;j<data.size();j++){
            if(data[j].dad==-1){
                if(data[j].info<info1){
                    id2=id1;
                    id1=j;
                    info2=info1;
                    info1=data[j].info;
                }
                else if(data[j].info<info2){
                    id2=j;
                    info2=data[j].info;
                }
            }
        }
        data.push_back(Node(data[id1].info+data[id2].info));
        int l=data.size()-1;
        data[id1].dad=l;
        data[id2].dad=l;
        data[l].lc=id1;
        data[l].rc=id2;
    }
    int result=0;
    for(int i=0;i<N;i++){
        int w=data[i].info;
        int route=0;
        int prev=data[i].dad;
        while(prev!=-1){
            route++;
            prev=data[prev].dad;
        }
        result+=w*route;
    }
    cout<<result<<endl;
}
