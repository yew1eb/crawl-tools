#include<stdio.h>
#include<string.h>
int players[10000+1];//begin with 1
int N=0,M=0;
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF&&(M+N)>0)
    {
        memset(players,0,sizeof(players));
        int num=0,max_cnt=0,sec_cnt=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                scanf("%d",&num);
                players[num]++;
                if(players[num]>max_cnt) max_cnt=players[num];
            }
        }
        int j=0;
        for(sec_cnt=max_cnt-1;sec_cnt>=1;sec_cnt--)
        {
            int find_flag=0;
            for(j=1;j<=10000;j++)
            {
                if(sec_cnt==players[j]) {find_flag=1;printf("%d",j);break;}
            }
            if(find_flag) break;
        }
        for(j=j+1;j<=10000;j++) if(sec_cnt==players[j]) printf(" %d",j);
        printf("\n");
    }
    return(0);
}
