#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define MAXL 380000
using namespace std;

int visited[MAXL];
queue<int> q=queue<int>();
struct Prev{
    int ps;
    char pp;
    Prev(int ps,char pp){this->ps=ps;this->pp=pp;}
    Prev(){this->ps=-1;this->pp='x';}
};
Prev prevs[MAXL];
bool flag=false;
char table[11]="012345678x";

int fact(int n){
    if(n==0) return 1;
    int result=1;
    for(int i=1;i<=n;i++){
        result*=i;
    }
    return result;
}

int toint(char c){
    if(c=='x') return 9;
    return c-'0';
}

int calstate(string s){
    int t[9],index=0;
    for(int i=0;i<9;i++){
        t[i]=toint(s[i]);
        int a=t[i]-1;
        for(int j=0;j<i;j++){
            if(t[j]<t[i]) a--;
        }
        index+=a*fact(8-i);
    }
    return index;
}

string calstring(int id){
    char str[11];
    int v[9];
    int remain=id;
    for(int i=0;i<9;i++){
        v[i]=false;
    }
    for(int i=0;i<9;i++){
        int c=remain/fact(8-i);
        int temp=-1;
        char rr;
        for(int j=0;j<9;j++){
            if(v[j]==false) temp++;
            if(temp==c){
                rr=table[j+1];
                v[j]=true;
                break;
            }
        }
        str[i]=rr;
        remain=remain%fact(8-i);
    }
    string res=str;
    return res;
}

int main(){
    for(int i=0;i<MAXL;i++){
        visited[i]=0;
    }
    string init="";
    for(int i=0;i<9;i++){
        char t;
        cin>>t;
        init+=t;
    }
    int sid=calstate(init);
    q.push(sid);
    visited[sid]=1;
    while(!q.empty()){
        int id=q.front();
        q.pop();
        if(id==0) {flag=true;break;}
        string sstr=calstring(id);
        int xpos=-1;
        for(int i=0;i<9;i++){
            if(sstr[i]=='x') {xpos=i;break;}
        }
        if(xpos/3>0){
            string nstr=sstr;
            nstr[xpos]=nstr[xpos-3];
            nstr[xpos-3]='x';
            int nid=calstate(nstr);
            if(visited[nid]==0){
                visited[nid]=1;
                prevs[nid]=Prev(id,'u');
                q.push(nid);
            }
        }
        if(xpos/3<2){
            string nstr=sstr;
            nstr[xpos]=nstr[xpos+3];
            nstr[xpos+3]='x';
            int nid=calstate(nstr);
            if(visited[nid]==0){
                visited[nid]=1;
                prevs[nid]=Prev(id,'d');
                q.push(nid);
            }
        }
        if(xpos%3>0){
            string nstr=sstr;
            nstr[xpos]=nstr[xpos-1];
            nstr[xpos-1]='x';
            int nid=calstate(nstr);
            if(visited[nid]==0){
                visited[nid]=1;
                prevs[nid]=Prev(id,'l');
                q.push(nid);
            }
        }
        if(xpos%3<2){
            string nstr=sstr;
            nstr[xpos]=nstr[xpos+1];
            nstr[xpos+1]='x';
            int nid=calstate(nstr);
            if(visited[nid]==0){
                visited[nid]=1;
                prevs[nid]=Prev(id,'r');
                q.push(nid);
            }
        }
    }
    if(flag){
        string result="";
        int cid=0;
        while(cid!=sid){
            result=prevs[cid].pp+result;
            cid=prevs[cid].ps;
        }
        cout<<result<<endl;
    }
    else{
        cout<<"unsolvable"<<endl;
    }
    return 0;
}