#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#define MAX 100
#define MOD 10001
#define int64 int//long long//__int64


int n, begin, end;
int64 m,final[MAX][MAX];
char str[MAX][MAX],tp[MAX];
struct Mat {
    int mat[MAX][MAX], size;
    friend Mat operator *(Mat a, Mat b);
    friend Mat operator +(Mat a, Mat b);
    friend Mat operator ^(Mat a, int64 k);
} E;
Mat operator *(Mat a, Mat b) {

    Mat c;
    c.size = a.size;
    memset(c.mat, 0, sizeof (c.mat));
    for (int i = 0; i < c.size; ++i)
        for (int j = 0; j < c.size; ++j)
            for (int k = 0; k < c.size; ++k)
                if (a.mat[i][k] && b.mat[k][j])
                    c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
    return c;
}
Mat operator +(Mat a, Mat b) {

    Mat c;
    c.size = 2 * n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            c.mat[i][j] = (a.mat[i][j] + b.mat[i][j]) % MOD;
    return c;
}
Mat operator ^(Mat a, int64 k) {

    Mat c = E;
    c.size = a.size;
    while (k) {

        if (k & 1) c = c * a;
        a = a * a, k >>= 1;
    }
    return c;
}
Mat sum1(Mat A,int k) {
    //ç©ºé´å¤æåº¦ä¸ºOï¼n*n),æ¶é´å¤æåº¦ä¸ºOï¼logï¼kï¼*n^3ï¼
    if (k == 1) return A;
    if (k & 1)  return sum1(A,k-1) + (A^k);
    return sum1(A,k/2) * ((A^(k / 2)) + E);
}
Mat sum2(Mat A, int64 k) {

    int i,j;
    Mat c = A;
    c.size = 2 * A.size;
    for (i = 0; i < n; ++i)
       c.mat[i][i+n] = c.mat[i+n][i+n] = 1;

    
    c = c^(k+1);
    Mat temp;
    temp.size = n;
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            temp.mat[i][j] = (i==j?c.mat[i][j+n]-1:c.mat[i][j+n]);
    return temp;
}
int Solve() {

    int i, j;
    Mat c;
    E.size = c.size = n;
    memset(c.mat, 0, sizeof (c.mat));
    memset(E.mat, 0, sizeof (E.mat));
    for (i = 0; i < 2 * n; ++i) E.mat[i][i] = 1;
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            if (str[i][strlen(str[i]) - 1] == str[j][0])
                c.mat[i][j] = 1;


    if (m % 2 == 0) m--;
    int cnt = (m - 1) / 2;
    Mat c2 = c * c;
    int ans = 0;
    c = c + c * sum2(c2,cnt);
    ans = (ans + c.mat[begin][end]) % MOD;
    return ans;
}


int main()
{
    int i, j, k,t;


    scanf("%d", &t);
    while (t--) {

        scanf("%d", &n);
        for (i = 0; i < n; ++i)
            scanf("%s",str[i]);
        scanf("%s",tp);
        for (i = 0; i < n; ++i)
            if (strcmp(tp,str[i]) == 0)
                begin = i;
        scanf("%s",tp);
        for (i = 0; i < n; ++i)
            if (strcmp(tp,str[i]) == 0)
                end = i;
        scanf("%d",&m);


        int ans = Solve();
        printf("%d\n",ans%MOD);
    }
}