#include <cstdio>
#define MAX 8
using namespace std;
char map[7][MAX];
char s[11][MAX];
int n,flag,total;
struct node{
    int i,j;
    int run;
}road[11];
bool judge(int curi,int curj,int x)              //判断是否可推函数，长了Debug好痛苦。。。
{
    int i;
    if(x==1){
        if(curi-1<0||(map[curi-1][curj]=='O'))
        return 0;
        for(i=2;curi-i>=0;i++)
        if(map[curi-i][curj]=='O')
        return 1;
    }else if(x==2){
        if(curj-1<0||(map[curi][curj-1]=='O'))
        return 0;
        for(i=2;curj-i>=0;i++)
        if(map[curi][curj-i]=='O')
        return 1;
    }else if(x==3){
        if(curj+1>=8||(map[curi][curj+1]=='O'))
        return 0;
        for(i=2;curj+i<8;i++)
        if(map[curi][curj+i]=='O')
        return 1;
    }else if(x==4){
        if(curi+1>=7||(map[curi+1][curj]=='O'))
        return 0;
        for(i=2;curi+i<7;i++)
        if(map[curi+i][curj]=='O')
        return 1;
    }
    return 0;
}
void dfs(){
    int i,j,k,l,l2;
    if(total==n){
        for(i=1;i<total;i++){
            printf("%d %d ",road[i].i,road[i].j);
            if(road[i].run==1)
            printf("U\n");
            else if(road[i].run==2)
            printf("L\n");
            else if(road[i].run==3)
            printf("R\n");
            else if(road[i].run==4)
            printf("D\n");
        }
        flag=1;
        return ;
    }
    for(i=0;i<7;i++){
        for(j=0;j<8;j++){
            if(map[i][j]=='O'){
                for(k=1;k<=4;k++){
                    if(!judge(i,j,k))continue;
                    road[total].i=i;
                    road[total].j=j;
                    road[total].run=k;
                    if(k==1||k==4){
                        for(l=0;l<7;l++){
                            s[total][l]=map[l][j];            //该列改变了，记录该列。
                        }
                    }
                    else{
                        for(l=0;l<8;l++){
                            s[total][l]=map[i][l];           //该行改变了，记录该行。
                        }
                    }
                    map[i][j]='X';
                    if(k==1){                                //分类讨论推动方向
                        l2=i;
                        for(l=i-1;l>=0;l--){
                            if(map[l][j]=='O'){
                                map[l+1][j]='O';
                                if(l2!=l+1){
                                    map[l2][j]='X';
                                }
                                l2=l;
                            }
                        }
                        map[l2][j]='X';
                    }else if(k==2){
                        l2=j;
                        for(l=j-1;l>=0;l--){
                            if(map[i][l]=='O'){
                                map[i][l+1]='O';
                                if(l2!=l+1){
                                    map[i][l2]='X';
                                }
                                l2=l;
                            }
                        }
                        map[i][l2]='X';
                    }else if(k==3){
                        l2=j;
                        for(l=j+1;l<8;l++){
                            if(map[i][l]=='O'){
                                map[i][l-1]='O';
                                if(l-1!=l2){
                                    map[i][l2]='X';
                                }
                                l2=l;
                            }
                        }
                        map[i][l2]='X';
                    }else if(k==4){
                        l2=i;
                        for(l=i+1;l<7;l++){
                            if(map[l][j]=='O'){
                                map[l-1][j]='O';
                                if(l-1!=l2){
                                    map[l2][j]='X';
                                }
                                l2=l;
                            }
                        }
                        map[l2][j]='X';
                    }
                    total++;
                    dfs();
                    if(flag)return ;
                    total--;
                    if(k==1||k==4){                         //进行回溯。
                        for(l=0;l<7;l++){
                                map[l][j]=s[total][l];
                            }
                    }
                    else{
                        for(l=0;l<8;l++){
                            map[i][l]=s[total][l];
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    int casi=0;
    int i,j;
    while(scanf("%s",s[0])!=EOF){
            if(casi)printf("\n");
            n=0;
            for(i=0;i<8;i++){
                map[0][i]=s[0][i];
                if(map[0][i]=='O')
                n++;
            }
            for(i=1;i<7;i++){
                scanf("%s",s[0]);
                for(j=0;j<8;j++){
                    map[i][j]=s[0][j];
                    if(map[i][j]=='O')
                    n++;
                }
            }
            flag=0;
            total=1;
            printf("CASE #%d:\n",++casi);
            dfs();
    }
    return 0;
}