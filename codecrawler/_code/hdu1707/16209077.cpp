#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node
{
    char na[21];
    int a[10][15];
}s[205];
struct pp
{
    char ans[21];
}w[205];
bool cmp(pp a,pp b){
    return strcmp(a.ans,b.ans)<0;
}
int main(){
    int n,t,i,j,k,d,b,e,q,flag;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s%d",s[i].na,&k);
            memset(s[i].a,0,sizeof(s[i].a));
            for(j=0;j<k;j++){
                scanf("%d%d%d",&d,&b,&e);
                while(b<=e){
                    s[i].a[d][b]=1;
                    b++;
                }
            }
        }
        scanf("%d",&q);
        while(q--){
            scanf("%d%d%d",&d,&b,&e);
            j=0;    
            for(i=0;i<n;i++){
                k=b;
                flag=0;
                while(k<=e){
                    if(s[i].a[d][k]){
                        flag=1;
                        break;
                    }
                    k++;
                }
                if(flag){
                    strcpy(w[j].ans,s[i].na);
                    j++;
                }
            }
            if(!j)
                printf("None");
            else{
                sort(w,w+j,cmp);
                for(i=0;i<j;i++){
                    if(i)
                        printf(" ");
                    printf("%s",w[i].ans);
                }
            }
            printf("\n");
        }
    }
    return 0;
}