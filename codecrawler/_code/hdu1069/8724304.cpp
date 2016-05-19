/*
ÌâÄ¿ÒªÇóÊÇ , °Ñ¸ø¶¨³ß´çµÄ³¤·½Ìå ( ÊýÁ¿²»ÏÞ ) µþÔÚÒ»Æð , ÄÜµþ¼ÓµÄÌõ¼þÊÇ ,
ÉÏÃæÒ»¸ö³¤·½ÌåµÄ³¤¿í±ÈÏÂÃæÒ»¸ö³¤·½ÌåµÄ³¤¿í¶Ì¶¼¶Ì ,
 »òÕßÒ»±ßÏàµÈ , ÁíÒ»±ß½Ï¶Ì , ³¤·½Ìå¿ÉÒÔÈÎÒâÃæ³¯ÏÂ°Ú·Å , ÇóÕâÐ©³¤·½ÌåÄÜ¹»µþ³ÉµÄ×î¸ßµÄ¸ß¶È .
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
    int x;
    int y;
    int h;
    bool operator <(const node& t)const
    {
        return x>t.x||(x==t.x&&y>t.y);
    }
} rec[100];

int main()
{
    int n;
    int i, j, max;
    int k;
    int x, y, z;
    int dp[100];
    int T = 1;
    while(scanf("%d",&n),n)
    {
        k = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(x>y) rec[k].x = x, rec[k].y = y;
            else rec[k].x = y, rec[k].y = x;
            rec[k++].h = z;

            if(x>z) rec[k].x = x, rec[k].y = z;
            else rec[k].x = z, rec[k].y = x;
            rec[k++].h = y;

            if(z>y) rec[k].x = z, rec[k].y = y;
            else rec[k].x = y, rec[k].y = z;
            rec[k++].h = x;
        }
        sort(rec,rec+k);
        dp[0] = rec[0].h;
        for(i=1; i<k; i++)
        {
            max = 0;
            for(j=i-1; j>=0; j--)
            {
                if( (rec[j].y>rec[i].y&&rec[j].x>rec[i].x)||
                    (rec[j].y>rec[i].x&&rec[j].x>rec[i].y) )
                {
                    if(dp[j]>max)
                        max = dp[j];
                }
            }
            dp[i] = max + rec[i].h;
        }
        max = 0;
        for(i=0; i<k; i++)
            if(dp[i]>max)
                max = dp[i];
        printf("Case %d: maximum height = %d\n",T++,max);
    }
    return 0;
}




















