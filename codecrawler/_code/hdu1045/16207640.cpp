#include"stdio.h"
#include"string.h"


struct A
{
    int x,y;
}E[20];
int total;
int map[6][6];
int n;
int ans;
int dir[4][2]={1,0, -1,0, 0,1, 0,-1};


int judge2(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=n)    return -1;
    if(map[x][y]==1)    return 1;
    return map[x][y];
}
int judge(int k)
{
    int flag;
    int i;
    int t_x,t_y;
    int temp;


    flag=0;
    for(i=0;i<4;i++)
    {
        if(flag)    break;
        t_x=E[k].x+dir[i][0];
        t_y=E[k].y+dir[i][1];
        while(t_x>=0 && t_x<n && t_y>=0 && t_y<n)
        {
            temp=judge2(t_x,t_y);
            if(temp==-1)    break;
            if(temp==1)        {flag=1;break;}
            t_x+=dir[i][0];
            t_y+=dir[i][1];
        }
    }
    return flag;
}


void DFS(int k,int num)
{
    if(num>ans)        ans=num;


    if(k==total)    return ;

    DFS(k+1,num);

    if(!judge(k))
    {
        map[E[k].x][E[k].y]=1;
        DFS(k+1,num+1);
        map[E[k].x][E[k].y]=0;
    }
}


int main()
{
    int i,l;
    char str[10];
    
    while(scanf("%d",&n),n)
    {
        total=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            for(l=0;str[l];l++)
            {
                if(str[l]=='.')
                {
                    map[i][l]=0;
                    E[total].x=i;
                    E[total].y=l;
                    total++;
                }
                else if(str[l]=='X')map[i][l]=-1;
            }
        }


        ans=0;
        DFS(0,0);
        printf("%d\n",ans);
    }
    return 0;
}