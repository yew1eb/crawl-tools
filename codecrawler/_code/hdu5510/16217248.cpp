#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
char s[505][2005],nextt[2005];

int pd(char *s1,char *s2){
    int i,j,len1,len2;
    len1=strlen(s1);
    len2=strlen(s2);
    i=0;j=-1;
    memset(nextt,-1,sizeof(nextt));
    while(i<len2){
        if(j==-1 || s2[i]==s2[j]){
            i++;
            j++;
            nextt[i]=j;
        }
        else j=nextt[j];
    }
    i=0;j=0;
    while(i<len1 && j<len2){
        if(j==-1 || s1[i]==s2[j]){
            i++;
            j++;
        }
        else j=nextt[j];
    }
    if(j>=len2)
    return 1;
    else return 0;
}


int main()
{
    int T,n,m,i,j,ans,num,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ans=-1;
        for(i=1;i<=n;i++){
            scanf("%s",s[i]);
        }
        j=1;
        for(i=2;i<=n;i++){     //è¿éç¨ä¸¤ä¸ªæéï¼iæå½åä½ç½®ï¼jæéåå°åªä¸ªä¸²
            while(j<i && pd(s[i],s[j]) )j++;
            if(j<i)ans=i;
        }
        cas++;
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
