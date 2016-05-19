#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
bool g[10][10],fil[10];
//g[10][10]记录点与点之间是否相连，fil[10]记录该数字是否已经选过
int a[10],ans[10],num;
//ans[]保存路径
void dfs(int deep,int move[])
{
    if(deep==8)//选完了
    {
        if(!num)//保存第一个答案
        {
            for(int i=0;i<8;i++)
                ans[i]=move[i];
        }
        num++;
        return ;
    }
    else if(a[deep]>0)//该点已经给定了数字，直接往下搜
    {
        move[deep]=a[deep];
        dfs(deep+1,move);
    }
    else {
        for(int i=1;i<=8;i++)//枚举8个数字
        {
            if(fil[i])//该数字已经选过
                continue;
            int flag=0;
            for(int j=0;j<8;j++)//枚举八个点
            {
                if(g[deep][j] && ((move[j]>0 &&abs(move[j]-i)==1)||(a[j]>0 && abs(a[j]-i)==1)) )//若该点与当前点相连&& 已经选了数字 && 差值等于1
                {
                    flag=1;break;
                }
            }
            if(flag) continue;
            move[deep]=i;fil[i]=true;
            dfs(deep+1,move);
            if(num>1)return ;
            move[deep]=0;fil[i]=false;
        }
    }
}

void init()
{
    memset(g,false,sizeof(g));
    for(int i=0;i<8;i++)
        g[i][i]=true;
    for(int i=1;i<=3;i++)
        g[i][0]=g[0][i]=true;
    g[1][2]=g[2][1]=true;
    g[1][4]=g[4][1]=true;
    g[1][5]=g[5][1]=true;
    for(int i=3;i<=6;i++)
        g[2][i]=g[i][2]=true;
    g[3][5]=g[5][3]=true;
    g[3][6]=g[6][3]=true;
    g[4][5]=g[5][4]=true;
    g[4][7]=g[7][4]=true;
    g[5][6]=g[6][5]=true;
    g[5][7]=g[7][5]=true;
    g[6][7]=g[7][6]=true;
}
int main()
{
    init();
    int cas=0,T;
    scanf("%d",&T);
    while(T--)
    {
        memset(fil,false,sizeof(fil));
        for(int i=0;i<8;i++)
        {
            scanf("%d",&a[i]);
            fil[a[i]]=true;
        }
        int move[10]={0};
        num=0;
        dfs(0,move);
        printf("Case %d: ",++cas); 
        if(num==0)
            printf("No answer\n");
        else if(num>1)
            printf("Not unique\n");
        else {
            printf("%d",ans[0]);
            for(int i=1;i<8;i++)
                printf(" %d",ans[i]);
            puts("");
        }
    }
    return 0;
}