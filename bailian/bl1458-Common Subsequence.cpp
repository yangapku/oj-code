#include<iostream>
#include<vector>
#include<string>
#define MAXN 300
using namespace std;

int record[MAXN][MAXN];
int main(){
    string s1,s2;
    while(cin>>s1>>s2){
        int l1=s1.length();
        int l2=s2.length();
        for(int i=0;i<=l2;i++){
            record[i][0]=0;
        }
        for(int i=0;i<=l1;i++){
            record[0][i]=0;
        }
        for(int i=1;i<=l2;i++){
            for(int j=1;j<=l1;j++){
                if(s2[i-1]==s1[j-1]){
                    record[i][j]=max(record[i-1][j-1]+1,max(record[i][j-1],record[i-1][j]));
                }
                else{
                    record[i][j]=max(record[i][j-1],record[i-1][j]);
                }
            }
        }
        cout<<record[l2][l1]<<endl;
    }
}
