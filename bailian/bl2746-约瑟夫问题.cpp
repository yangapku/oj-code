#include<iostream>
#include<cstring>
#include<vector>
#define MAXN 400
using namespace std;

struct Node{
    int info;
    Node* next;
    Node(int info){
        this->info=info;
        this->next=NULL;
    }
};

int main(){
    int N,M;
    while(1){
        cin>>N>>M;
        if(N==0) return 0;
        Node* head=NULL;
        head=new Node(1);
        Node* ptr=head;
        for(int i=2;i<=N;i++){
            ptr->next=new Node(i);
            ptr=ptr->next;
        }
        ptr->next=head;
        Node *p1=head,*p2=ptr;
        int id=1;
        while(1){
            if(id==M){
                id=1;
                p1=p1->next;
                p2->next=p1;
            }
            else{
                p2=p1;
                p1=p1->next;
                id++;
            }
            if(p1->next==p1){
                cout<<p1->info<<endl;
                break;
            }
        }
    }
}
