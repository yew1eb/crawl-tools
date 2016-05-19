#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
char a[33],b[33];
int main()
{
    int f[55],g[55],i,j,k,s[33],n,T;
    f[0]=1;f[1]=0;
    g[0]=0;g[1]=1;
    for(i=2;i<50;i++)
    {
        f[i]=f[i-1]+f[i-2];
        g[i]=g[i-1]+g[i-2];
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s%d",a,b,&n);
        memset(s,0,sizeof(s));
        for(i=0;a[i]!='\0';i++)
            s[a[i]-'a']+=f[n];
        for(i=0;b[i]!='\0';i++)
            s[b[i]-'a']+=g[n];

        for(i=0;i<26;i++)
            printf("%c:%d\n",i+'a',s[i]);
        printf("\n");
    }
    return 0;
}
/*
    è§å¯å¯ç¥ï¼str[0]ä¸­æ1ä¸ªstr[0],str[1]æ0ä¸ªstr[0],str[2]æ1ä¸ªstr[0]...ï¼ä»èå¾åºf[n]=f[n-1]+f[n-2](n>1),f[1]=0,f[0]=1;,f[n]è¡¨ç¤ºç¬¬str[n]ä¸­çstr[0]çä¸ªæ°ã
    åçå¯å¾g[n]=g[n-1]+g[n-2](n>1),g[1]=1,g[0]=0;g[n]è¡¨ç¤ºstr[n]ä¸­çstr[1]çä¸ªæ°
    ä¹ååªè¦éåä¸str[0]åstr[1]å°±è½å¾å°ç­æ¡äº
*/
