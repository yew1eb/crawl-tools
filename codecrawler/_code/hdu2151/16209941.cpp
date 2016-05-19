#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int step[110][110];
int main()
{
    int N,P,M,T;
    while(scanf("%d%d%d%d",&N,&P,&M,&T)!=EOF){
        memset(step,0,sizeof(step));
            step[0][P]=1;
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++){
                if(step[i-1][j+1]!=0&&j+1<=N) step[i][j]+=step[i-1][j+1];
                if(step[i-1][j-1]!=0&&j-1>=1) step[i][j]+=step[i-1][j-1];

            }
        }
//        for(int i=1;i<=M;i++){
//            for(int j=1;j<=N;j++){
//                    printf("%d ",step[i][j]);
//            }
//            printf("\n");
//        }
        printf("%d\n",step[M][T]);
    }
    return 0;
}
