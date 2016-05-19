#include<stdio.h>
#include<string.h>
#include<ctype.h>
char map[105][105];
int vis[27];
int main()
{
    int n,m,i,j,k,q,flag,_i,_j;
    char c;
    while(scanf("%d%d",&n,&m)&&n)
    {
        for(i=0;i<n;i++)
            scanf("%s",map[i]);
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(isupper(map[i][j])&&vis[map[i][j]-'A']==0)
                {
                    flag=0;
                    vis[map[i][j]-'A']=1;
                    int h=0,w=0;
                    for(k=j;;k++)
                        if(map[i][k]!=map[i][j])
                            break;
                    w=k;
                    for(k=i;;k++)
                        if(map[k][j]!=map[i][j])
                            break;
                    h=k;
                    if((w-j+1)<3||(h-i+1)<3)
                        continue;
                    for(k=i;k<h;k++)
                    {
                        for(q=j;q<w;q++)
                        {
                            if(k==i||k==h-1)
                            {
                                if(map[k][q]!=map[i][j])
                                {flag=1;break;}
                            }
                            else if(q==j||q==w-1)
                            {
                                if(map[k][q]!=map[i][j])
                                {flag=1;break;}
                            }
                            else if(map[k][q]!='.')
                            {
                                flag=1;break;
                            }
                        }
                        if(flag==1)
                            break;
                    }
                    if(flag==1)
                        continue;
                    vis[map[i][j]-'A']=-1;
                }
            }
        }
        for(i=0;i<26;i++)
            if(vis[i]==-1)
                printf("%c",'A'+i);
        printf("\n");
    }
    return 0;
}