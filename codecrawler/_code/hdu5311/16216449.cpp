#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MX = 1830 + 5;
const int INF = 10000;

char w[] = "anniversary", S[MX], temp[MX];

int main() {
    int T, L = strlen(w), p;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", S);

        bool sign = false;
        for(int i = 0; i <= L - 3; i++) {
            for(int j = i + 1; j <= L - 2; j++) {
                //[0,i],[i+1,j],[j+1,L-1]
                strcpy(temp, w);
                temp[i + 1] = 0;
                p = strstr(S, temp) - S;
                if(p < 0) continue;
                p += i + 1;

                strcpy(temp, w + i + 1);
                temp[j - i] = 0;
                p = strstr(S + p, temp) - S;
                if(p < 0) continue;
                p += j - i;

                strcpy(temp, w + j + 1);
                temp[L - 1 - j] = 0;
                p = strstr(S + p, temp) - S;
                if(p < 0) continue;

                sign = true;
                break;
            }
            if(sign) break;
        }
        printf("%s\n", sign ? "YES" : "NO");
    }
    return 0;
}
