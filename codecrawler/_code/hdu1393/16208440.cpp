#include<stdio.h>
#include<string.h>
bool visited[61] = {false};
int s=0,d=0;
int main()
{
    while(scanf("%d%d",&s,&d)!=EOF&&(s+d)>0)
    {
        memset(visited,false,sizeof(visited));
        visited[60]=true;
        visited[s]=true;
        int cnt=0;
        while(s != 60)
        {
            s=s+s*d;
            cnt++;
            while(s>60) s-=60;
            if(visited[s]) break;
            else visited[s] = true;
        }
        if(s==60) printf("%d\n",cnt);
        else printf("Impossible\n");
    }
    return(0);
}
