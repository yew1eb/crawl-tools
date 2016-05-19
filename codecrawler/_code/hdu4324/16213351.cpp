#include<iostream>
#include<cstdio>
using namespace std;
#define N 2010
int indegree[N],a[N][N];
char b[N];
int main(){
//    freopen("in.txt","r",stdin);
    int n,t,x,p=1;
    scanf("%d",&t);
        while(t--){
            int sign1=0;
            scanf("%d",&n);
            for(int i=0;i<=n;i++){
                indegree[i]=0;
            }
            for(int i=1;i<=n;i++){
                scanf("%s",b);
                for(int j=0;j<n;j++){
                    a[i][j+1]=b[j]-'0';
                    if(a[i][j+1]==1)
                    indegree[j+1]++;//å¥åº¦æ°ç»
                }
            }
            printf("Case #%d: ",p++);
            for(int i=1;i<=n;i++){
                int temp;
                int sign=0;
                for(int j=1;j<=n;j++){
                    if(indegree[j]==0){
                        temp=j;
                        indegree[j]=-1;
                        sign=1;
                        break;
                    }
                }
                if(sign==0){//å¦ææ²¡ææ¾å°å®ç¹ï¼é£ä¸å®æç¯äº
                    printf("Yes\n");
                    sign1=1;
                    break;
                }
                else{
                    for(int j=1;j<=n;j++){
                        if(a[temp][j]&&temp!=j)
                            indegree[j]--;
                    }
                }
            }
            if(sign1==0){
                printf("No\n");
            }
        }
    return 0;
}
