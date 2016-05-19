/*
é¢æï¼ç»ä½ ä¸äºå°å²ãå¬å±æµ·ååæµ®å°ï¼å°å²å¯ä»¥éå¼ä¸¤ä¸ªå¬å±æµ·åï¼æµ®å°æ å½±å
æ±éå°½å¯è½å¤çéä¸äºå¬å±æµ·åç¹æ¯è¡æ¯åä»è½éä¸ä¸ªã
éå¶æ¡ä»¶ï¼å°å±±å¯ä»¥éå¼è¿ä¸ªéå¶æ¡ä»¶ãå³*#*å¯ä»¥éä¸¤ä¸ª
é¢å¤çï¼
*****
**#*#
*****   å¯ä»¥æè¡è½¬å  

*****
**#oo
ooo*#
*****

æè¡è½¬åçåºç¡ä¸æåè½¬å
***o**o
**ooooo
oooo*oo
**o**o*
å ä¸ºæ¯è¡æ¯åé¡¶å¤å¯ä»¥å¢å 50
æä»¥æ»å±æå¤2500*2500çç©éµ
ç¶åç´æ¥äºåå¹éå³å¯
*/
#include<stdio.h>
#include<string.h>
#define N  2800
int ma[N][N];
char s[60][60];
int ans[N][N];
int n,m,addx,addy;
void slovex() {//æè¡è½¬å
  int i,k;
  addx=0;
for(i=1;i<=n;i++) {
addx++;
 //printf("%d\n",addx);
 k=1;
while(1) {
    for(;s[i][k]!='#'&&k<=m;k++) {
      if(s[i][k]=='*')
       ans[addx][k]=1;
    }
    if(k==m)//æåä¸ä¸ªä¹è¦ç®è¿å»ï¼åå¼å§è¿ééäºä¸ç´æ²¡çåºæ¥éè¦*****
        ans[addx][k]=2;
    if(k==m+1||k==m)
        break;
    ans[addx][k]=2;
    k++;
    addx++;
}
}
return ;
}
void slovey() {//å¨æè¡è½¬åçåºç¡ä¸æåè½¬å
 int i,k;
 addy=0;
 for(i=1;i<=m;i++) {
    addy++;
    k=1;
 //   printf("%d\n",addy);
    while(1) {
        for(;ans[k][i]!=2&&k<=addx;k++) {
            if(ans[k][i]==1)
                ma[k][addy]=1;
        }
        if(k==addx+1||k==addx)
            break;
            k++;
        addy++;
    }
 }
 return;
}
int vis[N],link[N];
int findd(int u) {
int i;
for(i=1;i<=addy;i++)
if(ma[u][i]&&vis[i]==0) {
vis[i]=1;
if(link[i]==-1||findd(link[i])) {
link[i]=u;
return 1;
}
}
return 0;
}
int main() {
    int t,i,sum,j;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        memset(ma,0,sizeof(ma));
        memset(ans,0,sizeof(ans));
        for(i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        slovex();
       /*     for(i=1;i<=addx;i++) {
                for(j=1;j<=m;j++)
            printf("%d ",ans[i][j]);
            printf("\n");
        }*/
        slovey();
      /*   for(i=1;i<=addx;i++) {
                for(j=1;j<=addy;j++)
            printf("%d ",ma[i][j]);
            printf("\n");
        }*/
        memset(link,-1,sizeof(link));
        sum=0;
        for(i=1;i<=addx;i++) {//ç´æ¥å¥æ¨¡æ¿äºåå¹éå³å¯
            memset(vis,0,sizeof(vis));
            sum+=findd(i);
        }
    printf("%d\n",sum);
    }
return 0;}