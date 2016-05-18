#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long
LL mat[50001][32]={0};
bool binarySearch(int x,int z,int cnt)
{
    int l=x+1,r=50000,mid;
    for(;l<=r;)
    {
        mid=(l+r)>>1;
        if(mat[mid][z]==0)
        {
            r=mid-1;
            continue;
        }
        if(mat[mid][z]+x*mid*z<cnt)
           l=mid+1;
        else if(mat[mid][z]+x*mid*z>cnt)
           r=mid-1;
        else
            return true;
    }
    return false;
}
int main()
{
    int k;
    for(int i=1;i<=50000;++i)
    {
        mat[i][1]=i;
        for(int j=2;j<=31;++j)
        {
            mat[i][j]=mat[i][j-1]*i;
            if(mat[i][j]>2147483648LL) break;//这个2147483648LL中的LL一定要加上

        }
    }
    for(;scanf("%d",&k),k;)
    {
        long long summ=0;
        int cnt;
        for(int x=1;x<=50000&&x<=k;++x)
            for(int z=2;z<=31;++z)
            {
                if(mat[x][z]==0) break;
                cnt=k-mat[x][z];
                if(cnt-x*z<=0) break;
                if(binarySearch(x,z,cnt))
                    summ++;
            }
        printf("%I64d\n",summ);
    }
    return 0;
}
