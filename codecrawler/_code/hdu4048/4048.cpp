import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;
import java.util.Arrays;
public class Main{
    int p[] = new int[2300], nn[] = new int[20010];
    void build() {
        boolean vis[] = new boolean[20010];
        int cnt = 0;
        p[0] = 1;
        for (int i = 2; i < 20010; i++)
            if (!vis[i]) {
                p[++cnt] = i;
                int j = i;
                while (j < 20010) {
                    vis[j] = true;
                    j += i;
                }
            }
    }

    StreamTokenizer in = new StreamTokenizer(new BufferedReader(
            new InputStreamReader(System.in)));

    int nextInt() throws IOException {
        in.nextToken();
        return (int) in.nval;
    }

    int prime[] = new int[10010], count[] = new int[10010], cnt;
    void divide(int n) {
        cnt = 0;// 质因子数目
        int mx = (int) (Math.sqrt(n) + 3);
        if (n < mx)
            mx = n;
        for (int i = 2; i < mx; i++) {
            if (n == 1)
                break;
            if (n % i == 0) {
                prime[++cnt] = i;
                count[cnt] = 0;
                while (n % i == 0) {
                    n /= i;
                    count[cnt]++;
                }
            }
        }
        if (n != 1) {
            prime[++cnt] = n;
            count[cnt] = 1;
        }
    }

    long pow(long x, long p) {
        long ans = 1;
        while (p > 0) {
            if ((p & 1) == 1)
                ans = muti_mod(ans,x);
            p >>= 1;
            x = muti_mod(x,x);// x*x can be long even x is int
        }
        return ans;
    }

    long muti_mod(long a, long b)
    {
        long n=mod;
        long exp = a % n, res = 0;
        while (b>0)
        {
            if ((b & 1)==1)
            {
                res += exp;
                if (res > n)
                    res -= n;
            }
            exp <<= 1;
            if (exp > n)
                exp -= n;

            b >>= 1;
        }
        return res;
    }

    long get(int now, int sum, long k) {
        long ans = pow(nn[sum], k);
        for (int i = now + 1; p[i]*sum<=mx; i++)
            if (nn[p[i]*sum] >0)
                ans = (ans - get(i, sum * p[i], k) + mod)% mod;
        return ans;
    }

    long ans, mx;
    void dfs(int now, long value, long euler) {
        if (now == cnt + 1) {// value是n的因子
            long temp = get(0, 1, n / value);
            ans = (ans + euler * temp) % mod;
            return;
        }
        dfs(now + 1, value, euler);
        long temp = prime[now];
        for (int i = 1; i <= count[now]; i++) {
            dfs(now + 1, value * temp, muti_mod(euler * (prime[now] - 1),
                    (temp / prime[now]) ));
            temp = muti_mod(prime[now],temp);
        }
    }

    long polya() {
        ans = 0;
        divide(n);
        dfs(1, 1, 1);
        ans/=n;
        mod/=n;
        ans%=mod;
        ans+=mod;
        ans%=mod;
        return ans;
    }

    int m, n;
     int mod ;
    void run() throws IOException {
        int cas = nextInt();
        build();
        while (cas-- > 0) {
            m = nextInt();
            n = nextInt();
            mod= 10007*n;
            Arrays.fill(nn, 0);
            mx = -1;
            for (int i = 0; i < m; i++) {
                int x = nextInt();
                if (x > mx)
                    mx = x;
                int j;
                for (j = 1; j * j < x; j++)
                    if (x % j == 0) {
                        nn[j]++;
                        nn[x / j]++;
                    }
                if (j * j == x)
                    nn[j]++;
            }
            System.out.println(polya());
        }
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}