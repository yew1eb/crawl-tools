#include <stdio.h>
#include <string.h>

int main()
{
    char *p, a[1010], b[1010];
    int ans;
    while(scanf("%s",&a),a[0]!='#')
    {
        scanf("%s",b);
        int len = strlen(b);
        for(ans = 0, p = a; p=strstr(p,b); ans++, p += len);
        printf("%d\n",ans);
    }
    return 0;
}
