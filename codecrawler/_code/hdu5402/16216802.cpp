#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 105;
const int  INF = (1 << 30);
int mat[maxn][maxn];
int n,m,sum,minv,posx,posy;
void special_solve(){
    printf("%d\n",sum - minv);
    if(!(posx & 1)){
        for(int i = 0; i < posx; i++){
            char c = i & 1 ? 'L' : 'R';
            for(int j = 1; j < m; j++)
                printf("%c",c);
            printf("D");
        }
        int base = 0;
        for(int i = 0; i < m; i++){
            char c = (i + base) & 1 ? 'U' : 'D';
            if(i != posy)
                printf("%c",c);
            else
                base ++;
            if(i < m - 1)
                printf("R");
        }
        for(int i = posx + 2; i < n; i++){
            printf("D");
            char c = i & 1 ? 'R' : 'L';
            for(int j = 1; j < m; j++)
                printf("%c",c);
        }
    }
    else{
        for(int i = 0; i < posx - 1; i++){
            char c = i & 1 ? 'L' : 'R';
            for(int j = 1; j < m; j++)
                printf("%c",c);
            printf("D");
        }
        int base = 0;
        for(int i = 0; i < m; i++){
            char c = (i + base) & 1 ? 'U' : 'D';
            if(i != posy)
                printf("%c",c);
            else
                base ++;
            if(i < m - 1)
                printf("R");
        }
        for(int i = posx + 1; i < n; i++){
            printf("D");
            char c = i & 1 ? 'R' : 'L';
            for(int j = 1; j < m; j++)
                printf("%c",c);
        }
    }
}
int main(){
    while(scanf("%d%d",&n,&m) != EOF){
        sum = 0;
        minv = INF;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                scanf("%d",&mat[i][j]);
                sum += mat[i][j];
                if((i + j) & 1){
                    if(minv > mat[i][j]){
                        posx = i;
                        posy = j;
                        minv = mat[i][j];
                    }
                }
            }
        if(n & 1){
            printf("%d\n",sum);
            for(int i = 0; i < n; i++){
                char c = i & 1 ? 'L' : 'R';
                for(int j = 1; j < m; j++)
                    printf("%c",c);
                if(i != n - 1)
                    printf("D");
            }
        }
        else if(m & 1){
            printf("%d\n",sum);
            for(int i = 0; i < m; i++){
                char c = i & 1 ? 'U' : 'D';
                for(int j = 1; j < n; j++)
                    printf("%c",c);
                if(i != m - 1)
                    printf("R");
            }
        }
        else
            special_solve();
        puts("");
    }
    return 0;
}
