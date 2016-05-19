#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct Node
{
    char name[100];
    char space[100];
    int num;
} f[110];

int cmp(Node x,Node y)
{
    if(strcmp(x.space,y.space))
        return strcmp(x.space,y.space)<0;
    return strcmp(x.name,y.name)<0;
}

int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%*c",&n);
        for(i = 0; i<n; i++)
        {
            scanf("%s%s%d",f[i].name,f[i].space,&f[i].num);
        }
        sort(f,f+n,cmp);
        char di[100],min[100];
        int cnt = 0,flag = 1;
        strcpy(di,f[0].space);
        strcpy(min,f[0].name);
        for(i = 0; i<n; i++)
        {
            if(strcmp(di,f[i].space))
            {
                strcpy(di,f[i].space);
                strcpy(min,f[i].name);
                flag = 1;
                cnt = 0;
            }
            if(!strcmp(di,f[i].space))
            {
                if(flag)
                {
                    printf("%s\n",di);
                    flag = 0;
                }
                if(!strcmp(min,f[i].name))
                {
                    while(!strcmp(min,f[i].name) && !strcmp(di,f[i].space))//äº§å°ä¸æ°´æåé½å¿é¡»ç¸å
                    {
                        cnt+=f[i].num;
                        i++;
                    }
                    printf("   |----%s(%d)\n",min,cnt);
                    strcpy(min,f[i].name);
                    i--;
                    cnt = 0;
                }
            }
        }
        if(t)
        printf("\n");
    }

    return 0;
}
