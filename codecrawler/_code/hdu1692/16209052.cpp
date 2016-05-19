#include<iostream>
using namespace std;
int t,n,ans,w[100005],l[100005],p[100005];
int min(int i,int j)
{
    return i<j?i:j;
}
void f()
{
    int tmp=p[n];
    ans=p[n];
    for(int i=1;i<n;i++){
        int sum=p[i];
        int wi=w[i];
        for(int j=i+1;j<=n;j++){
            wi+=w[j];
            if(wi<=l[j])    sum+=p[j];
            if(sum>=ans) break;
        }
        ans=min(ans,sum);
    }
}
int main()
{
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>w[i]>>l[i]>>p[i];
        f();
        cout<<"Case "<<cas<<": Need to use "<<ans<<" mana points."<<endl;
    }
}