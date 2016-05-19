#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct Node
{
    int w,h;
    bool operator<(Node a)
    {
        if(a.w==w)
            return h>a.h;
        return w<a.w;
    }
};
Node A[20002];
int p[20002];
int main()
{
    int T,M,i,l,r,m,q;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&M);
        for(i=0;i<M;i++)
            scanf("%d%d",&A[i].w,&A[i].h);
        sort(A,A+M);
        q=0;
        for(i=0;i<M;i++)
        {
            l=0;r=q;
            while(l<r)
            {
                m=(l+r)/2;
                if(p[m]>=A[i].h)
                    l=m+1;
                else r=m;
            }//è¿ä¸ªäºåï¼å°±æ¯å»æ¾ä¸ä¸ªåå¥½å®¹çæ¡¶
            p[l]=A[i].h;
            q += (l==q);//åå¦ï¼æ²¡ææ¾å°ï¼å°±æ°å ä¸ä¸ªæ¡¶ã
        }
        printf("%d\n",q);
    }
    return 0;
}