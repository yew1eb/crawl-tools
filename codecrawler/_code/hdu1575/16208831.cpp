#include<stdio.h>
#include<string.h>
#define max 12
struct node
{
    int map[max][max];
}st,ed;
int n,k;
//ç©éµç¸ä¹
node mat_mul(node a,node b)
{
    node tem;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            tem.map[i][j]=0;
            for(int h=0; h<n; h++)
                tem.map[i][j]+=a.map[i][h]*b.map[h][j];
            tem.map[i][j]%=9973;
        }
    return tem;
}
int qu_sum()//äºåæ³ç©éµæ±å¹
{
    node tem1=st,tem2=ed;
    while(k!=1)
    {
        if(k%2)
        {
            k--;
            tem1=mat_mul(tem1,tem2);
          //k=20 10 5(å¥æ°) 2 1
        }
        else
        {
            k>>=1;
            tem2=mat_mul(tem2,tem2);
        }

    }
    node ans=mat_mul(tem1,tem2);
    int sum=0;
    for(int j=0; j<n; j++)
    {
        sum+=ans.map[j][j];
        sum%=9973;
    }
    return sum;
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    while(T--)
    {
        memset(st.map,0,sizeof(st.map));
        scanf("%d%d",&n,&k);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
            {//åä½ç©éµ
                st.map[i][j]=0;
                st.map[i][i]=1;
                scanf("%d",&ed.map[i][j]);
            }
        printf("%d\n",qu_sum());
    }
    return 0;
}
