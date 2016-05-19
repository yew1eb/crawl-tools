#include <stdio.h>
#include <string.h>
using namespace std;
#define N 100000
char str[N];
bool vis[N];
int main()
{
    int flag = 1, cas = 1;
    while(~scanf("%s",str)) {
        if(str[0]=='9') {
            if(flag)
                printf("Set %d is immediately decodable\n",cas++);
            else
                printf("Set %d is not immediately decodable\n",cas++);
            flag=1;
            memset(vis,0,sizeof(vis));
            continue;
        }
        int j = 1;
        for(int i=0; str[i]; ++i)
        {
            if(str[i]=='0')
                j=j<<1;
            else
                j=j<<1|1;
            if(vis[j]==1)
            {
                flag = 0;
                break;
            }
        }
        vis[j] = 1;
    }
    return 0;
}
