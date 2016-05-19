#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int point[100002];
#define INF 0x7fffffff

int process(int n,int t)
{
    int sum,tmp,max1,max2,tt;
    int i,j;

    sort(point,point+n);       //å¯¹ç¹è¿è¡æåº
    tt=0;
    sum=0;
    max1=-INF;
    for(i=0;i<n;i++)        //ä»¥æ­£æ¹åä¸ºä¸»è¦æ¹åè¿è¡èè
    {
        if(point[i]>=0 && point[i]<=t)
        {
            tt++;
            sum=tt;
            tmp=t-point[i];
            for(j=n-1;j>=0;j--)
                if(point[j]<0 && abs(2*point[j])<=tmp) //2*point[j]æ­£åä¸¤æ¬¡
                    sum++;
        }
        if(max1<sum)   //æ¾å°æå¤§çsum
            max1=sum;
    }
    tt=0;
    max2=-INF;
    sum=0;
    for(i=n-1;i>=0;i--)        //ä»¥è´æ¹åä¸ºä¸»è¦æ¹åè¿è¡èè
    {
        if(point[i]<=0 && abs(point[i])<=t)
        {
            tt++;
            sum=tt;
            tmp=t-abs(point[i]);
            for(j=0;j<n;j++)
                if(point[j]>0 && 2*point[j]<=tmp) //2*point[j]æ­£åä¸¤æ¬¡
                    sum++;
        }
        if(max2<sum)   //æ¾å°æå¤§çsum
            max2=sum;
    }
    return max1>max2?max1:max2;
}

int main()      
{
    int n,t,i;

    ios::sync_with_stdio(false);
    while(cin>>n>>t)
    {
        for(i=0;i<n;i++)
            cin>>point[i];
        cout<<process(n,t)<<endl;
    }
    return 0;      
}
