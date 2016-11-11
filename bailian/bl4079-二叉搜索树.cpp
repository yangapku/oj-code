#include<iostream>
using namespace std;

struct Node{
    int info;
    Node* lc;
    Node* rc;
    Node(int info){this->info=info;this->lc=NULL;this->rc=NULL;}
};

void DFS(Node* ptr){
    cout<<ptr->info<<' ';
    if(ptr->lc!=NULL) DFS(ptr->lc);
    if(ptr->rc!=NULL) DFS(ptr->rc);
}

int main(){
    int num;
    Node* root=NULL;
    while(cin>>num){
        Node* ptr=new Node(num);
        if(root==NULL){
            root=ptr;
            continue;
        }
        Node* p1=root;
        while(1){
            if(p1->info==num) break;
            if(num<p1->info){
                if(p1->lc==NULL){
                    p1->lc=ptr;break;
                }
                else{
                    p1=p1->lc;
                }
            }
            else{
                if(p1->rc==NULL){
                    p1->rc=ptr;break;
                }
                else{
                    p1=p1->rc;
                }
            }
        }
    }
    DFS(root);
}
