#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std; 
int  s[101];
int tt[10001];
 
int g(int x , int  k)
{
    int mex[101];
    memset(mex,0,sizeof(mex));
    if(tt[x]!=-1) return tt[x]; //集合S一致，则每个数量的mex一样，所以可以重复利用 
    if(x-s[0]<0) return tt[x]=0; //s[0]为集合中最小值，x-s[0]<0,则x不可能到达其他状态，一定为P 
    for(int i=0;i<k && x-s[i]>=0;i++) //判断条件，因为s[]排了序，当x-s[i]<0就停止循环。 
    { 
        mex[g(x-s[i] , k)]=1; //x的后继SG函数中的没有出现的最小非负数 
    }
    for(int i=0;;i++) //通过x的后继SG函数出现的非负数得x的结果 
    if(!mex[i])  return tt[x]=i;
}

int main()
{
    int  k ;
    int n, t ,a , ans;
    while(scanf("%d",&k)!=EOF && k)
    {
        memset(tt,-1,sizeof(tt));
        tt[0]=0;
        for(int i=0;i<k;i++) scanf("%d",&s[i]);
        sort(s,s+k);
        scanf("%d",&t); 
        while(t--)
        {
            ans=0;
            scanf("%d",&n);
            for(int i=0;i<n;i++) 
            {
                scanf("%d",&a);  
                ans^=g(a , k);
            }  
           // for(int i=0;i<=12; i++) cout<<i<<"   ";cout<<endl;
            //for(int i=0;i<=12;i++) cout<<tt[i]<<" ";cout<<endl;
            if(!ans)  printf("L"); //异或sum！=0，说明该点为必败点，只能到达必胜点。 
            else printf("W");
        }
        printf("\n");
    }
    return 0;
} 
/*
(0,1,1) 的异或sum=0，为必败点.
P必败点是指刚取过石头的人获胜，必败点无论怎么移动都只能到达必胜点。 
*/