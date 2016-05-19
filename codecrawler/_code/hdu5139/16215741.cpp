#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <stdlib.h>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <set>
#define inf 0x3f3f3f3f
#define eps 1e-5
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define N  100010
#define mod 1000000007
using namespace std;
struct node
{
 int number,order,ans;
} a[N];
int cmp(const void *a,const void *b)
{
    node *p1=(node *)a,*p2=(node *)b;
    return p1->number-p2->number;
}
int cmp2(const void *a,const void *b)
{
    node *p1=(node *)a,*p2=(node *)b;
    return p1->order-p2->order;
}
int main()
{
   /// freopen("in.txt","r",stdin);
   /// freopen("stdout1002.txt","w",stdout);
    int n,i,num=0,k,number1;
    while(~scanf("%d",&number1))
    {
        a[num].number=number1;
        a[num].order=num;
        num++;
    }
    qsort(a,num,sizeof(a[0]),cmp);
    long long answer=1,pre=1,pren=1;
    for(i=1,k=0; i<=a[num-1].number; i++)
    {
        pren=(pren*i)%mod;
        answer=(pre*pren)%mod;
        pre=answer;
        while(a[k].number==i)///éå¤åç´ æ¶é¤
        {
            a[k].ans=answer;
            k++;
        }
    }
    qsort(a,num,sizeof(a[0]),cmp2);
    for(i=0;i<num;i++)
    {
        printf("%d\n",a[i].ans);
    }
    return 0;
}
