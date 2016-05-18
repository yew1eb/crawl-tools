#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 10010
int m,n,n1,n2;
int mb,ms;
int b[maxn],s[maxn];
int cmp(int t1,int t2){
    return t1>t2;
}
int main(){
    int T; scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%d%d%d%d",&n,&m,&n1,&n2);
        s[0]=b[0]=0;
        for(int i=1;i<=n1;i++)
            scanf("%d",&b[i]);
        sort(b+1,b+1+n1,cmp);

        for(int i=1;i<=n2;i++)
            scanf("%d",&s[i]);
        sort(s+1,s+1+n2,cmp);

        for(int i=1;i<=n1;i++)
            b[i]+=b[i-1];
        for(int i=1;i<=n2;i++)
            s[i]+=s[i-1];

        if(n<=1 && m<=1){
            printf("Case #%d: 0\n",cas);
        }
        else{
            if(n>m)
                swap(n,m);
            int ans=0;
            mb=min(n1,n*m/2);

            if(n==1)
                ms=min(n2,n*m/3);
            else if(n==2 && m%3==2)
                ms=min(n2,n*m/3-1);
            else
                ms=min(n2,n*m/3);

            int msize=n*m;
            for(int i=0;i<=ms;i++){
                int tmp=0;
                int j=(msize-i*3)/2;
                tmp+=s[i];
                if(j<=mb)
                    tmp+=b[j];
                else
                    tmp+=b[mb];
                if(tmp>ans)
                    ans=tmp;
            }
            printf("Case #%d: %d\n",cas,ans);
        }
    }
    return 0;
}
