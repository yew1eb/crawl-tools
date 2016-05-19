#include<stdio.h>
int main(void){
int n,m,i,j;
while(scanf("%d%d",&m,&n)!=EOF){
    for(i=0;i<=n+1;i++){
        for(j=0;j<=m+1;j++){
if((i==0&&j==0)||(i==n+1&&j==0)||(i==0&&j==m+1)||(i==n+1&&j==m+1))printf("+");
else if((i==0&&j!=0&&j!=m+1)||(i==n+1&&j!=0&&j!=m+1))printf("-");
else if((j==0&&i!=0&&i!=n+1)||(j==m+1&&i!=0&&i!=n+1))printf("|");
else printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}
return 0;
}