#include<iostream>
#include<cstdio>
#include<memory.h>
struct node 
{
    int matrix[31][31];// åå¸ç¼å·1-30
}ma,E;
int city[31],len;
int find(int x,bool flag)
{
    for(int i=1;i<len;i++)
        if(city[i]==x)
            return i;
    if(flag==1)//æ·»å åå¸
    {
        city[len++]=x;
        return len-1;
    }
    return 50;//æ²¡æ¾å°åå¸
}
node operator * (node x,node y)
{
    node temp;
    for(int i=1;i<=30;i++)
        for(int j=1;j<=30;j++)
        {
            temp.matrix[i][j]=0;
            for(int k=1;k<=30;k++)
            {
                temp.matrix[i][j]+=(x.matrix[i][k]*y.matrix[k][j])%2008;
                //temp.matrix[i][j]%=2008;
            }
        }
    return temp;
}
node operator + (node x,node y)
{
    node temp;
    for(int i=1;i<=30;i++)
        for(int j=1;j<=30;j++)
        {
            temp.matrix[i][j]=(x.matrix[i][j]+y.matrix[i][j])%2008;
        }
    return temp;
}
node operator ^(node a,int k)
{
    
    if(k==0)
        return E;
    node p=a,ans=E;
    while(k)
    {
        if(k%2==1)
            ans=ans*p;
        k=k/2;//k>>1;//å¼ææ­»å¾ªç¯äº
        p=p*p;
    }
    return ans;
}
node fun(node a,int k)
{
    
    if(k==0)
        return E;
    if(k==1)
        return a;
    if(k%2==1)
    {
        return fun(a,k-1)+(a^k);
    }
    else
        return ((a^(k/2))+E)*fun(a,k/2);
}
int main()
{
    int n,t1,t2;
    __int64 v1,v2,p1,p2;
    memset(E.matrix,0,sizeof(E.matrix));
    for(int i=1;i<=30;i++)
        E.matrix[i][i]=1;

    while(scanf("%d",&n)!=EOF)
    {
        len=1;
        memset(ma.matrix,0,sizeof(ma.matrix));
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d %I64d",&p1,&p2);
            int x=find(p1,1);
            int y=find(p2,1);
            ma.matrix[x][y]++;
        }
        int k;
        scanf("%d",&k);
        while(k--)
        {
            scanf("%I64d %I64d %d %d",&v1,&v2,&t1,&t2);
            if(t1>t2)
            {
                int temp=t1;
                t1=t2;
                t2=temp;
            }
            int x=find(v1,0);
            int y=find(v2,0);
            int ans=0;
            if(x==50||y==50||t1==0&&t2==0)
                printf("0\n");
            else
            {
               /*node a=fun(ma,t2-t1-1);//è¿æ ·ç®æ¯éçï¼ï¼ï¼ï¼whyï¼ï¼ï¼
               a=a*(ma^(t1-1));
               int ans=a.matrix[x][y]%2008;*/
                if(t1>1)
                {
                    node tem1=fun(ma,t2);
                    node tem2=fun(ma,t1-1);
                    ans=(tem1.matrix[x][y]%2008-tem2.matrix[x][y]%2008)%2008;
                }
                else
                {
                    node tem1=fun(ma,t2);
                    ans=tem1.matrix[x][y]%2008;
                }
                if(ans<0)//æ³¨æè´æ°çå¤çï¼ï¼ï¼ï¼
                    ans+=2008;
               printf("%d\n",ans);
            }
        }
    }
    system("pause");
    return 0;
}