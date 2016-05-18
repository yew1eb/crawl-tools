#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;
#define M 100000
bool visit[101000];
int prime[101000];
int num2[14000];
struct node
{
    int num;
    int a;
} unit[7000];
void table()
{
    memset(visit,true,sizeof(visit));
    int num = 0;
    for (int i = 2; i <= M; ++i)
    {
        if (visit[i] == true)
        {
            num++;
            prime[num] = i;
        }
        for (int j = 1; ((j <= num) && (i * prime[j] <= M));  ++j)
        {
            visit[i * prime[j]] = false;
            if (i % prime[j] == 0) break; //µã¾¦Ö®±Ê
        }
    }
}
/*
4
Case 1.
2 2
23

Case 2.
23 1
-1

*/
/*
4
Case 1.
2 2
23

Case 2.
23 1
-1
*/
int main()
{
    memset(prime, 0, sizeof(prime));
    table();
    int n;
    int i,j,k;
    int y=1;
    //for(int i=1;i<7000;i++)
    //printf("%d\n",prime[i]);
    for(i=1; i<7000; i++)
    {

        unit[i].a=prime[i];
        unit[i].num=0;
    }
    while(scanf("%d",&n),n>0)
    {

        if(y!=1)
        printf("\n");
        printf("Case %d.\n",y);
        //for(i=1;i<7000;i++)
        //printf("%d\n",unit[i].a);
        for(i=1; i<7000; i++)
        {
            unit[i].num=0;
        }
        for(i=1; i<7000; i++)
        {
            if(n<0)
                break;
            while(n%unit[i].a==0)
            {

                unit[i].num++;
                n=n/unit[i].a;
                //printf("%d %d %d\n",unit[i].a,n,unit[i].num);
            }

        }
        int t=0;
        for(i=1; i<7000; i++)
        {
            if(unit[i].num)
            {
                num2[t]=unit[i].a;
                num2[t+1]=unit[i].num;
                t=t+2;
            }
        }
        //printf("%d\n",t);

        for(i=0; i<t-1; i++)
        {
            printf("%d ",num2[i]);
        }
        printf("%d \n",num2[t-1]);
        //printf("\n");
        y++;
    }
    return 0;
}