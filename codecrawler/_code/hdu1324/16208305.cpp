#include<stdio.h>
#include<string.h>
int Z,I,M,L;
int cases=0;
bool visited[10000]={false};
int inds[10000]={0};
int main()
{
    while(scanf("%d%d%d%d",&Z,&I,&M,&L)!=EOF&&(Z+I+M+L)>0)
    {
        printf("Case %d: ",++cases);
        memset(visited,false,sizeof(visited));
        int ind=1;
        visited[L]=true;
        inds[L]=ind++;
        while(true)
        {
            L=(Z*L+I)%M;
            if(visited[L]) break;
            visited[L]=true;
            inds[L]=ind++;
        }
        printf("%d\n",ind-inds[L]);
    }
    return(0);
}
