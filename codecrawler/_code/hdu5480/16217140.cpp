#include<stdio.h>
#include<string.h>
int d[3][100005];
int lowbit(int x)
{
    return x&(-x);
}
void update(int i,int x,int n)
{
    while(x<=n)
    {
        d[i][x]++;
        x=x+lowbit(x);
    }
}
int  getsum(int x,int i)
{
    int ans=0;
    while(x>0)
    {
       ans=ans+d[i][x];
       x=x-lowbit(x);
    }
    return ans;
}
int main()
{
      int i,j,k,T;
       int n,m,K,Q;
        int x,y,x1,x2,y1,y2,vis1[100005],vis2[100005];
        scanf("%d",&T);
        while(T--)
        {
            memset(d,0,sizeof(d));
            memset(vis1,0,sizeof(vis1));
            memset(vis2,0,sizeof(vis2));
            scanf("%d%d%d%d",&n,&m,&K,&Q);
            for(i=1;i<=K;i++)
            {
                scanf("%d%d",&x,&y);
                if(!vis1[x])     //æ³¨æå¤é
                {update(0,x,n);
            vis1[x]=1;
             }
             if(!vis2[y])
                {
                    vis2[y]=1;
                    update(1,y,m);
            }
             
        }

               while(Q--)
               {
                int a,b;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                a=getsum(x2,0)-getsum(x1-1,0);
                b=getsum(y2,1)-getsum(y1-1,1);
                if(a<x2-x1+1&&b<y2-y1+1)printf("No\n");
                else printf("Yes\n");
                }
            }
            return 0;
    }
/*
3
3 4 2 5
1 1
2 3
1 1 3 2
*/
