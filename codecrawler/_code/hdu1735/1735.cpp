#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

int mess[10001][101];
struct Tom
{
    int num, zero;
} save[10001];
int cmp(const void *x, const void *y)
{
    return (*(struct Tom*)y).zero - (*(struct Tom*)x).zero;
}
int main()
{
#ifdef test
    freopen("sample.txt", "r", stdin);
#endif
    int m, n, l;
    while(scanf("%d%d%d", &n, &l, &m) != EOF)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<l; j++)
                scanf("%d", &mess[i][j]);
        }
        int cct=0;
        if(mess[0][0]==0&&mess[0][1]==0)
            mess[0][0]=mess[0][1]=2;// 文章开头段 0 的处理
        for(int i=1; i<n; i++)
            if(mess[i][0]==0&&mess[i][1]==0)
            {
                save[cct].num = i;
                save[cct].zero = 0;
                for(int j=l-1; j>=0; j--)
                    if(mess[i-1][j]==0)
                        ++save[cct].zero;
                    else break;
                ++cct;
            }
        qsort(save, cct, sizeof(save[0]), cmp);
        for(int i=0; i<m-1; i++)
        {
            int ii = save[i].num;
            mess[ii][0]=mess[ii][1]=2;// 令段头的0全部转换为1
            for(int j=l-1; j>=0; j--)
                if(mess[ii-1][j]==0)
            