#include"stdio.h"
#include"string.h"
int next[50011];
char str1[50011],str2[50011];
void getnext()
{
    int i,k;
    memset(next,0,sizeof(next));
    i=1,k=0,next[i]=k;
    while(str1[i])
    {
        if(k==0 || str1[i]==str1[k])    {next[++i]=++k;}
        else                            k=next[k];
    }
}
int KMP()
{
    int i,j;
    int len1,len2;
    int flag;
    j=1;
    len1=strlen(str1);
    len2=strlen(str2);
    for(i=1;str2[i];)
    {
        if(str2[i]==str1[j])
        {
            i++;j++;
            if(j>len1 && str2[i])    {j=1;i=i-len1+1;}
        }
        else
        {
            j=next[j];
            if(j==0)    {i++;j=1;}
        }
    }
    flag=j;
    if(flag==1)    {if(str1[1]!=str2[len2-1])    flag=0;}
    else flag--;
    return flag;
}
int main()
{
    int i;
    int ans;
    str1[0]='.';
    str2[0]='.';
    while(scanf("%s",str1+1)!=-1)
    {
        scanf("%s",str2+1);
        getnext();
        ans=KMP();
        if(ans<=0)    printf("0\n");
        else
        {
            for(i=1;i<=ans;i++)    printf("%c",str1[i]);
            printf(" %d\n",ans);
        }
    }
    return 0;
}