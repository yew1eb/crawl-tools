#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"ctype.h"
#define N 1011
int hash[N][N];
int min(int a,int b){
    return a>b?b:a;
}
int max(int a,int b){
    return a>b?a:b;
}
int main()
{
    char str[511];
    int a,b;
    int i,l,k,sum,ans,d[5];
    int minx,miny,maxx,maxy,mark1,len;
    while(gets(str))
    {
        ans=0;
        len=strlen(str);
        memset(hash,0,sizeof(hash));
        for(i=0;i<len;i++)
        {
            if(str[i]=='(')
            {
                k=0;sum=0;mark1=0;
                for(l=i+1;k<4;l++)
                {
                    if(isdigit(str[l]))    {mark1=1;sum=sum*10+str[l]-'0';}
                    else if(mark1==0)    continue;
                    else    {d[k++]=sum;sum=0;mark1=0;}
                }
                i=l;
                minx=d[0]>d[2]?d[2]:d[0];
                miny=d[1]>d[3]?d[3]:d[1];
                maxx=d[0]>d[2]?d[0]:d[2];
                maxy=d[1]>d[3]?d[1]:d[3];
                for(a=minx;a<maxx;a++)
                for(b=miny;b<maxy;b++)
                    if(!hash[a][b])    {ans++;hash[a][b]=1;}
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}