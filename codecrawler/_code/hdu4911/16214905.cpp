#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[100005];
int left[100005], right[100005];
__int64 cnt;

void merge(int* a, int p, int q, int r)
{
    int i, j, k, n1, n2;
    n1 = q-p+1;
    n2 = r-q;
    for (i=0; i<n1; i++)
    {
        left[i] = a[p+i];
    }
    for (i=0; i<n2; i++)
    {
        right[i] = a[q+i+1];
    }
    left[n1] = right[n2] = 0x7fffffff;

    i = j = 0;
    for (k=p; k<=r; k++)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
            cnt += n1-i; /**æ­¤æ­¥éª¤æ¯å¨å½å¹¶æåºæ³ä¸­å çä¸å¥ï¼ç¨æ¥è®¡æ°æ±éåºæ°çæ°ç®**/
        }
    }
    return;
}

void mergesort(int* a, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p+r)/2;
        mergesort(a, p, q);
        mergesort(a, q+1, r);
        merge(a, p, q, r);
    }
    return ;
}
int main()
{
    int n,k,i,j;
    while(~scanf("%d%d",&n,&k))
    {
        cnt = 0;
        for(i = 0;i<n;i++)
        scanf("%d",&a[i]);
        mergesort(a,0,n-1);
        printf("%I64d\n",max(cnt-k,(__int64)0));
    }

    return 0;
}
