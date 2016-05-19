#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

/*
freopen("input.txt",  "r", stdin);  //读数据
freopen("output.txt", "w", stdout); //注释掉此句则输出到控制台
*/

int xf[9];
int a[44],b[44];

int main()
{
    int i,j,n,k,tt,q,w;
    cin>>tt;
    while(tt--)
    {
        memset(a,0,sizeof(a));
        memset(xf,0,sizeof(xf));
        cin>>n>>k;
        for(i=1;i<=k;i++)
        {
            scanf("%d%d",&q,&w);
            xf[q]=w;
        }
        i=1;
        while(xf[i]==0)
            i++;//找到第一个有学分的课
        for(j=0;j<=xf[i];j++)
            if((j*i)<=n)//这个没必要，但是为了防止越界，还是加上吧
                a[j*i]=1;
        for(i++;i<=8;i++)
        {
            if(xf[i]==0)
                continue;
            memset(b,0,sizeof(b));
            for(j=0;j<=n;j++)
            {
                if(a[j]==0)
                    continue;
                for(k=0;k<=xf[i];k++)
                {
                    if((j+k*i)<=n)
                        b[j+k*i]+=a[j];
                    else
                        break;
                }
            }
            for(j=0;j<=n;j++)
                a[j]=b[j];
        }
        printf("%d\n",a[n]);
    }
    return 520;
}