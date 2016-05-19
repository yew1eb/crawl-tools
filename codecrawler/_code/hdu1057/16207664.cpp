/*
author:jxy
lang:C/C++
university:China,Xidian University
**If you need to reprint,please indicate the source**
*/
#include <cstdio>
#include <cstring>
const char o[4]={'.','!','X','#'};
const int dir[4][2]={-1,0,1,0,0,-1,0,1};
int day,now[20][20],next[20][20],change[16];
int main()
{
    int T,i,j,k,x,y,temp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&day);
        for(i=0;i<16;i++)scanf("%d",&change[i]);
        for(i=0;i<20;i++)
          for(j=0;j<20;j++)
             scanf("%d",&now[i][j]);
        while(day--)
        {
            for(i=0;i<20;i++)
             for(j=0;j<20;j++)
             {
                temp=now[i][j];
                for(k=0;k<4;k++)
                {
                    x=i+dir[k][0];
                    y=j+dir[k][1];
                    if(x<0||x>=20||y<0||y>=20)continue;
                    temp+=now[x][y];
                }
                next[i][j]=now[i][j]+change[temp];
                if(next[i][j]<0)next[i][j]=0;
                if(next[i][j]>3)next[i][j]=3;
             }
            memcpy(now,next,sizeof(next));
        }
        for(i=0;i<20;i++,puts(""))
         for(j=0;j<20;j++)
             printf("%c",o[now[i][j]]);
        if(T)puts("");
    }
    return 0;
}
