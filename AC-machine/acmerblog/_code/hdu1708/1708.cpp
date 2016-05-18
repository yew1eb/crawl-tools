#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
long long tag[51][26];
char s1[31],s2[31];
int n;
void Init(char *s1,char *s2)
{
    memset(tag,0,sizeof(tag));
    for(int i=0;s1[i];i++)
        tag[0][s1[i]-'a']++;
    for(int i=0;s2[i];i++)
        tag[1][s2[i]-'a']++;
}
void solve()
{
    Init(s1,s2);
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<26;j++)
            tag[i][j]=tag[i-2][j]+tag[i-1][j];
    }
    for(int i=0;i<26;i++)
        printf("%c:%lld\n",'a'+i,tag[n][i]);
    printf("\n");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s%d",s1,s2,&n);
        solve();
    }
    return 0;
}