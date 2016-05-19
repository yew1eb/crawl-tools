#include <iostream>
#include <algorithm>
using namespace std;

int const nMax = 500005;
int stone[nMax];
int L, n, m;

bool success(int jump)
{
    if(jump * m < L) 
        return false;
 
    int i, j, cnt;
    i = cnt = 0; 
    for(j = 1; j <= n+1; j++)
        if(stone[j] - stone[i] > jump)
            if(j == i + 1) return false;
            else { i = --j; //è´ªå¿ï¼è®©æ¯ä¸æ¬¡è·³å¾å°½å¯è½è¿ï¼ç±äºä¸ºä¸ä¸æ¬¡å¾ªç¯ååå¤æ¶è¦æ§è¡å¾ªç¯æ¡ä»¶çç¬¬ä¸é¨åj++ï¼æä»¥æ­¤å¤å--jã
  cnt++; }

    if((++cnt) > m)  //è·³è¿æ²³çæåä¸æ­¥æ²¡æè®°å½ï¼æä»¥cntè¦èªå¢1ã
        return false;
    return true;
}

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    int l, r, mid;

    while(scanf("%d%d%d", &L, &n, &m) != EOF)
    {
        stone[0] = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &stone[i]);
        stone[n+1] = L;
  
        sort(stone+1, stone+n+1, cmp);
        
        l = 0; r = L;
        while(l <= r)
        {
            mid = (l + r) / 2;
            
            if(success(mid))
                r = mid - 1;
            else l = mid + 1;
        }
        printf("%d\n", l); 
    }
    return 0;
}