#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#define inf 1<<30
using namespace std;
struct Node{
    int x,y;
}block[8][3],side[6][4];//è®°å½é­æ¹çå«ä¸ªç«æ¹ä½çä¸ä¸ªé¢,æ¯ä¸ªé¢ç4ä¸ªåæ 
char str[10][10];
char each_col[6];   //æ¯ä¸ªé¢çé¢è²ï¼åå«ä¸ºä¸ï¼å·¦ï¼åï¼å³ï¼åï¼ä¸
bool flag;
int ans[100];
int depth;
void Init(){   //è·å¾æ¯ä¸ªç«æ¹ä½çæ¯ä¸ªé¢åæ ,ä»¥åé­æ¹æ¯ä¸ªé¢åä¸ªç¹çåæ 
    block[0][0].x=3;block[0][0].y=2;block[0][1].x=3;block[0][1].y=1;block[0][2].x=4;block[0][2].y=2;
    block[1][0].x=3;block[1][0].y=3;block[1][1].x=3;block[1][1].y=4;block[1][2].x=4;block[1][2].y=3;
    block[2][0].x=2;block[2][0].y=2;block[2][1].x=2;block[2][1].y=1;block[2][2].x=1;block[2][2].y=2;
    block[3][0].x=2;block[3][0].y=3;block[3][1].x=1;block[3][1].y=3;block[3][2].x=2;block[3][2].y=4;
    block[4][0].x=3;block[4][0].y=0;block[4][1].x=5;block[4][1].y=2;block[4][2].x=3;block[4][2].y=7;
    block[5][0].x=5;block[5][0].y=3;block[5][1].x=3;block[5][1].y=5;block[5][2].x=3;block[5][2].y=6;
    block[6][0].x=0;block[6][0].y=2;block[6][1].x=2;block[6][1].y=7;block[6][2].x=2;block[6][2].y=0;
    block[7][0].x=0;block[7][0].y=3;block[7][1].x=2;block[7][1].y=5;block[7][2].x=2;block[7][2].y=6;
    side[0][0].x=0;side[0][0].y=2;side[0][1].x=0;side[0][1].y=3;side[0][2].x=1;side[0][2].y=2;side[0][3].x=1;side[0][3].y=3;
    side[1][0].x=2;side[1][0].y=0;side[1][1].x=2;side[1][1].y=1;side[1][2].x=3;side[1][2].y=0;side[1][3].x=3;side[1][3].y=1;
    side[2][0].x=2;side[2][0].y=2;side[2][1].x=2;side[2][1].y=3;side[2][2].x=3;side[2][2].y=2;side[2][3].x=3;side[2][3].y=3;
    side[3][0].x=2;side[3][0].y=4;side[3][1].x=2;side[3][1].y=5;side[3][2].x=3;side[3][2].y=4;side[3][3].x=3;side[3][3].y=5;
    side[4][0].x=2;side[4][0].y=6;side[4][1].x=2;side[4][1].y=7;side[4][2].x=3;side[4][2].y=6;side[4][3].x=3;side[4][3].y=7;
    side[5][0].x=4;side[5][0].y=2;side[5][1].x=4;side[5][1].y=3;side[5][2].x=5;side[5][2].y=2;side[5][3].x=5;side[5][3].y=3;
}
char get_color(int A,int B,int C){  //è·å¾æ¯ä¸ªé¢çé¢è²ï¼éè¿å¶ä¸­ç3ä¸ªé¢
    for(int i=0;i<8;i++){
        if(str[block[i][0].x][block[i][0].y]==each_col[A]&&str[block[i][1].x][block[i][1].y]==each_col[B]&&str[block[i][2].x][block[i][2].y]!=each_col[C])
            return str[block[i][2].x][block[i][2].y];
        if(str[block[i][1].x][block[i][1].y]==each_col[A]&&str[block[i][0].x][block[i][0].y]==each_col[B]&&str[block[i][2].x][block[i][2].y]!=each_col[C])
            return str[block[i][2].x][block[i][2].y];
        if(str[block[i][0].x][block[i][0].y]==each_col[A]&&str[block[i][2].x][block[i][2].y]==each_col[B]&&str[block[i][1].x][block[i][1].y]!=each_col[C])
            return str[block[i][1].x][block[i][1].y];
        if(str[block[i][2].x][block[i][2].y]==each_col[A]&&str[block[i][0].x][block[i][0].y]==each_col[B]&&str[block[i][1].x][block[i][1].y]!=each_col[C])
            return str[block[i][1].x][block[i][1].y];
        if(str[block[i][1].x][block[i][1].y]==each_col[A]&&str[block[i][2].x][block[i][2].y]==each_col[B]&&str[block[i][0].x][block[i][0].y]!=each_col[C])
            return str[block[i][0].x][block[i][0].y];
        if(str[block[i][2].x][block[i][2].y]==each_col[A]&&str[block[i][1].x][block[i][1].y]==each_col[B]&&str[block[i][0].x][block[i][0].y]!=each_col[C])
            return str[block[i][0].x][block[i][0].y];
    }
}
void change_x(char maze[10][10]){   //xè½´æè½¬
    char tmp;
    tmp=maze[2][4];maze[2][4]=maze[2][5];maze[2][5]=maze[3][5];maze[3][5]=maze[3][4];maze[3][4]=tmp;
    tmp=maze[1][3];maze[1][3]=maze[2][6];maze[2][6]=maze[5][3];maze[5][3]=maze[3][3];maze[3][3]=tmp;
    tmp=maze[0][3];maze[0][3]=maze[3][6];maze[3][6]=maze[4][3];maze[4][3]=maze[2][3];maze[2][3]=tmp;
}
void change_y(char maze[10][10]){   //yè½´æè½¬
    char tmp;
    tmp=maze[2][0]; maze[2][0]=maze[2][6];maze[2][6]=maze[2][4]; maze[2][4]=maze[2][2]; maze[2][2]=tmp;
    tmp=maze[2][1]; maze[2][1]=maze[2][7];maze[2][7]=maze[2][5]; maze[2][5]=maze[2][3]; maze[2][3]=tmp;
    tmp=maze[0][2]; maze[0][2]=maze[0][3];maze[0][3]=maze[1][3]; maze[1][3]=maze[1][2]; maze[1][2]=tmp;
}
void change_z(char maze[10][10]){   //zè½´æè½¬
    char tmp;
    tmp=maze[2][1]; maze[2][1]=maze[1][3];maze[1][3]=maze[3][4]; maze[3][4]=maze[4][2]; maze[4][2]=tmp;
    tmp=maze[3][1]; maze[3][1]=maze[1][2];maze[1][2]=maze[2][4]; maze[2][4]=maze[4][3]; maze[4][3]=tmp;
    tmp=maze[2][2]; maze[2][2]=maze[2][3];maze[2][3]=maze[3][3]; maze[3][3]=maze[3][2]; maze[3][2]=tmp;
}
int get_h(char maze[10][10]){  
    int ret=0;
    for(int i=0;i<6;i++){
        for(int j=0;j<4;j++)
            if(maze[side[i][j].x][side[i][j].y]!=each_col[i])
                ret++;
    }
    return (ret+7)/8;
};
void IDAstar(char maze[10][10],int tmp_depth){
    if(flag)
        return;
    if(get_h(maze)>tmp_depth)
        return;
    if(tmp_depth==0){
        flag=true;
        return;
    }
    for(int i=0;i<3;i++){
        if(flag)
            return;
        char temp[10][10];
        for(int i=0;i<6;i++)
            for(int j=0;j<8;j++)
                temp[i][j]=maze[i][j];
        if(i==0)
            change_x(temp);
        else if(i==1)
            change_y(temp);
        else 
            change_z(temp);
        ans[tmp_depth]=i;
        IDAstar(temp,tmp_depth-1);
    }
}
int main(){
    Init();
    while(scanf("%s",str[0])!=EOF){
        for(int i=1;i<6;i++)
            scanf("%s",str[i]);
        if(strcmp(str[2],"........")==0)
            break;
        each_col[1]=str[3][0];each_col[5]=str[5][2];each_col[4]=str[3][7];//å¶ä¸­æä¸ä¸ªæ¹åä¸ç´æ²¡æå¨ï¼å¯ä»¥ç¡®å®æç»ç»æç3ä¸ªé¢çé¢è²
        each_col[0]=get_color(1,4,5);
        each_col[2]=get_color(1,5,4);
        each_col[3]=get_color(4,5,1);
        flag=false;
        for(depth=get_h(str);;depth++){
            IDAstar(str,depth);
            if(flag){
                for(int i=depth;i>0;i--)
                    printf("%c",ans[i]+'X');
                printf("\n");
                break;
            }
        }
    }
    return 0;
}