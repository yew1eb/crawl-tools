#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 1000010 ;
int a[maxn],b[maxn];
int n,k;
int solve(int n)
{
    int i=0,j=0;
    a[0]=1,b[0]=1;
    while(a[i]<n)
    { // a[i]è¡¨ç¤ºå½åè½ç¨æ¥æé çæå¤§é¡¹
      // b[i]è¡¨ç¤ºç±0...i,ç±aä¸­æ°åæææçæå¤§å¼
        i++;
        a[i]=b[i-1]+1; // b[i-1]+1ä¸è½è¡¨ç¤ºæaä¸­çåi-1ä¸­æä¸è¿ç»­å é¡¹çåï¼æéè¦æé 
        while(a[j+1]*k<a[i])
            j++; // æ¾å°æè¿çæ°å¥½ä¸ç¬¬ié¡¹å·®å¼å¨kåä»¥ä¸ç
        if(a[j]*k<a[i])
            b[i]=b[j]+a[i]; //ç¨å°äºaä¸­åi-2é¡¹ï¼ä¿è¯åä¸ºaä¸­æä¸è¿ç»­çè¯ï¼å¯ä»¥åå½åçj
        else // åæ°ç¬¬äºé¡¹åæåä¸é¡¹å·®å¼æ°å¥½ä¸ºkåæ¶ï¼è½æé çæå¤§é¡¹ä¸å
            b[i]=a[i];
    }
    if(n==a[i])
        return -1;
    int ans;
   while(n)
   {
       if(n>=a[i])
            n-=a[i],ans=a[i];
       i--;
   }
   return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&n,&k);
        int ans = solve(n);
        printf("Case %d: ",cas);
        if(ans==-1)
            printf("lose\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
