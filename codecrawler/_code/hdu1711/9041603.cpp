#include <stdio.h>
#include <string.h>

const int maxn = 1000005;
const int maxm = 10005;
int a[maxn], b[maxm], next[maxm];
int n, m;

void Read()
{
    int i;
    scanf("%d%d",&n, &m);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    for(i=0; i<m; i++) scanf("%d", &b[i]);
}

void Get_Next()
{
    int i, j;
    i = 0;
    next[0] = -1;
    j = -1;
    while(i<m) {
        if(j==-1||b[i]==b[j]) {
            i++;
            j++;
            next[i] =j;
        } else {
            j = next[j];
        }
    }
}

int Kmp()
{
    int i, j;
    i = 0;
    j = 0;
    while(i<n&&j<m) {
        if(j==-1||b[j]==a[i]) {
            i++;
            j++;
        } else {
            j=next[j];
        }
    }
    if(j>=m)
        return i - j + 1;
    else
        return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        Read();
        Get_Next();
        int ans = Kmp();
        printf("%d\n",ans);
    }
    return 0;
}
