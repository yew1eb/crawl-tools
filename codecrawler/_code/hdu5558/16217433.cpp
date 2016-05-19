#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//åç¼æ°ç»æ¨¡æ¿
/*
æ ·ä¾ä½¿ç¨:
è¥åå­ç¬¦ä¸²ä¸º"abc"
år = {1, 2, 3, 0};
n = 3;
GetSa(r, sa, n+1, m);
GetHeight(r, rank, height, n);
å¶ä¸­
rä¸ºå­ç¬¦ä¸²è½¬åæçæ°ç»ï¼æ«å°¾åæ·»ä¸ä¸ª0
nä¸ºå­ç¬¦ä¸²çé¿åº¦
sa[i]è¡¨ç¤ºæåå¨içåç¼ä¸æ ,iä»1å¼å§ï¼æ»¡è¶³Suffix(sa[i]) < Suffix(sa[i+1])
rank[i]è¡¨ç¤ºSuffix(i)çæåï¼ä¸ºsaçé
height[i]è¡¨ç¤ºsa[i]åsa[i-1]çæé¿å¬å±åç¼
*/
struct SuffixArray
{
    enum {MAXN = 100010};
    int wa[MAXN], wb[MAXN], wsf[MAXN], wv[MAXN];

    int Cmp(int *r, int a, int b, int k)
    {
        return r[a] == r[b] && r[a+k] == r[b+k];
    }

    void GetSa(int *r, int *sa, int n, int m)
    {
        int i, j, p, *x = wa, *y = wb, *t;
        for (i = 0; i < m; i++)  
            wsf[i] = 0;
        for (i = 0; i < n; i++)  
            wsf[x[i]=r[i]]++;
        for (i = 1; i < m; i++)  
            wsf[i] += wsf[i-1];
        for (i = n - 1; i >= 0; i--)  
            sa[--wsf[x[i]]] = i;
        p = j = 1;
        for (; p < n; j *= 2, m = p)
        {
            for (p = 0, i = n - j; i < n; i++)  y[p++] = i;
            for (i = 0; i < n; i++)  
                if(sa[i] >= j)  y[p++] = sa[i] - j;
            for (i = 0; i < n; i++)  
                wv[i] = x[y[i]];
            for (i = 0; i < m; i++)  
                wsf[i] = 0;
            for (i = 0; i < n; i++)  
                wsf[wv[i]]++;
            for (i = 1; i < m; i++)  
                wsf[i] += wsf[i-1];
            for (i = n - 1; i >= 0; i--)  
                sa[--wsf[wv[i]]] = y[i];
            swap(x, y);
            x[sa[0]] = 0;
            for (p = 1, i = 1; i < n; i++)
                x[sa[i]] = Cmp(y, sa[i-1], sa[i], j) ? p - 1 : p++;
        }
    }

    void GetHeight(int *r, int *sa, int *rank, int *height, int n)
    {
        int i, j, k = 0;
        for (i = 1; i <= n; i++)  
            rank[sa[i]] = i;
        for (i = 0; i < n; i++)
        {
            if (k) k--;
            else k=0;
            j = sa[rank[i]-1];
            while (r[i+k] == r[j+k]) k++;
            height[rank[i]] = k;
        }
    }
}suffixArray;

const int MAXN = 100010;
const int STSIZE = 18;
char s[MAXN];
int r[MAXN], sa[MAXN], rnk[MAXN], height[MAXN], pre[MAXN], nxt[MAXN];

int main()
{
    int T; scanf("%d", &T);
    for (int kk = 1; kk <= T; kk++)
    {
        //input
        scanf("%s", s);
        
        //initialize
        int n = 0;
        for (int i = 0; s[i] != '\0'; i++)
            r[n++] = s[i] - 'a' + 1;
        r[n] = 0;
        
        //get sa & rank & height
        suffixArray.GetSa(r, sa, n + 1, 27);
        suffixArray.GetHeight(r, sa, rnk, height, n);
        
        //get pre & nxt
        for (int i = 1; i <= n; i++)
        {
            if (height[i] == 0) pre[i] = i;
            else pre[i] = pre[i-1];
        }
        for (int i = n; i > 0; i--)
        {
            if (i == n || height[i+1] == 0) nxt[i] = i;
            else nxt[i] = nxt[i+1];
        }
        
        //get answer
        printf("Case #%d:\n", kk);
        int i = 0;
        while (i < n)
        {
            int now = rnk[i];
            int left = pre[now], right = nxt[now];
            int t = i, k = 0;
            int minHeight = height[now];
            for (int j = now - 1; j >= left; j--)
            {
                minHeight = min(minHeight, height[j+1]);
                if (minHeight < k) break;
                if (sa[j] < i)
                {
                    if ((minHeight == k && sa[j] < t) || minHeight > k)
                    {
                        t = sa[j];
                        k = minHeight;
                    }
                }
            }
            if (now + 1 <= right) minHeight = height[now+1];
            for (int j = now + 1; j <= right; j++)
            {
                minHeight = min(minHeight, height[j]);
                if (minHeight < k) break;
                if (sa[j] < i) 
                {
                    if ((minHeight == k && sa[j] < t) || minHeight > k)
                    t = sa[j];
                    k = minHeight;
                }
            }
            if (k == 0) printf("-1 %d\n", s[i]);
            else printf("%d %d\n", k, t);
            i += (k == 0 ? 1 : k);
        }
    }
    return 0;
}