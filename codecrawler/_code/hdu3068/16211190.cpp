#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;
const int N=110055;

int p[2*N];
char str0[N],str[2*N];

void init()
{
    int i,l;
    str[0]='@';str[1]='#';
    for(i=0,l=2;str0[i];i++,l+=2)
    {
        str[l]=str0[i];
        str[l+1]='#';
    }
    str[l]=0;
}
int solve()
{
    int ans=0;
    int i,mx,id;
    mx=0;
    for(i=1;str[i];i++)
    {
        if(mx>i)p[i]=p[2*id-i]>(mx-i)?(mx-i):p[2*id-i];
        else    p[i]=1;
        while(str[i+p[i]]==str[i-p[i]])    p[i]++;
        if(i+p[i]>mx)
        {
            mx=i+p[i];
            id=i;
        }
        if(p[i]>ans)    ans=p[i];
    }
    return ans-1;
}
int main()
{
    while(scanf("%s",str0)!=-1)
    {
        init();
        printf("%d\n",solve());
    }
    return 0;
}