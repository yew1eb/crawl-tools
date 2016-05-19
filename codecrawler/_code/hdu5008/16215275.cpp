#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N=111000;
char s[N]; // N>256
int n, sa[N], height[N], _rank[N], tmp[N], top[N];
void makesa() //O(N*logN)
{
    int i, j, len, na;
    na = (n < 256 ? 256 : n);
    memset(top, 0, na * sizeof(int));
    for (i = 0; i < n ; i++) top[ _rank[i] = s[i] & 0xff ]++;
    for (i = 1; i < na; i++) top[i] += top[i - 1];
    for (i = 0; i < n ; i++) sa[ --top[ _rank[i] ] ] = i;
    for (len = 1; len < n; len <<= 1)
    {
        for (i = 0; i < n; i++)
        {
            j = sa[i] - len;
            if (j < 0) j += n;
            tmp[ top[ _rank[j] ]++ ] = j;
        }
        sa[ tmp[ top[0] = 0 ] ] = j = 0;
        for (i = 1; i < n; i++)
        {
            if (_rank[ tmp[i] ] != _rank[ tmp[i-1] ] ||
                    _rank[ tmp[i]+len ]!=_rank[ tmp[i-1]+len ])
                top[++j] = i;
            sa[ tmp[i] ] = j;
        }
        memcpy(_rank, sa , n * sizeof(int));
        memcpy(sa , tmp, n * sizeof(int));
        if (j >= n - 1) break;
    }
}
void lcp() //O(4*N)
{
    int i, j, k;
    for (j = _rank[height[i=k=0]=0]; i < n - 1; i++, k++)
        while (k >= 0 && s[i] != s[ sa[j-1] + k ])
            height[j] = (k--), j = _rank[ sa[j] + 1 ];
}
ll f[N];
int main()
{
    while( scanf("%s", s)!=EOF )
    {
        n = strlen(s)+1;
        int len = n-1;
        makesa();
        lcp();
        int q;
        for(int i=1; i<=len; i++)
            f[i]=f[i-1]+len-sa[i]-height[i];
        ll k,v,l=0,r=0;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%I64d",&v);
            k=(v^l^r)+1;
            if(f[len]<k)
            {
                l=r=0;
                puts("0 0");
                continue;
            }
            int pos=lower_bound(f+1,f+n,k)-f;
            l=sa[pos];
            //int len1;
            //if(pos) len1=k-f[pos-1]+height[pos];
            //else len1=k;
            int len1=len-(f[pos]-k)-l;
            while(++pos<n&&height[pos]>=len1)//è¿éæå¥½ç¨RMQ+äºåï¼é¿ååä¸ä¸ªaçæ°æ®çæåµ
                if(l>sa[pos]) l=sa[pos];
            l++;
            r=l+len1-1;
            printf("%I64d %I64d\n",l,r);
        }
    }
    return 0;
}