#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<string> vec;
int result=0;
int id=0;

string strrev(const string& s){
    string sv;
    for(int i=s.length()-1;i>=0;i--){
        sv+=s[i];
    }
    return sv;
}

void DFS(int pos,int l){
    if(vec[id].length()-pos<result) return;
    string ns=vec[id].substr(pos,l);
    string nsv=strrev(ns);
    int i;
    for(i=0;i<vec.size();i++){
        if(vec[i].find(ns)==-1 && vec[i].find(nsv)==-1) break;
    }
    if(i==vec.size()){
        result=max(result,l);
        if(pos+l+1<=vec[id].size()) DFS(pos,l+1);
    }
}

int main(){
    int T;
    cin>>T;
    for(int ccc=0;ccc<T;ccc++){
        vec.clear();
        result=0;
        int N;
        id=0;
        cin>>N;
        for(int i=0;i<N;i++){
            string s;
            cin>>s;
            vec.push_back(s);
            if(s.length()<vec[id].length()) id=vec.size()-1;
        }
        for(int i=0;i<vec[id].length();i++){
            DFS(i,1);
        }
        cout<<result<<endl;
    }
    return 0;
}
