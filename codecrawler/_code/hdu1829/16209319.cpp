#include"stdio.h"
#include"string.h"
int set[2011];
int sex[2011];


void build(int n)
{
    int i;
    for(i=1;i<=n;i++)    set[i]=i;
}
int find(int k)
{
    if(set[k]==k)    return k;
    set[k]=find(set[k]);
    return set[k];
}
void insert(int x,int y)
{
    int f1,f2;
    f1=find(x);
    f2=find(y);
    if(f1==f2)    return ;
    set[f1]=f2;
}


int main()
{
    int T,Case;
    int n,m;
    int a,b;
    int flag;


    scanf("%d",&T);
    for(Case=1;Case<=T;Case++)
    {
        scanf("%d%d",&n,&m);


        build(n);


        memset(sex,0,sizeof(sex));
        flag=0;
        while(m--)
        {
            scanf("%d%d",&a,&b);
            if(flag)                continue;
            if(find(a)==find(b))    {flag=1;continue;}


            if(sex[a]==0)    sex[a]=b;
            else    insert(sex[a],b);
            if(sex[b]==0)    sex[b]=a;
            else    insert(sex[b],a);
        }


        printf("Scenario #%d:\n",Case);
        if(flag)    printf("Suspicious bugs found!");
        else        printf("No suspicious bugs found!");
        printf("\n\n");
    }
    return 0;
}