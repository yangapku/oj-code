#include<iostream>
#include<queue>
#include<vector>
#define MAXN 150000
using namespace std;

int pq[MAXN];
int length=0;

void push(int n){
    pq[length]=n;
    length++;
    int dad=(length-2)/2,cpos=length-1;
    while(dad>=0){
        if(pq[cpos]<pq[dad]){
            int temp=pq[cpos];
            pq[cpos]=pq[dad];
            pq[dad]=temp;
            cpos=dad;
            dad=(cpos-1)/2;
        }
        else break;
    }
}

int top(){
    return pq[0];
}

void pop(){
    length--;
    pq[0]=pq[length];
    if(length==0) return;
    int cpos=0;
    while(1){
        int lcid=2*cpos+1;
        int rcid=2*cpos+2;
        if(lcid>=length) break;
        else if(rcid>=length){
            if(pq[cpos]>pq[lcid]){
                int temp=pq[cpos];
                pq[cpos]=pq[lcid];
                pq[lcid]=temp;
                cpos=lcid;
            }
            else break;
        }
        else{
            int cid=pq[lcid]<pq[rcid]?lcid:rcid;
            if(pq[cpos]>pq[cid]){
                int temp=pq[cpos];
                pq[cpos]=pq[cid];
                pq[cid]=temp;
                cpos=cid;
            }
            else break;
        }
    }


}

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int r;
        cin>>r;
        if(r==1){
            int n;
            cin>>n;
            push(n);
        }
        else{
            int e;
            e=top();
            pop();
            cout<<e<<endl;
        }
    }
}
