#include <stdio.h>
#include <string.h>

int a[30][30];
int temp[10005];
bool vis[10005];

int main(void){
    int i,j,n,k,mark;
    for(i='A';i<='Z';i++){
        for(j='A';j<='Z';j++){
            a[i-'A'][j-'A'] = i ^ j;
        }
    }
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++){
            scanf("%d",temp+i);
        }
        mark = 1;
        for(i=0;i<26;i++){
            memset(vis,0,sizeof(vis));
            for(j=0;j<26;j++){
                for(k=0;k<n;k++){
                    if(temp[k]==a[i][j])
                        vis[k] = 1;
                }
            }
            for(k=0;k<n;k++){
                if(vis[k]==0){mark = 0;break;}
            }
            if(mark==0){mark=1;continue;}
            else break;
        }
        for(k=0;k<n;k++){
            for(j=0;j<26;j++)
            {
                if(a[i][j]==temp[k])
                    printf("%c",j+'A');
            }
        }
        puts("");
    }
    return 0;
}
