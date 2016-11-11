#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#define MAXN 99999
using namespace std;

struct Node{
    char info;
    Node* lc;
    Node* rc;
    Node(char info){this->info=info;this->lc=NULL;this->rc=NULL;}
};
Node* data[MAXN];
int state[MAXN];
struct NodeLevel{
    int level;
    Node* nde;
    NodeLevel(int l,Node* n){this->level=l;this->nde=n;}
};
stack<char> st;
queue<NodeLevel> qe;

int main(){
    int N;
    int cp=0;
    cin>>N;
    for(int i=0;i<N;i++){
        string nd;
        cin>>nd;
        int cs=nd[1]-'0';
        data[cp]=new Node(nd[0]);
        state[cp]=cs;
        while(cp>=2){
            if(state[cp]==1 && state[cp-1]==1 && state[cp-2]==0){
                data[cp-2]->lc=data[cp-1];
                data[cp-2]->rc=data[cp];
                cp=cp-2;
                state[cp]=1;
            }
            else break;
        }
        cp++;
    }
    Node* tree=data[0];
    int tl=-1;
    qe.push(NodeLevel(0,tree));
    while(!qe.empty()){
        NodeLevel cnl=qe.front();
        qe.pop();
        int cl=cnl.level;
        Node* cn=cnl.nde;
        if(tl!=cl){
            while(!st.empty()){
                cout<<st.top()<<' ';
                st.pop();
            }
            tl=cl;
        }
        st.push(cn->info);
        Node* ptr=cn->lc;
        while(ptr!=NULL && ptr->info!='$'){
            qe.push(NodeLevel(cl+1,ptr));
            ptr=ptr->rc;
        }
    }
    while(!st.empty()){
        cout<<st.top()<<' ';
        st.pop();
    }
    return 0;
}
