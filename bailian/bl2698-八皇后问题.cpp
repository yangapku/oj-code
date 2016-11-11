#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

char g[8][8];
int result=0;

void DFS(int pos,int step){
	g[pos][step-1]=1;
	int index;
	for(index=0;index<step-1;index++){
		if(g[pos][index]) break;
	}
	if(index<step-1){
		g[pos][step-1]=0;
		return;
	}
	for(int i=1;i<=7;i++){
		if(pos-i>=0 && step-1-i>=0 && g[pos-i][step-1-i]){
			g[pos][step-1]=0;return;
		}
		if(pos+i<=7 && step-1-i>=0 && g[pos+i][step-1-i]){
			g[pos][step-1]=0;return;
		}
		if(pos+i<=7 && step-1+i<=7 && g[pos+i][step-1+i]){
			g[pos][step-1]=0;return;
		}
		if(pos-i>=0 && step-1+i<=7 && g[pos-i][step-1+i]){
			g[pos][step-1]=0;return;
		}
	}
	if(step==8){
		result++;
		cout<<"No. "<<result<<endl;
		for(int i=0;i<=7;i++){
			for(int j=0;j<=7;j++){
				cout<<(int)g[i][j]<<' ';
			}
			cout<<endl;
		}
		g[pos][step-1]=0;return;
	}
	for(int i=0;i<8;i++){
		DFS(i,step+1);
	}
	g[pos][step-1]=0;
}

int main(){
	for(int i=0;i<8;i++){
		DFS(i,1);
	}
}
