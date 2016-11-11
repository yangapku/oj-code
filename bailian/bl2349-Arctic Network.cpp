#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cmath>
#define MAXN 520
using namespace std;

struct Node{
    double x;
    double y;
    Node(double x,double y){this->x=x;this->y=y;}
};
vector<Node> data;
const double MAXL=99999999999999;
double dist[MAXN];
char visited[MAXN];

double far(Node& n1,Node& n2){
    return sqrt((n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y));
}
int main(){
    int N;
    cin>>N;
    for(int ccc=0;ccc<N;ccc++){
        data.clear();
        int S,P;
        cin>>S>>P;
        for(int i=0;i<P;i++){
            dist[i]=MAXL;
            visited[i]=0;
        }
        for(int i=0;i<P;i++){
            double x,y;
            cin>>x>>y;
            data.push_back(Node(x,y));
        }
        for(int i=0;i<P;i++){
            dist[i]=far(data[0],data[i]);
        }
        for(int i=0;i<P;i++){
            int id=-1;
            double mindist=MAXL;
            for(int j=0;j<P;j++){
                if(visited[j]==0 && dist[j]<mindist){
                    mindist=dist[j];
                    id=j;
                }
            }
            visited[id]=1;
            for(int j=0;j<P;j++){
                if(visited[j]==0){
                    double nd=far(data[id],data[j]);
                    if(nd<dist[j]) dist[j]=nd;
                }
            }
        }
        priority_queue<double> pq;
        for(int i=0;i<P;i++){
            pq.push(dist[i]);
        }
        for(int i=0;i<(S-1);i++){
            pq.pop();
        }
        double result=pq.top();
        printf("%0.2f\n",result);
    }
    return 0;
}

