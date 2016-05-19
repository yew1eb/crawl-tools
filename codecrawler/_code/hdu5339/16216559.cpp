#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int b[50],temp[50];
int cmp(int a,int b){
    return a>b;
}
int main(){
    int n,a,t,i,j,k,cur,num,sum,minn,sign;
    scanf("%d",&t);
    while(t--){
    scanf("%d%d",&n,&a);
    sign=0;
    for(i=0;i<n;i++)
    scanf("%d",&b[i]);
    minn=99999999;
    sum=1<<n;
    sort(b,b+n,cmp);            //åå¯¹å°çåä½ä¹ååå¯¹å¤§çåä½æ²¡ææä¹
    for(i=1;i<sum;i++){         //å æ­¤å°æ°åæåºåï¼ä»å¤§å°å°éå
       j=i;k=cur=0;num=a;
       while(j){                //éåææå­åºåï¼
       if(j&1)temp[cur++]=b[k]; //å­åºåçæè¯¦è§http://blog.csdn.net/stay_accept/article/details/47204619
       j>>=1;k++;
       }
       if(cur>=minn)            //æ¾åè¿ç®åé¢å¯ä»¥èçæ¶é´
       continue;
//       for(j=0;j<cur;j++)
//       cout<<temp[j]<<" ";
//       cout<<endl;
       for(j=0;j<cur;j++)
       num%=temp[j];
       if(num==0){
       minn=cur;
       sign=1;
       }
    }
    if(sign)
    printf("%d\n",minn);
    else
    printf("-1\n");
    }
    return 0;
}
