#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    char s[1010];
    int r[1010], l[1010];
    int i, lens;
    while (~scanf("%d", &T)) {
        while (T--) {
            scanf("%s", s);

            lens = strlen(s);

            for (i = lens - 1; i >= 0; i--) {     ///æ«æ ) çæ°é
                if (i == lens - 1) {
                    r[i] = (s[i] == ')');
                } else {
                    r[i] = r[i + 1] + (s[i] == ')');
                }
            }

            for (i = 0; i < lens; i++) {   ///æ«æ ( çæ°é
                if (i == 0) {
                    l[i] = (s[i] == '(');
                } else {
                    l[i] = l[i - 1] + (s[i] == '(');
                }
            }

            int ans = 99999999;

            for (i = 0; i < lens; i++)
                ans = min(ans, r[i] + l[i] - 1);    ///å¯»æ¾æä½ç½®å·¦å³è½¬ç½®éè¦çæå°æ¬¡æ°ï¼æ³¨æåä¸

            printf("%d\n", ans);
        }
    }
    return 0;
}
