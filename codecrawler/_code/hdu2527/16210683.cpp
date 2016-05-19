#include <set>
#include <cstring>
#include <cstdio>
using namespace std;

char buf[100];
multiset<int> s;
int n,cnt[26];
//éç¨2è¿å¶çåå¤«æ¼,clenè¿å¶æ°
int huffman(char str[],int clen)
{
    s.clear();
    memset(cnt,0,sizeof(cnt));
    int i,tmp,sum;
    for(i=0;i<strlen(str);i++)
    {
        cnt[str[i]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(cnt[i])
        {
            s.insert(cnt[i]);
        }
    }
    if(s.size()==1)
    {
        return *s.begin();
    }
    else
    {
        sum=0;
        while(s.size()>1)
        {
            tmp=0;
            for(i=0;i<clen;i++)
            {
                tmp+=*s.begin();
                s.erase(s.begin());
            }
            s.insert(tmp);
            sum+=tmp;
        }
        return sum;
    }
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%s",&n,buf);
        printf("%s\n",huffman(buf,2)>n?"no":"yes");
    }
    return 0;
}
