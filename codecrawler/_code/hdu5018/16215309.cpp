#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("cin.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int q1=a,q2=b,q=a+b;
        if(c==q1 || c==q2 || c==q){
            printf("Yes\n");
            continue;
        }
        while(q<c){
            a=b;
            b=q;
            q=a+b;
        }
        if(q==c)  printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}