#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
using namespace std;
struct node
{
    char id[20];
    char name[20];
    int fen;
} a[maxn];
bool cmp1(node x,node y)
{
    if( strcmp(x.id , y.id) < 0 )//å­¦å·éå¢æåº
        return true;
    else
        return false;
}
bool cmp2(node x,node y)
{
    if(strcmp(x.name,y.name) < 0 )//åå­å­å¸åºééåæåº
        return true;
    else if(strcmp(x.name , y.name) == 0)
    {
        if( strcmp(x.id , y.id) < 0 )//å½è¥å¹²å­¦çå·æç¸åå§åæ¶ï¼åæä»ä»¬çå­¦å·éå¢æåº
            return true;
    }
    return false;
}
bool cmp3(node x,node y)
{
    if(x.fen<y.fen) return true;//æç»©ééåæåº
    else if(x.fen==y.fen)
    {
        if( strcmp(x.id , y.id) < 0 )//å½è¥å¹²å­¦çå·æç¸åæç»©æ¶ï¼åæä»ä»¬çå­¦å·éå¢æåº
            return true;
    }
    return false;
}
int main()
{
    int n,c,T=0,i;
    while(scanf("%d%d",&n,&c),n)
    {
        for(i=0; i<n; i++)
            scanf("%s%s%d",a[i].id,a[i].name,&a[i].fen);
        switch(c)
        {
        case 1:
            sort(a,a+n,cmp1);
            break;
        case 2:
            sort(a,a+n,cmp2);
            break;
        case 3:
            sort(a,a+n,cmp3);
            break;
        }

        printf("Case %d:\n",++T);
        for(i=0; i<n; i++)
            printf("%s %s %d\n",a[i].id ,a[i].name ,a[i].fen);
    }
    return 0;
}