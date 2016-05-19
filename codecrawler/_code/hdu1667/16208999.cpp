#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int map[10][10];
bool check(){
    if(map[3][3]!=map[3][4]) return false; if(map[3][3]!=map[3][5]) return false;
    if(map[3][3]!=map[4][3]) return false; if(map[3][3]!=map[4][5]) return false;
    if(map[3][3]!=map[5][3]) return false; if(map[3][3]!=map[5][4]) return false;
    if(map[3][3]!=map[5][5]) return false;
    return true;
}

void moveA(){
    int tmp=map[1][3];
    for(int i=1;i<=6;i++) map[i][3]=map[i+1][3];
     map[7][3]=tmp;
}
void moveB(){
    int tmp=map[1][5];
    for(int i=1;i<=6;i++) map[i][5]=map[i+1][5];
     map[7][5]=tmp;
}

void moveC(){
    int tmp=map[3][7];
    for(int i=7;i>=2;i--) map[3][i]=map[3][i-1];
    map[3][1]=tmp;
}
void moveD(){
    int tmp=map[5][7];
    for(int i=7;i>=2;i--) map[5][i]=map[5][i-1];
    map[5][1]=tmp;
}

void moveE(){
   int tmp=map[7][5];
   for(int i=7;i>=2;i--) map[i][5]=map[i-1][5];
    map[1][5]=tmp;
}
void moveF(){
   int tmp=map[7][3];
   for(int i=7;i>=2;i--) map[i][3]=map[i-1][3];
   map[1][3]=tmp;
}

 void moveG(){
   int tmp=map[5][1];
   for(int i=1;i<=6;i++) map[5][i]=map[5][i+1];
   map[5][7]=tmp;
}

 void moveH(){
   int tmp=map[3][1];
   for(int i=1;i<=6;i++) map[3][i]=map[3][i+1];
   map[3][7]=tmp;
}
int smallest_deep(){                                     //è¯ä¼°å½æ°
    int cnt[4]={0};
    for(int i=3;i<=5;i++){
         cnt[map[3][i]]++;
         cnt[map[5][i]]++;
     }

     cnt[map[4][3]]++;
     cnt[map[4][5]]++;

     int max=0;
     for(int i=1;i<=3;i++){
         if(max<cnt[i]) max=cnt[i];
    }
    return 8-max;

}
int deep;
char ans[1000];
bool dfs(int cur_deep){
    if(cur_deep==deep) return check();

    if(cur_deep+smallest_deep()>deep) return false;

    moveA();  ans[cur_deep]='A';   if(dfs(cur_deep+1)) return true; moveF();

    moveB();  ans[cur_deep]='B';   if(dfs(cur_deep+1)) return true; moveE();

    moveC();  ans[cur_deep]='C';   if(dfs(cur_deep+1)) return true; moveH();

    moveD();  ans[cur_deep]='D';   if(dfs(cur_deep+1)) return true; moveG();

    moveE();  ans[cur_deep]='E';   if(dfs(cur_deep+1)) return true; moveB();

    moveF();  ans[cur_deep]='F';   if(dfs(cur_deep+1)) return true; moveA();

    moveG();  ans[cur_deep]='G';   if(dfs(cur_deep+1)) return true; moveD();

    moveH();  ans[cur_deep]='H';   if(dfs(cur_deep+1)) return true; moveC();

    return false;
}
int main(){
    for(int i=1;i<=7;i++)  map[3][i]=map[5][i]=1;

    for(int i=1;i<=7;i++)  map[i][3]=map[i][5]=1;

    while(true){
        for(int i=1;i<=7;i++) for(int j=1;j<=7;j++){
             if(map[i][j]==0)  continue;
             scanf("%d",&map[i][j]);
             if(map[i][j]==0)  return 0;
        }
        if(check()){
            printf("No moves needed\n");
             printf("%d\n",map[3][3]);
            continue;
        }
        deep=1;

        while(true){
            if(dfs(0)) break;
            deep++;
        }
        ans[deep]='\0';
        cout<<ans<<endl;
        cout<<map[3][3]<<endl;
    }
    return 0;
}
