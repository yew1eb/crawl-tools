#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

typedef __int64 LL;
const int N=400109;
const LL II=1000000007;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);

char xh[N],s[N],pi[26];
int p[N],len;

void manacher(char *str)
{
	int mx=0;//记录前面回文串最长影响到的地方。不一定是最长回文串造成的。
	int id;//最长影响串的id
	int ans=0,t;//最长结果
	for(int i=1;i<len;i++)
	{
		if(mx>i)    p[i]=min(p[2*id-i],mx-i);
		else	p[i]=1;
		while(str[i+p[i]]==str[i-p[i]])
		{
            p[i]++;
		}
		if(i+p[i]>mx)
		{
			mx=i+p[i];
			id=i;
		}
		if(p[i]>ans)	ans=p[i],t=i;
	}
	ans--;
	if(ans<2)
	{
	    printf("No solution!\n");
	    return ;
	}
	int j=t-(ans-1);
	printf("%d %d\n",j/2-1,j/2+ans-2);
	for(int i=0;i<ans;i++,j+=2)
        printf("%c",pi[str[j]-'a']);
    printf("\n");
}

int main()
{
    int i,j,l;
    char c,a;
	while(scanf("%c%s",&c,s)!=EOF)
	{
	    l=c-'a';
	    for(i=0;i<26;i++)
            pi[i]=(i+26-l)%26+'a';
	    getchar();//这个地方要注意
        len=strlen(s);
        xh[0]='$';xh[1]='#';
        for(i=0,l=2;i<len;i++,l+=2)
        {
            xh[l]=s[i];
            xh[l+1]='#';
        }
        len=len*2+2;
		manacher(xh);
	}
	return 0;
}