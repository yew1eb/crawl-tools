#include <cstdio>
#include <cstring>

using namespace std;

char s[10000];

int main()
{
    int n,a,len;
    //freopen("data.txt","r",stdin);
    while(1)
    {
        scanf("%s",s);
        n=0;
        len=strlen(s);
        while(len--){n+=s[len]-'0';}
        if(n==0) break;
        while(n>=10)
        {
            a=0;
            while(n){a+=n%10; n/=10;}
            n=a;
        }

        printf("%d\n",n);
    }
    return 0;
}