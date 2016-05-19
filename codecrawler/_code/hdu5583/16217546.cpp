#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#define exp 1e-10
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int N = 100005;
const int M = 2010;
const int inf = 2147483647;
const int mod = 2009;
__int64 s[N];
char num[N];
int main()
{ 
    int t,i,j,p=1;
    __int64 ans,Max,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",num);
        for(ans=0,j=1,k=1,i=1;num[i]!='\0';i++)
            if(num[i]!=num[i-1])
                s[j++]=k,ans+=k*k,k=1;
            else
                k++;
        s[j++]=k;ans+=k*k;s[j++]=0;Max=ans;
        //printf("%I64d\n",Max);
        for(i=1;i<j-2;i++)
        {
            //printf("%d %d\n",s[i],s[i+1]);
            if(s[i+1]==1)
                Max=max(Max,ans-s[i]*s[i]-s[i+1]*s[i+1]-s[i+2]*s[i+2]+(s[i]+s[i+1]+s[i+2])*(s[i]+s[i+1]+s[i+2]));
            else
                Max=max(Max,ans-s[i]*s[i]-s[i+1]*s[i+1]+(s[i]+1)*(s[i]+1)+(s[i+1]-1)*(s[i+1]-1));
            //printf("###%d %I64d\n",i,Max);
            if(s[i]==1)
                Max=max(Max,ans-s[i]*s[i]-s[i+1]*s[i+1]-s[i-1]*s[i-1]+(s[i]+s[i+1]+s[i-1])*(s[i]+s[i+1]+s[i-1]));
            else
                Max=max(Max,ans-s[i]*s[i]-s[i+1]*s[i+1]+(s[i]-1)*(s[i]-1)+(s[i+1]+1)*(s[i+1]+1));
            //printf("@@@@%d %I64d\n",i,Max);
        }
        printf("Case #%d: %I64d\n",p++,Max);    
    }
    return 0; 
}