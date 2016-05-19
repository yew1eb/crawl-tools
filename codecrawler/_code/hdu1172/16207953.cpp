#include<stdio.h>
#include<cstring>
using namespace std;
const int MAXN=100;
struct Node
{
    int a,b,c;
} node[MAXN];

bool Judge(int k,int number)
{
    int num1[5],num2[5];
    bool mark[5];
    for(int i=1; i<=4; i++)mark[i]=false;

    num1[1]=node[k].a/1000;
    num1[2]=(node[k].a%1000)/100;
    num1[3]=(node[k].a%100)/10;
    num1[4]=(node[k].a%10);

    num2[1]=number/1000;
    num2[2]=(number%1000)/100;
    num2[3]=(number%100)/10;
    num2[4]=(number%10);

    int count=0;
    for(int i=1; i<=4; i++)//ç¸åä½ç½®ç¸åçæ°
    {
        if(num1[i]==num2[i])count++;
    }
    if(count!=node[k].c)return false;//å¦æä¸ªæ°ä¸ç¬¦å°±è¿åé

    count=0;
    for(int i=1; i<=4; i++)//ç¸åæ°å­çä¸ªæ°
    {
        for(int j=1; j<=4; j++)
        {
            if(num1[i]==num2[j]&&!mark[j])
            {
                mark[j]=true;
                count++;
                break;
            }
        }
    }
    if(count!=node[k].b)return false;

    return true;
}



int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d%d",&node[i].a,&node[i].b,&node[i].c);
        }
        int count=0,result;
        bool flag=true;
        for(int num=1000; num<=9999; num++)//æ´åæä¸¾
        {
            for(int i=1; i<=n; i++)
            {
                flag=Judge(i,num);
                if(!flag)break;
            }
            if(flag)
            {
                count++;
                result=num;
            }
        }
        if(count==1)
        {
            printf("%d\n",result);
        }
        else
            printf("Not sure\n");
    }
    return 0;
}
