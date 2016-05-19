#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define inf 1<<20
const int N=300;
int map[N][N];
void init(){
    map['A']['A']=5;
    map['C']['A']=map['A']['C']=-1;
    map['C']['C']=5;map['A']['G']=map['G']['A']=-2;
    map['A']['T']=map['T']['A']=-1;map['C']['G']=map['G']['C']=-3;
    map['A']['-']=map['-']['A']=-3;map['C']['T']=map['T']['C']=-2;map['G']['G']=5;
    map['C']['-']=map['-']['C']=-4;map['T']['G']=map['G']['T']=-2;
    map['G']['-']=map['-']['G']=-2;map['T']['T']=5;map['T']['-']=map['-']['T']=-1;
}
const int L=105;
char s1[L],s2[L];
int dp[L][L];
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int l1,l2;
        scanf("%d %s",&l1,s1+1);
        scanf("%d %s",&l2,s2+1);
        for(int i=0;i<=l1;i++)
            for(int j=0;j<=l2;j++)
                dp[i][j]=-inf;
        dp[0][0]=0;
        for(int i=1;i<=l1;i++) dp[i][0]=dp[i-1][0]+map[s1[i]]['-'];
        for(int j=1;j<=l2;j++) dp[0][j]=dp[0][j-1]+map[s2[j]]['-'];
        for(int i=1;i<=l1;i++)
            for(int j=1;j<=l2;j++){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+map[s1[i]][s2[j]]);
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+map[s1[i]]['-']);
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+map[s2[j]]['-']);
            }
        printf("%d\n",dp[l1][l2]);
    }
    return 0;
}
