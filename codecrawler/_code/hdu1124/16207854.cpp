#include <iostream>
#include <cstdio>
using namespace std;
int get(int a){   return a/5;  }
int main()
{
    //freopen("cin.txt","r",stdin);
    int t,q,temp;
    cin>>t;
    while(t--){
        scanf("%d",&q);
        int ans=0;
        temp=get(q);
        while(temp){
            ans+=temp;
            temp=get(temp);
        }
        printf("%d\n",ans);
    }
    return 0;
}