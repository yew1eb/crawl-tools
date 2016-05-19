#include <cstdio>
#include <cstring>
using namespace std;

char str[1001];
int main()
{
    int len,i,cnt;
    while(~scanf("%s",str))
    {
        len=strlen(str);
        cnt=0;
        for(i=0;i<len;i++)
        {
            if(str[i]=='(')
            {
                cnt++;
            }else if(str[i]==')'){
                cnt--;
            }else{
                break;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
