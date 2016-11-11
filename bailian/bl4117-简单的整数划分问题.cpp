#include<iostream>
using namespace std;

int a,result=0;
void DFS(int last,int remain){
    if(remain==0){
        result++;
        return;
    }
    for(int i=last;i>0;i--){
        if(remain-i>=0)
            DFS(i,remain-i);
    }
}
int main(){
    while(cin>>a){
        result=0;
        for(int i=a;i>0;i--){
            DFS(i,a-i);
        }
        cout<<result<<endl;
    }
}
