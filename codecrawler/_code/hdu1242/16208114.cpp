#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>


const int MAX = 202;

char map[MAX][MAX];
int visit[MAX][MAX];
int n,m,ax,ay,minx;

void dfs(int x,int y,int len){
    if(x<0 || y<0 || x>=n || y>=m)return;
    if(len>=minx)return;
    if(map[x][y]=='#')return;
    if(visit[x][y]==1)return;
    if(map[x][y]=='r'){
        if(len<minx)minx=len;
        return;
    }
    if(map[x][y]=='x'){
        ++len;
    }
    visit[x][y]=1;
    dfs(x+1,y,len+1);
    dfs(x-1,y,len+1);
    dfs(x,y+1,len+1);
    dfs(x,y-1,len+1);
    visit[x][y]=0;
}

int main(){

    //freopen("in.txt","r",stdin);
    int i,j,len;
    while(scanf("%d %d%*c",&n,&m)!=EOF){
        for(i=0;i<n;++i){
            for(j=0;j<m;++j){
                map[i][j]=getchar();
                if(map[i][j]=='a'){
                    ax = i;
                    ay = j;
                }
            }
            getchar();
        }
        len = 0;
        minx = INT_MAX;
        dfs(ax,ay,len);
        if(minx!=INT_MAX){
            printf("%d\n",minx);
        }else{
            printf("Poor ANGEL has to stay in the prison all his life.\n");
        }
        
    }
    
    return 0;
}
