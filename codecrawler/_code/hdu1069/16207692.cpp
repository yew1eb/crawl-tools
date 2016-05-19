#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
    int l,w,h;
}box[111];
int dp[111];
bool cmp(node a,node b)
{
   if(a.l>b.l) return true;
   if(a.l==b.l&&a.w>b.w) return true;
   return false;
}
int main()
{
    int d[3],n,i,j,c=1,k,sumh;
    while(scanf("%d",&n)!=EOF&&n)
    {
        k=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&d[0],&d[1],&d[2]); 
            sort(d,d+3);
            //å°æ°æ®è½¬æ¢æå¤ç§å½¢å¼çç©å½¢ä½
            box[k].l=d[2];box[k].w=d[1];box[k].h=d[0];k++;
            box[k].l=d[2];box[k].w=d[0];box[k].h=d[1];k++;
            box[k].l=d[1];box[k].w=d[0];box[k].h=d[2];k++;     
        } 
        sort(box,box+k,cmp);
        for(i=0;i<k;i++) dp[i]=box[i].h;
        for(i=k-2;i>=0;i--)
            for(j=i+1;j<k;j++)
            {
               if(box[i].l>box[j].l&&box[i].w>box[j].w)//æå¤§éådp
                   if(dp[i]<dp[j]+box[i].h)
                       dp[i]=dp[j]+box[i].h;
            }
            sumh=dp[0];
            for(i=0;i<k;i++)
                if(sumh<dp[i]) sumh=dp[i];
            printf("Case %d: maximum height = %d\n",c++,sumh);
    }
   return 0;
}