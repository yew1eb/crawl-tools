#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int num[20][20], dp[2][1 << 15], top = 0, sta[1 << 15], n, ans, row;
char ch[1000];
int main() {
    for(int i = 0; i < 1 << 15; ++i)
        if((i & (i << 1)) == 0)
            sta[top++] = i;
    ans = row = 0;
    memset(dp, 0, sizeof(dp));
    while(gets(ch)) {
        if(strcmp(ch, "") == 0) {
            for(int i = 0; i < row; ++i) {
                for(int j = 0; j < top && sta[j] < (1 << row); ++j) {
                    int sum = 0, max_s = 0;
                    //ç¬¬iè¡ å¨ç¶æsta[j]ä¸çæ»å 
                    for(int k = 0; k < row; ++k)
                        sum += sta[j] & (1 << k) ? num[i][k] : 0;
                    //ååºç¶æsta[j]ä¸ç ä¸ä¸ä¸è¡æå¤§ç 
                    for(int k = 0; k < top && sta[k] < (1 << row); ++k) 
                        if(!(sta[j] & sta[k]) && !(sta[j] & sta[k] << 1) && !(sta[j] << 1 & sta[k]))
                            max_s = max(max_s, dp[1 - (i & 1)][sta[k]]);
                //    printf("%d %d\n", sum, max_s);
                    //è¦çè¯¥ç¶æçæ°çæå¤§å¼ 
                    dp[i & 1][sta[j]] = sum + max_s;
                    ans = max(ans, sum + max_s);
                    /*
for(int k = 0; k < 8; ++k)
                        printf("%d ", dp[0][k]);
                    printf("\n");
                    for(int k = 0; k < 8; ++k)
                        printf("%d ", dp[1][k]);
                    printf("\n\n\n");*/
                }
            }
            printf("%d\n", ans);
            row = ans = 0;
            memset(dp, 0, sizeof(dp));
            continue;
        }
        int temp = 0, k = 0;
        for(int i = 0; ch[i]; ++i)
            if(ch[i] == ' ')
                num[row][k++] = temp, temp = 0;
            else
                temp = temp * 10 + ch[i] - '0';
        num[row][k++] = temp;
        row++;
    } 
}