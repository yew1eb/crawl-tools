#include<stdio.h>
#include<string.h>

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//åä¸ªæ¹åæç´¢
char map[110][110];
int flag[110][110];//flag[x][y]>0è¡¨ç¤º(x,y)å¤çç¾å·²ååå°æä¸ªåºåä¸­ã
int H,W;

int check(int x,int y){
    if(x>=0 && y>=0 && x<H && y<W)return 1;
    return 0;
}

void dfs(int x,int y,int cnt){
    int i,dx,dy;
    for(i=0;i<4;i++){
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        //ä»(x,y)ç¹æç´¢å°(dx,dy)ï¼å¹¶ä¸(dx,dy)å¤çç¾è¿æªååå°æä¸ªåºåä¸­ã
        if(check(dx,dy) && flag[dx][dy]==0 && map[dx][dy]=='#'){
            flag[dx][dy]=cnt;//æ è®°å·²åå
            //ä»(dx,dy)å¼å§æç´¢æ¥ç(dx,dy)ç"åå¨"æ¯å¦ææªæ è®°çç¹
            dfs(dx,dy,cnt);
        }
    }
}

int main(){
    int T,i,j,cnt;
    scanf("%d",&T);
    while(T--){
        memset(flag,0,sizeof(flag));
        scanf("%d%d",&H,&W);
        for(i=0;i<H;i++)scanf("%s",map[i]);
        cnt=0;
        for(i=0;i<H;i++){
            for(j=0;j<W;j++){
                //(i,j)å¤æç¾ï¼å¹¶ä¸å°æªæ è®°ãä¸ä¸ªæ°çåºåã
                if(map[i][j]=='#' && flag[i][j]==0){
                    cnt++;//åºåæ°å 1
                    flag[i][j]=cnt;
                    dfs(i,j,cnt);
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}