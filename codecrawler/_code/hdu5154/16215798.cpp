//èæ¥ç¥è¯ç¹ï¼æææåºããã 
#include<stdio.h>
#include<string.h>
#define inf 110
int line[inf][inf];
int in[inf];
int n,m;
int i,j,k;
int count;
int a,b;
void topo()
{
    for(i=1;i<=n;++i)//næ¬¡éå 
    {
        for(j=1;j<=n;++j)//æ¯æ¬¡éånä¸ªæ°  
        {
            if(!in[j])
            {
                in[j]--;
                count++;
                for(k=1;k<=n;++k)
                {
                    if(line[j][k])
                    in[k]--;
                } 
            }    
        }
    } 
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(line,0,sizeof(line));
        memset(in,0,sizeof(in));
        count=0;
        for(i=1;i<=m;++i)
        {
            scanf("%d%d",&a,&b);
            if(!line[a][b])
            {
                line[a][b]=1;
                in[b]++;
            }
        }
        topo();
        if(count==n)
        printf("YES\n");
        else
        printf("NO\n");
    }    
    return 0;
} 