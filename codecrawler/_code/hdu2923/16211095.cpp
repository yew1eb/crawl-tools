#include <iostream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
#define inf 999999999
const int L = 1005;
int n,c,m;
int a[105][105];
char str[1005][100];
int cnt;
map<string,int> mat;


void Floyd()
{
    int i,j,k;
    for(i = 1; i<=n; i++)
        for(j = 1; j<=n; j++)
            for(k = 1; k<=n; k++)
                if(a[j][i]+a[i][k]<a[j][k])
                    a[j][k] = a[j][i]+a[i][k];
}

int main()
{
    int i,j,val,x,y,len,cas = 1,sum,start;
    char s1[100],s2[100],s3[100];
    char from,to;
    while(~scanf("%d%d%d",&n,&c,&m)&&(n+c+m))
    {
        sum = 0;
        mat.clear();
        for(i = 0; i<=n; i++)
            for(j = 0; j<=n; j++)
                a[i][j] = inf;
        for(i = 0; i<=c; i++)
            scanf("%s",str[i]);
        cnt = 1;
        for(i = 0; i<m; i++)
        {
            scanf("%s %c-%d-%c %s",s1,&from,&val,&to,s3);
            if(!mat[s1])
                mat[s1] = cnt++;
            if(!mat[s3])
                mat[s3] = cnt++;
            x = mat[s1],y = mat[s3];
            if(from == '<' && val<a[y][x])
                a[y][x] = val;
            if(to == '>' && val<a[x][y])
                a[x][y] = val;
        }
        Floyd();
        start = mat[str[0]];
        for(i = 1; i<=c; i++)
            sum+=a[start][mat[str[i]]]+a[mat[str[i]]][start];
        printf("%d. %d\n",cas++,sum);
    }

    return 0;
}
