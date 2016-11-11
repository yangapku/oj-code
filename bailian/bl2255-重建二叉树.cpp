#include<iostream>
#include<vector>
using namespace std;

string s1,s2;
string cal(int p1,int e1,int p2,int e2){
    string res="";
    if(p1==e1) return "";
    if(e1-p1==1) return res+s1[p1];
    char rootch=s1[p1];
    int rootpos;
    for(rootpos=p2;rootpos<e2;rootpos++){
        if(s2[rootpos]==rootch) break;
    }
    int len1=rootpos-p2;
    int len2=e2-(rootpos+1);
    return cal(p1+1,p1+1+len1,p2,p2+len1)+cal(e1-len2,e1,e2-len2,e2)+rootch;
}

int main(){
    while(cin>>s1>>s2){
        cout<<cal(0,s1.length(),0,s2.length())<<endl;
    }
}
