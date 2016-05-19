#include<stdio.h>
#include<string.h>
#define N 211
#define M 33
int ans[N][M],len[N];
void init()
{
    int i,l;
    memset(len,0,sizeof(len));
    memset(ans,0,sizeof(ans));
    len[1]=len[2]=1;
    ans[1][0]=1;
    ans[2][0]=2;
    for(i=3;i<=200;i++)
    {
        for(l=0;l<len[i-1];l++)
        {
            ans[i][l]+=ans[i-1][l]+ans[i-2][l];
            ans[i][l+1]+=ans[i][l]/1000000;
            ans[i][l]%=1000000;
        }
        len[i]=len[i-1];
        if(ans[i][len[i]]) len[i]++;
    }
}
int main()
{
    init();
    int T,L,l;
    char str[211];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        L=strlen(str);
        printf("%d",ans[L][len[L]-1]);
        for(l=len[L]-2;l>=0;l--) printf("%06d",ans[L][l]);
        printf("\n");
    }
    return 0;
}