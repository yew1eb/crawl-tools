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
const int N=1000000;
const LL II=1000000007;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);

char word[N];
int wlen,next[N];

void getnext(char *p)
{
    int j=0,k=-1;
    next[0]=-1;
    while(j<wlen)
    {
        if(k==-1||p[j]==p[k])
        {
            j++;    k++;
            next[j]=k;
        }
        else
            k=next[k];
    }
}

int getminmax(int flag)  //最小最大表示法0、1
{
    int i=0,j=1,k=0;
    while(i<wlen&&j<wlen&&k<wlen)
    {
        int t=word[(i+k)%wlen]-word[(j+k)%wlen];
        if(!t) k++;
        else
        {
            if(flag==0)
            {
                if(t>0) i=i+k+1;
                else    j=j+k+1;
            }
            else
            {
                if(t>0) j=j+k+1;
                else    i=i+k+1;
            }
            if(i==j)    j++;
            k=0;
        }
    }
    return i<j?i:j;
}   //返回是从0开始，如果问第几个需加1

int main()
{
	while(scanf("%s",word)!=EOF)
	{
        wlen=strlen(word);
        getnext(word);
        int t=1,Min,Max;
        if(wlen%(wlen-next[wlen])==0)
            t=wlen/(wlen-next[wlen]);
        Min=getminmax(0);
        Max=getminmax(1);
		printf("%d %d %d %d\n",Min+1,t,Max+1,t);
	}
	return 0;
}