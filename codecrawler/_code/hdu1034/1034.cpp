#include<cstdio>
using namespace std;
int main()
{
    int a[100],n,k,p,t,i,j;
    while(scanf("%d",&n),n)
    {
        k=0;
        for(i=0;i<n;i++)  //接受数据
        scanf("%d",&a[i]);
        while(1)
        {
            k++;
            t=a[n-1]/2;    //t为本轮 a[i]要加多少
            for(i=0;i<n;i++)  //循环
            {
                p=a[i]/2;    
                a[i]=a[i]/2+t;  
                t=p;
                if(a[i]&1)  //为奇数加1
                ++a[i];
            }
            t=a[0];
            for(i=0;t==a[i]&&i<n;i++);  //判断是否全部相等
            if(i==n)
                break;
        }
        printf("%d %d\n",k,t);
    }
    return 0;
}