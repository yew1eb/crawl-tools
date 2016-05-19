#include<stdio.h>
int main()
{
    int T;
    int i,n;
    int ans,m,l;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ans=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&m,&l);
            ans=ans^(m%(l+1));
        }    
        if(ans==0)  printf("Yes\n");//后取的人胜 
        else   printf("No\n");//先取的人胜 
    }    
    return 0;
}