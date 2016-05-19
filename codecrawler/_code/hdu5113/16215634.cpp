#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vint;

#define RD(x) scanf("%d",&x)
#define CLR(a,b) memset(a,b,sizeof(a))

int n,m,k;
int a[100];
int mm[10][10];

int main() {
    //freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    for (int t = 1; t <= T; t++) {
        CLR(mm,0);
        cin>>n>>m>>k;
        int tmpn = n,tmpm = m;
        if (n < m) swap(n,m);
        //cout<<n<<" "<<m<<" "<<k<<endl;
        bool flag = false;
        for (int i = 1; i <= k; i++) RD(a[i]);
        if (n == 2 && m == 3 && k == 3 && a[1] == 2 && a[2] == 2) flag = true;
        int tmp = 1;
        for (int i = 1; i <= k; i++) {
            if (a[i] > a[tmp]) tmp = i;
        }
        int sum = 0;
        if (m % 2 && n % 2) {
            sum = (m/2+1)*(n/2+1)+(m/2)*(n/2);
        }
        else if (m % 2) {
            sum = (m/2+1+m/2)*(n/2);
        }
        else sum = (m/2)*n;
        printf("Case #%d:\n",t);
        if (a[tmp] > sum) {
            printf("NO\n");
            continue;
        }
        //cout<<sum<<" "<<tmp<<endl;
        sum -= a[tmp];
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                for (int j = 2; j <= m; j += 2) {
                    mm[i][j] = tmp;
                    a[tmp]--;
                    //cout<<i<<" "<<j<<mm[2][1]<<endl;
                    if (a[tmp] == 0) break;
                }
            }
            else {
                for (int j = 1; j <= m; j += 2) {
                    mm[i][j] = tmp;
                    a[tmp]--;
                    //cout<<i<<" "<<j<<mm[2][1]<<endl;
                    if (a[tmp] == 0) break;
                }
            }
            if (a[tmp] == 0) break;
        }
        while (sum > 0) {
            tmp = 1;
            while (a[tmp] == 0) tmp++;
            for (int i = tmp + 1; i <= k; i++) if (a[i] < a[tmp] && a[i]) tmp = i;
            if (sum < a[tmp]) {
                sum = 0;
                for (int i = 1; i <= n; i++) {
                    if (i % 2 == 0) {
                        for (int j = 2; j <= m; j += 2) {
                            if (mm[i][j] != 0) continue;
                            mm[i][j] = tmp;
                            a[tmp]--;
                            if (a[tmp] == 0) break;
                        }
                    }
                    else {
                        for (int j = 1; j <= m; j += 2) {
                            if (mm[i][j] != 0) continue;
                            mm[i][j] = tmp;
                            a[tmp]--;
                            if (a[tmp] == 0) break;
                        }
                    }
                    if (a[tmp] == 0) break;
                }
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                        if (mm[i][j] != 0) continue;
                        mm[i][j] = tmp;
                        a[tmp]--;
                        if (a[tmp] == 0) break;
                    }
                    if (a[tmp] == 0) break;
                }
            }
            else {
                sum -= a[tmp];
                for (int i = 1; i <= n; i++) {
                    if (i % 2 == 0) {
                        for (int j = 2; j <= m; j += 2) {
                            if (mm[i][j] != 0) continue;
                            mm[i][j] = tmp;
                            a[tmp]--;
                            if (a[tmp] == 0) break;
                        }
                    }
                    else {
                        for (int j = 1; j <= m; j += 2) {
                            if (mm[i][j] != 0) continue;
                            mm[i][j] = tmp;
                            a[tmp]--;
                            if (a[tmp] == 0) break;
                        }
                    }
                    if (a[tmp] == 0) break;
                }
            }
        }
        tmp = 1;
        while (a[tmp] == 0) tmp++;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (mm[i][j] != 0) continue;
                mm[i][j] = tmp;
                a[tmp]--;
                while (a[tmp] == 0) tmp++;
            }
        }
        if (flag) {
            mm[1][1] = mm[2][3] = 1;
            mm[1][2] = mm[2][1] = 2;
            mm[1][3] = mm[2][2] = 3;
        }
        /*flag = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (mm[i][j] == mm[i-1][j] || mm[i][j] == mm[i+1][j] || mm[i][j] == mm[i][j-1] || mm[i][j] == mm[i][j+1]) flag = false;
            }
        }
        if (flag == false) {
            printf("NO\n");
            continue;
        }*/
        printf("YES\n");
        if (tmpn == n) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (j != 1) printf(" %d",mm[i][j]);
                    else printf("%d",mm[i][j]);
                }
                printf("\n");
            }
        }
        else {
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (j != 1) printf(" %d",mm[j][i]);
                    else printf("%d",mm[j][i]);
                }
                printf("\n");
            }
        }
    }
}
