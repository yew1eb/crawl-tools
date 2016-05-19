#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=110;
int   n, t, q;
struct Node
{
    int  a, b;
}node[maxn];
int     dp[maxn*10][maxn];
bool mark[maxn*10][maxn];
int  main( )
{
    while (cin>>n>>t>>q && (n||t||q) )
    {
        for (int i=1; i<=n; i++) scanf("%d %d", &node[i].a, &node[i].b);
        node[0].a = 0; node[0].b = 1; //Õý³£µÄ¹¥»÷
        memset(dp, 0, sizeof(dp));
        dp[0][100] = 0;   //³õÊ¼»¯¿ªÊ¼×´Ì¬
        int pre;
        try
        {
           for (int i=1; (i-1)*q<100; i++)
           {
              for (int j=0; j<=100; j++) //»Ø¸´µÄmagicvalueÐ¡ÓÚµÈÓÚ100µÄÇé¿ö
              {
                   //Ñ¡ÔñÎïÀí¹¥»÷
                   pre = min(100, j+t);
                   dp[i][pre] = max(dp[i][pre], dp[i-1][j]+1);
                   if (dp[i][pre] >=100) throw i;
                   //Ñ¡Ôñskill
                   for (int k=1; k<=n; k++)
                   {
                       if (j>=node[k].a) //¿ÉÒÔ¹¥»÷
                       {
                             pre = min(100, j-node[k].a + t);
                             dp[i][pre] = max(dp[i][pre], dp[i-1][j] + node[k].b);
                             if (dp[i][pre]>=100) throw i;
                        }
                    }
              }
           }
           puts("My god");
        }catch( int ans )
        {
           cout<<ans<<endl;
        }
    }
    return 0;
}