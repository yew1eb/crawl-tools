#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#include<string>
#include<cstdlib>
#include<cmath>

using namespace std;

const int maxn = 100005;
int a[maxn];

int main()
{
    int n, t;
    int tt = 1;
    while(EOF != scanf("%d %d",&n, &t) ) {
        int sum = 0;
        int ji = 0;
        int ou = 0;
        if(n == -1 && t == -1) {
            break;
        }
        int ss = 0;
        int tot = 0;
        int x = n;
        while(x) {
            a[tot++] = x % 10;
            x /= 10;
        }
        for(int k = tot - 1; k >= 0; k--) {
            ss++;
            if(ss % 2 == 1) {
                ji += a[k];
            } else 
                ou += a[k];
            sum += a[k];
        }
        for(int i = 1; i <= t; i++) {
            x = sum;
            tot = 0;
            while(x) {
                a[tot++] = x % 10;
                x /= 10;
            }
            for(int k = tot - 1; k >= 0; k--) {
                ss++;
                if(ss % 2 == 1) {
                    ji += a[k];
                } else 
                    ou += a[k];
                sum += a[k];
            }
        }
        int cha = ji - ou;
//        cout << ji << "  " << ou << "  " << cha << endl;
        if(cha %11 == 0) {
            printf("Case #%d: Yes\n", tt++);
        }
        else
            printf("Case #%d: No\n", tt++);
    }
    return 0;
}
