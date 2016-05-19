#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


//*****************************************************
//originå­æ¾éè®¡ç®çç©éµï¼reså­æ¾ç­æ¡ç©éµ
//æç»ç­æ¡ä¸ºres.a[1][0](å¯¹åºf[n])
struct matrix
{
    double a[3][3];
};
matrix origin,res;

//å°resåå§åä¸ºåå§æ¡ä»¶ç©éµï¼äººä¸ºè¾å¥å³ç³»éæ¨ç©éµorigin
void init()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%lf",&origin.a[j][i]);
        }
    }
}

//ç´æ¥å°2ä¸ªç©éµç¸ä¹x*y,è¿åè®¡ç®åçç©éµ
matrix multiply(matrix &x,matrix &y)
{
    matrix temp;
    memset(temp.a,0,sizeof(temp.a));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                temp.a[i][j]+=x.a[i][k]*y.a[k][j];
            }
        }
    }
    return temp;
}

//ç©éµå¿«éå¹çè®¡ç®,ç©éµçnæ¬¡å¹ï¼æ¯ä¸ªä¸­é´ç»æå¯¹MODåæ¨¡
void calc(matrix &origin,matrix &res,int n)
{
    while(n)
    {
        if(n&1)
            res=multiply(origin,res);
        n>>=1;
        origin=multiply(origin,origin);
    }
}
//*****************************************************

int main()
{
    int cas,i,n,query,s,e;
    cin>>cas;
    while(cas--)
    {
        init();
        matrix tmp=origin;
        scanf("%d",&query);
        while(query--)
        {
            scanf("%d%d%d",&s,&e,&n);
            memset(res.a,0,sizeof(res.a));
            s--,e--;
            res.a[s][0]=1;
            calc(origin,res,n);
            printf("%0.3lf\n",res.a[e][0]);
            origin=tmp;
        }
    }
    return 0;
}