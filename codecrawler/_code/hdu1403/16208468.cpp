#include <stdio.h>
#include <string.h>
#define max 1000010

int wa[max],wb[max],wv[max],ws[max];
int rank[max],height[max];
int sa[max],r[max];
char str[max*2];

int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0; i<m; i++) ws[i]=0;
    for(i=0; i<n; i++) ws[x[i]=r[i]]++;
    for(i=1; i<m; i++) ws[i]+=ws[i-1];
    for(i=n-1; i>=0; i--) sa[--ws[x[i]]]=i;
    for(p=1,j=1; p<n; j*=2,m=p)
    {
        for(p=0,i=n-j; i<n; i++) y[p++]=i;
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0; i<n; i++) wv[i]=x[y[i]];
        for(i=0; i<m; i++) ws[i]=0;
        for(i=0; i<n; i++) ws[wv[i]]++;
        for(i=1; i<m; i++) ws[i]+=ws[i-1];
        for(i=n-1; i>=0; i--)
            sa[--ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++ )
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}

void calheight(int *r,int *sa,int n)
{
    int i,j,k=0;
    for(i=1; i<=n; i++)
        rank[sa[i]]=i;
    for(i=0; i<n; height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
}

int main()
{
    while(scanf("%s",str)!=EOF)
    {
        int len=strlen(str);
        int len1=len;
        str[len]='9';
        scanf("%s",str+len1+1);
        len=strlen(str);
        for(int i=0;i<len;i++)
            r[i]=str[i];
        r[len]=0;
        da(r,sa,len,300);
        calheight(r,sa,len);
        int maxint=0;
        for(int i=2; i<len; i++)
        {
            if(maxint<height[i])
            {
                if((sa[i]>len1&&sa[i-1]<len1)||(sa[i]<len1&&sa[i-1]>len1))
                    maxint=height[i];
            }
        }
        printf("%d\n",maxint);
    }
    return 0;
}
