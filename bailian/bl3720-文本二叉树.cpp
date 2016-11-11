#include<iostream>
#include<vector>
#define MAXH 150
using namespace std;

struct Node{
    char info;
    Node* lc;
    Node* rc;
    Node(char ch){this->info=ch;this->lc=NULL;this->rc=NULL;}
};
Node* ptrs[MAXH];

int calh(string str){
    int i;
    for(i=0;i<str.length();i++){
        if(str[i]!='-') break;
    }
    return i;
}

void addNode(char ch,int h){
    if(h==0){
        ptrs[0]=new Node(ch);
        return;
    }
    Node* cptr=ptrs[h-1];
    Node* nptr=new Node(ch);
    ptrs[h]=nptr;
    if(cptr->lc==NULL){
        cptr->lc=nptr;
    }
    else{
        cptr->rc=nptr;
    }
}

void previsit(Node* root){
    if(root->info!='*') cout<<root->info;
    if(root->lc!=NULL){
        previsit(root->lc);
    }
    if(root->rc!=NULL){
        previsit(root->rc);
    }
}

void midvisit(Node* root){
    if(root->lc!=NULL){
        midvisit(root->lc);
    }
    if(root->info!='*') cout<<root->info;
    if(root->rc!=NULL){
        midvisit(root->rc);
    }
}

void postvisit(Node* root){
    if(root->lc!=NULL){
        postvisit(root->lc);
    }
    if(root->rc!=NULL){
        postvisit(root->rc);
    }
    if(root->info!='*') cout<<root->info;
}

int main(){
    int N;
    cin>>N;
    for(int ccc=0;ccc<N;ccc++){
        Node* tree=NULL;
        while(1){
            string s;
            getline(cin,s);
            if(s[0]=='0') break;
            int h=calh(s);
            int ch=s[h];
            addNode(ch,h);
        }
        previsit(ptrs[0]);
        cout<<endl;
        postvisit(ptrs[0]);
        cout<<endl;
        midvisit(ptrs[0]);
        cout<<endl;
        cout<<endl;
    }
}
