#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 1000;
const int bit = 42;
typedef long long LL;
LL a[maxn][maxn],g[maxn];
int n;

void build_matrix()        //æé ç³»æ°ç©éµ
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < bit; j++)
            a[i][bit-1-j] = (g[i]>>j) & 1;
    }
}

void Gauss(int n)
{
    int row = 0,col = 0,j,k,r;
    while(row < n && col < bit)
    {
        r = row;
        for(k = row+1; k < n; k++)
            if(a[k][col])
            {
                r = k;
                break;
            }
        if(a[r][col])
        {
            if(r != row)
            {
                for(k = col; k < bit; k++)
                    swap(a[r][k],a[row][k]);
            }
            //å¼ææ¶å
            for(k = row+1; k < n; k++)
            {
                if(a[k][col] == 0) continue;
                for(j = col; j < bit; j++)
                    a[k][j] ^= a[row][j];
            }
            row++;
        }
        col++;
    }
    if(row < n) printf("Yes\n");
    else printf("No\n");
}

int main()
{    
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i = 0; i < n; i++)
            scanf("%I64d",&g[i]);
        build_matrix();
        if(n > bit)
        {
            printf("Yes\n");
            continue;
        }
        Gauss(n);
    }
    return 0;
}