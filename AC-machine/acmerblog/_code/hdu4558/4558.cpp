int dx[] = {1,0,1,0};//up Right down Left
int dy[] = {0,1,0,-1};

const int M = 480, N = 11, mod = 1000000007;
char s[M];
int a[M][M], n, m, ans;
int dp[M][M][N];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    #endif

    int T; scanf("%d", &T);
    FOE(t, 1, T){
        ans = 0;
        memset(dp, 0, sizeof dp);
        scanf("%d%d", &n, &m);
        FOR(x, 0, n) {
            scanf("%s", s);
            FOR(y, 0, m) a[x][y] = s[y]-'0';
        }

        FOD(x, n-1, 0) {
            FOD(y, m-1, 0) {
                int v = a[x][y];
                FOR(i, 0, N) {
                    FOR(r, 0, 2) {
                        int xx=x+dx[r], yy=y+dy[r];
                        if(xx>=n || yy>=m) continue;

                        int temp = (11-i+v) % 11;
                        dp[x][y][i] = (dp[x][y][i] + dp[xx][yy][temp]) % mod;
                    }
                }
                dp[x][y][v]++;
                ans = ( ans + dp[x][y][0] ) % mod;
            }
        }
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}