#include <set>
#include <stdio.h>
using namespace std;
int main()
{
    int n,x;
    set <int> S;
    while(scanf("%d",&n),n)
    {
        while(n--)
        {
            scanf("%d",&x);
            if(S.find(x) == S.end())    //æ²¡æ¾å°ï¼æå¥
                S.insert(x);
            else                        //æ¾å°äºï¼å é¤
                S.erase(x);
        }
        printf("%d\n",*S.begin());
        S.clear();
    }
    return 0;
}