#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n,data[15];
int num[15];

void dfs(int shu,int bianhao)//shu ä»£è¡¨ å·²ç»æå ä¸ªéå¥½çæ°å¨numéäº //ç¼å·ä»£è¡¨ å·²ç»å¨dataæ°ç»é ååå°äºç¬¬å ä¸ª
{
    if(bianhao>n+1) return;
    if(shu>7) return ;
    if(shu==7)
    {
        for(int i=1;i<6;i++)
            printf("%d ",num[i]);
        printf("%d\n",num[6]);
       return ;
    }

    num[shu]=data[bianhao];
    dfs(shu+1,bianhao+1);//é shu+1
    dfs(shu,bianhao+1); //ä¸é  shuä¸å. bianhao+1
    return ;
}

int main()
{
    int flag=1;
    while(scanf("%d",&n),n)
    {
        if(flag)
            flag=0;
        else
            puts("");
        for(int i=1;i<=n;i++)
            scanf("%d",&data[i]);
        dfs(1,1);
        
    }
    return 0;
}
 