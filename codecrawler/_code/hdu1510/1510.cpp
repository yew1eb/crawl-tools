#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=110;
char A[maxn][maxn];
int a[maxn][maxn];
int main()
{
    int T;
    int sum;
    while (cin>>T){
        getchar();
        sum=0;
        memset(a,0,sizeof(a));
        for(int i=0;i<T;i++){
            gets(A[i]);
            int l=strlen(A[i]);
            for(int j=0;j<l;j++){
                if(A[i][j]=='#') a[i][j]=0;
                else if(!i) a[i][j]=1;
                else a[i][j]=a[i-1][j]+1;
                sum+=a[i][j];
                if(j){
                    int ans=a[i][j];
                    for(int x=j-1;x>=0;x--){
                        if(!a[i][x]) break;
                        ans=min(ans,a[i][x]);
                        sum+=ans;
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}