 #include<iostream>
 #include<cstdlib>
 #include<cstring>
 #include<cstdio>
 using namespace std;
 int bit[20];
 long long int dp[20][20][2000];
 long long  int x,y;
 
 
 long long int dfs(int len,int pos,int sum,bool flag )
 {
     long long int ans=0;
    if(len==0 ) return sum==0;
    if(sum<0) return 0;
    if(flag && dp[len][pos][sum]>=0) return dp[len][pos][sum];
 
    int tmp=flag?9:bit[len];
 
    for(int i=0;i<=tmp;i++)
    {
        int n_sum=sum;
        n_sum+=i*(len-pos);
        ans+=dfs(len-1,pos,n_sum,flag||i<tmp);
    }
    if(flag) dp[len][pos][sum]=ans;
    return ans;
 }
 long long int solve(long long int n)
 {
    int len=0;
    while(n) bit[++len]=n%10,n/=10;
    long long int ans=0;
    for(int i=1;i<=len;i++)
    {
       ans+=dfs(len,i,0,0);
    }
 
   return ans-(len-1);
    
 }
 int main()
 {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%64d %64d",&x,&y);
        memset(dp,-1,sizeof(dp));
        cout<<solve(y)<<endl;
     
    }
    return 0;
 }
