#include"stdio.h"
#include"string.h"
char str[1000111];
int next[1000111];
void getnext()
{
    int j,k;
    memset(next,0,sizeof(next));
    j=0;
    k=-1;
    next[0]=-1;
    while(str[j])
    {
        if(k==-1 || str[j]==str[k])    next[++j]=++k;
        else                        k=next[k];
    }
}
void KMP()
{
    int i;
    int t;
    for(i=2;str[i-1];i++)
    {
        t=i-next[i];
        if(i%t==0 && i/t>1)    printf("%d %d\n",i,i/t);
    }
}
int main()
{
    int Case=1;
    int n;
    while(scanf("%d",&n),n)
    {
        scanf("%s",str);
        printf("Test case #%d\n",Case++);
        getnext();
        KMP();
        printf("\n");
    }
    return 0;
}