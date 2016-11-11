#include<stdio.h>
#include<string>
#include<cstring>
#define MAX 1000300
using namespace std;

char data[MAX];
char newdata[2*MAX+1];
int sav[2*MAX+1];
int length;

int process()
{
    int j=0;int result=0,r=0,far=0,keypoint=0;
    newdata[j++]='_';
    for(int i=0;i<length;i++)
    {
        newdata[j++]=data[i];
        newdata[j++]='_';
    }
    length=length*2+1;
    for(int i=0;i<length;i++)
    {
        if(i<=far) r=min(sav[2*keypoint-i],far-i);
        while(i-r-1>=0&&i+r+1<length&&newdata[i-r-1]==newdata[i+r+1])
            r++;
        sav[i]=r;
        result=result>r?result:r;
        if((i+r)>far)
        {
            keypoint=i;
            far=i+r;
        }
    }
    return result;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",data);
        length=strlen(data);
        printf("%d\n",process());
    }
    return 0;
}
