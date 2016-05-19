#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include<algorithm>  
#include<iostream>
using namespace std;  
#define N 1010
int n=1001;
int c[N][N];
int map[N][N];
int lowbit(int x)
{
    return x&(-x);
}
void update(int x,int y,int val)
{
    int i,j;
    for(i=x;i<=n;i+=lowbit(i))
        for(j=y;j<=n;j+=lowbit(j))
            c[i][j]+=val;
}
int getsum(int x,int y)
{
    int i,j,sum=0;
    for(i=x;i>0;i-=lowbit(i))
        for(j=y;j>0;j-=lowbit(j))
            sum+=c[i][j];
    return sum;
}

int main()
{
    int t,ans=0;
    scanf("%d",&t);
    while(t--)
    {
        ans++;
        printf("Case %d:\n",ans);
        int q,i,j,k;
        int a,b,e,f;
        scanf("%d",&q);
        memset(c,0,sizeof(c));
        for(i=1;i<=1001;i++)
            for(j=1;j<=1001;j++){
                c[i][j]=lowbit(i)*lowbit(j);
                map[i][j]=1;
            }
        while(q--)
        {
            char ch;
            scanf("%c",&ch);
            scanf("%c",&ch);
            if(ch=='S'){
                scanf("%d%d%d%d",&a,&b,&e,&f);
                a++,b++,e++,f++;
                if(a>e) swap(a,e);
                if(b>f) swap(b,f);
                int sum=getsum(e,f)-getsum(e,b-1)-getsum(a-1,f)+getsum(a-1,b-1);
                printf("%d\n",sum);
            }
            else if(ch=='A'){
                scanf("%d%d%d",&a,&b,&e);
                a++,b++;
                update(a,b,e);
                map[a][b]+=e;
            }
            else if(ch=='D'){
                scanf("%d%d%d",&a,&b,&e);
                a++,b++;
                if(map[a][b]>=e)
                {
                    map[a][b]-=e;
                    update(a,b,-e);
                }
                else
                {
                    update(a,b,-map[a][b]);
                    map[a][b]=0;
                }
            }
            else if(ch=='M'){
                scanf("%d%d%d%d%d",&a,&b,&e,&f,&k);
                a++,b++,e++,f++;
                if(map[a][b]>=k){
                    map[a][b]-=k;
                    map[e][f]+=k;
                    update(a,b,-k);
                    update(e,f,k);
                }
                else{
                    update(a,b,-map[a][b]);
                    update(e,f,map[a][b]);
                    map[e][f]+=map[a][b];
                    map[a][b]=0;
                }
            }
        }
    }

}