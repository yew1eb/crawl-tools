#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#define N 105
#define maxn 5005
#define INF 1<<30
using namespace std;
int num[maxn],sum,a[N],n,m,tmp[maxn];
int main()
{
    int i,j,k,t,x,y,sum;
    while(cin>>n,n){
        m=n*(n-1)/2;
        sum=0;
        for(i=0;i<m;i++){
            cin>>num[i];
            sum+=num[i];
        }
        sum=sum/(n-1);
        for(i=0;i<=sum;i++){
            for(j=0;j<m;j++)
            tmp[j]=num[j];
            k=m;
            a[1]=i;
            a[0]=tmp[0]-i;
            a[2]=tmp[1]-a[0];
             for(j=2;j<m;j++){
                if(a[1]+a[2]==tmp[j]){
                    tmp[j]=INF;
                    break;
                }
             }
             if(j==m)
             continue;
            tmp[0]=INF;
            tmp[1]=INF;
            k-=3;
            for(j=3;j<n;j++){
                sort(tmp,tmp+m);
                a[j]=tmp[0]-a[0];
                x=0;
                y=0;
                while(x<j&&y<k){

                    if(tmp[y]-a[j]==a[x]){
                        x++;
                         tmp[y]=INF;
                        y++;

                    }
                    else if(tmp[y]-a[j]>a[x])
                    break;
                    else y++;
                }
                if(x!=j)
                break;
                k-=j;
            }
            if(j==n)
            break;
        }
        for(i=0;i<n-1;i++){
            printf("%d ",a[i]);
        }
        printf("%d\n",a[n-1]);
    }
    return 0;
}
