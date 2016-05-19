#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=1100;
int main()
{
    int n,a[N],f[N],i,j;
    while(scanf("%d",&n),n)
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            f[a[i]]=1;          //初始化标记 
        }
        for(i=0;i<n;i++)
        {
            if(f[a[i]]==0)    //如果已经存在不必再求，节省时间 
            continue;
            else
            j=a[i];
            while(j>1)
            {
                if(j%2==1)
                {
                    j=(j*3+1)/2;
                }
                else
                j=j/2;
                if(j<N)
                {
                    f[j]=0;    //将覆盖数标记 
                }
                
            }
            
        }j=0;
        for(i=n-1;i>=0;i--)
        {
            if(f[a[i]]&&j==1)
            printf(" %d",a[i]);       //倒序输出没有被标记的数，注意格式、 
            if(f[a[i]]&&j==0)
            {
                printf("%d",a[i]);
                j=1;
            }
            
        }
        printf("\n");
    }
    return 0; 
}