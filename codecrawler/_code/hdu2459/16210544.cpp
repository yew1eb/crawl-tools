#include <string.h>
#include <math.h>
#include <stdio.h>


int wa[200000],wb[200000],wv[200000],wsum[200000];
int height[200000],sa[200000],rank[200000];
int n,ans,len,pos;
char str[200000];
int R[200000];
int f[200000][20];
int a[200000],num;
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b] && r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++)
        wsum[i]=0;
    for(i=0;i<n;i++)
        wsum[x[i]=r[i]]++;
    for(i=1;i<m;i++)
        wsum[i]+=wsum[i-1];
    for(i=n-1;i>=0;i--)
        sa[--wsum[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++)
            y[p++]=i;
        for(i=0;i<n;i++)
            if(sa[i]>=j)
                y[p++]=sa[i]-j;
        for(i=0;i<n;i++)
            wv[i]=x[y[i]];
        for(i=0;i<m;i++)
            wsum[i]=0;
        for(i=0;i<n;i++)
            wsum[wv[i]]++;
        for(i=1;i<m;i++)
            wsum[i]+=wsum[i-1];
        for(i=n-1;i>=0;i--)
            sa[--wsum[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void calheight(int *r,int *sa,int n)
{
    int i,j,k=0;
    for(i=0;i<=n;i++)
        rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
}
int mmin(int x,int y)
{
    return x<y?x:y;
}
void rmqinit(int n)
{
    int i,j,k,m;
    m=(int)(log(1.0*n)/log(2.0)); 
    for(i=1;i<=n;i++) 
        f[i][0]=height[i]; 
    for(i=1;i<=m;i++) 
        for(j=n;j>=1;j--) 
        { 
            f[j][i]=f[j][i-1]; 
            k=1<<(i-1); 
            if(j+k<=n) 
                f[j][i]=mmin(f[j][i],f[j+k][i-1]); 
        } 
}
int get_rmq(int x,int y) 
{ 
    int m,t; 
    x=rank[x]; 
    y=rank[y]; 
    if(x>y)   
        t=x,x=y,y=t;   
    x++;   
    m=(int)(log(1.0*(y-x+1))/log(2.0));   
    return mmin(f[x][m],f[y-(1<<m)+1][m]);   
}
int main()
{
    int i,j,k,ca=0,l,s,t,p,cnt;
    while(~scanf("%s",str))
    {
        if(str[0]=='#')
            break;
        n=strlen(str);
        for(i=0;i<n;i++)
            R[i]=str[i]-'a'+1;
        R[n]=0;
        da(R,sa,n+1,28);
        calheight(R,sa,n);
        rmqinit(n);
        ans=1;
        num=0;
        pos=0;
        for(l=1;l<=n/2;l++)
        {
            for(i=0;i<n-l;i+=l)
            {
                if(str[i]!=str[i+l])
                    continue;
                k=get_rmq(i,i+l);
                s=k/l+1;
                p=i;
                t=l-k%l;
                cnt=0;
                for(j=i-1;j>=0 && j>i-l && str[j]==str[j+l];j--)
                {
                    cnt++;
                    if(cnt==t)
                    {
                        s++;
                        p=j;
                    }
                    else
                    if(rank[j]<rank[p])
                    {
                        p=j;
                    }
                }
                if(ans<s)
                {
                    pos=p;
                    len=s*l;
                    ans=s;

                }
                else
                if(ans==s && rank[pos]>rank[p])
                {
                    pos=p;
                    len=s*l;
                }

            }
        }
        printf("Case %d: ",++ca);
        if(ans<2)
        {
             char c='z';
             for(i=0;i<n;i++)
                 if(str[i]<c)
                     c=str[i];
             printf("%c\n",c);
             continue;
        }
        for(i=0;i<len;i++)
            printf("%c",str[i+pos]);
        puts("");
    }
    return 0;
}


