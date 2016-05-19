#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;
char map_[MAX][MAX];
int pos[MAX*9][2];//å­å¨æ¯é®å·ç¹çåæ ï¼æ¹ä¾¿æç´¢æ¶åªéè¦æç´¢è¿äºç¹å¡«ä»ä¹æ°å­.
bool row[MAX][MAX],list[MAX][MAX];//ç¨æ¥æ æåªè¡åªååºç°è¿ä»ä¹æ°.
int k;

bool check(int v,int num){
    int n=pos[v][0]/3*3;//æç´¢å¨å´9å°æ ¼çè¡çå¼å§æç´¢ä½ç½®.
    int m=pos[v][1]/3*3;//æç´¢å¨å´9å°æ ¼çåçå¼å§æç´¢ä½ç½®.
    for(int i=n;i<n+3;++i){
        for(int j=m;j<m+3;++j){
            if(map_[i][j] == num+'0')return false;
        }
    }
    return true;
}

bool DFS(int v){
    if(v == k){return true;}//ä»£è¡¨åé¢å·²ç»æææçç¹é½æç´¢å®äº.
    for(int i=1;i<10;++i){
        if(!row[pos[v][0]][i] && !list[pos[v][1]][i] && check(v,i)){
            map_[pos[v][0]][pos[v][1]]=i+'0';
            row[pos[v][0]][i]=true;
            list[pos[v][1]][i]=true;
            if(DFS(v+1)){return true;}
            map_[pos[v][0]][pos[v][1]]='?';
            row[pos[v][0]][i]=false;
            list[pos[v][1]][i]=false;
        }
    }
    return false;
}

void output(){
    for(int i=0;i<9;++i){
        cout<<map_[i][0];
        for(int j=1;j<9;++j){
            cout<<' '<<map_[i][j];
        }
        cout<<endl;
    }
    return;
}

int main(){
 int num=0;
    while(1){
     k=0;
     memset(row,false,sizeof row);
     memset(list,false,sizeof list);
     for(int i=0;i<9;++i){
          for(int j=0;j<9;++j){
              if(!(cin>>map_[i][j]))exit(0);
              if(map_[i][j] == '?'){pos[k][0]=i;pos[k++][1]=j;continue;}
              row[i][map_[i][j]-'0']=true;
              list[j][map_[i][j]-'0']=true;
            }
        }
     DFS(0);//å¼å§æç´¢ç¬¬1ä¸ªæ¯é®å·çç¹.
     if(num++)cout<<endl;
     output();
    }
    return 0;
} 