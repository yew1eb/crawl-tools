#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int num[1005];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)==2)
    {
        k--;
        for(int i=0;i<n;i++)
            scanf("%d",num+i);
        if(k==0) printf("Alice\n");
        else 
        {
            if(n%2) num[n++]=k%2-1;
            sort(num,num+n);
            int sum=0;
            for(int i=0;i<n;i+=2)
                sum^=num[i+1]-num[i]-1;
            if(sum) printf("Alice\n");
            else printf("Bob\n");
        }
    }
    return 0;
}