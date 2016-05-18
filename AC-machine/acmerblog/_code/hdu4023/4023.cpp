#include <cstdio>
#define min(a,b) (a>b?b:a)
int num[16];
int game[10];
int p[5];
int main ()
{
    int cas;
    scanf("%d",&cas);
    for (int I=1 ; I<=cas ; ++I)
    {
        int tmpmin;
        int turn=0;//表示当前子游戏的先手
        p[0]=0;p[1]=0;//记录约去平衡状态后的每个人的可放个数
        for (int i=0 ; i<15 ; ++i)
        {
            scanf("%d",num+i);
        }
        game[0]=num[0];     game[1]=num[1];             ///1
        game[2]=num[2]+num[3];  game[3]=num[4]+num[5];  ///2
        game[4]=num[6]+num[7];    game[5]=num[8]+num[9];///3
        game[6]=num[10]+num[11]+num[12]+num[13];        ///4
        game[7]=num[14];                                ///5
        
        /**约去平衡态**/
        /// 1
        game[0]>game[1]?p[0]+=2*(game[0]-game[1]):p[1]+=2*(game[1]-game[0]);
        /// 2
        tmpmin=min(game[2],game[3]);
        game[2]-=tmpmin;
        game[3]-=tmpmin;
        /// 3
        tmpmin=min(game[4],game[5]);
        game[4]-=tmpmin;    game[5]-=tmpmin;
        /// 4
        game[6]=game[6]&1;
        /// 5
        game[7]=game[7]&1;

        /// 5>2>4>3>1
        ///**按优先级进行游戏 1情况不影响结果可先处理**///
        ///5
        if(game[7])p[turn]+=2,turn^=1;
        ///2
        if(game[2])
        {
            if(game[2]&1){if(turn == 1)p[1]+=2;  else p[0]+=1; turn^=1 ; }
            p[1]+=game[2]/2*2;
            p[0]+=game[2]/2;
        }
        if(game[3])
        {
            if(game[3]&1){if(turn == 0)p[0]+=2;  else p[1]+=1; turn^=1 ; }
            p[0]+=game[3]/2*2;
            p[1]+=game[3]/2;
        }
        ///4
        if(game[6])
        {
            p[turn]+=1;turn^=1;
        }
        ///3
        if(game[4])
        {
            p[0]+=game[4];
            if(game[4]&1)
            {
                if(turn == 1)p[1]+=1;
                turn^=1;
            }
            p[1]+=game[4]/2;
        }
        if(game[5])
        {
            p[1]+=game[5];
            if(game[5]&1)
            {
                if(turn == 0)p[0]+=1;
                turn^=1;
            }
            p[0]+=game[5]/2;
        }
        ///
        //printf("%d----%d\n",p[0],p[1]);
        printf("Case #%d: %s\n",I,p[0]>p[1]?"Alice":"Bob");
    }
    return 0;
}
