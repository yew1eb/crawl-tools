/*
其实这题才是第一次做 

但是一直不过，也不知道怎么回事儿


就去调了那个简单题做

现在才发现少了main里面的if

还有ok2 是我之前写的，但是少了个{}

题意是，在所给的字符串中找一个子串，最少出现m次，求那个最长的串，并输出最后一次的开始位置

按长度二分，判断是否符合条件即可
*/


#include<stdio.h>
#include<string.h>
const int maxn=500010;


int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
 int sa[maxn],ss[maxn];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)//r[0  n-1]   sa[0    n-1]   最大值小于m
{
    int i,j,p,*x=wa,*y=wb,*t;

    for(i=0; i<m; i++)
        ws[i]=0;
    for(i=0; i<n; i++)
        ws[x[i]=r[i]]++;//x==rank   难道是统计字符个数
    for(i=1; i<m; i++)
        ws[i]+=ws[i-1];//加上前一个
    for(i=n-1; i>=0; i--)
        sa[--ws[x[i]]]=i;//排第[i]的是谁

    for(j=1,p=1; p<n; j*=2,m=p)
    {
        for(p=0,i=n-j; i<n; i++) //变量j是当前字符串的长度，
            y[p++]=i;// 数组y保存的是对第二关键字排序的结果
        for(i=0; i<n; i++)
            if(sa[i]>=j)
                y[p++]=sa[i]-j;

        for(i=0; i<n; i++)
            wv[i]=x[y[i]];
        for(i=0; i<m; i++)
            ws[i]=0;
        for(i=0; i<n; i++)
            ws[wv[i]]++;
        for(i=1; i<m; i++)
            ws[i]+=ws[i-1];
        for(i=n-1; i>=0; i--)
            sa[--ws[wv[i]]]=y[i];

        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}

int rank[maxn],height[maxn];
void calheight(int *r,int *sa,int n)
{
    int i,j,k=0;
    for(i=1; i<=n; i++)
        rank[sa[i]]=i;
    for(i=0; i<n; height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++)
            ;
    return;
}

int pos;
int po;
int ok2(int chang,int ci,int len)
{
    po=-1;
    int zui=-1,f=0;
    int i,jishu=0;
    for(i=2;i<=len;++i)
    {
        if(height[i]>=chang)
        {
            jishu++;
            if(sa[i-1]>=zui) zui=sa[i-1];
            if(sa[i]>zui) zui=sa[i];
            if(jishu>=ci){ f=1;//少了这个括号
            if(zui>po) po=zui;}
        }else
        {
            jishu=0;
            zui=-1;
        }
    }
    if(f)
    {
        return 1;
    }else{
        return 0;
    }
}

bool ok(int x, int m,int n) {
    int i, flag = 0;
    po = -1;
    int tm = 0, tt = -1;
    for (i=2; i<=n; i++) {
        if (height[i] >= x) {
            tm++;
            if (sa[i-1] > tt) tt = sa[i-1];
            if (sa[i] > tt) tt = sa[i];
            if (tm >= m) {
                flag = 1;
            if (tt > po)
                po = tt;
        }
        }
        else {
            tm = 0;
            tt = -1;
        }
    }
    if (flag)
    return true;
    return false;
}
int  main()
{
    int m;
    while(scanf("%d",&m),m)
    {
        getchar();
        char r[maxn];

        gets(r);
        int i;
        int len=strlen(r);
		  if (m == 1) {//少了这个
            printf("%d %d\n", len, 0);
            continue;
        }
        for(i=0; i<len; ++i)
        {
            ss[i]=r[i];
        }
        ss[len]=0;
        da(ss,sa,len+1,128);

        calheight(ss,sa,len);//为什么是len？？？

        int ret =0,hi=len-m+1,low=1,mid,pp;
        po=0;
		pos=0;
        while(hi>=low)
        {
            mid=(hi+low)/2;
            if(ok2(mid,m-1,len))//
            {
                pp=po;
                ret=mid;
                low=mid+1;
            }else
            {
                hi=mid-1;
            }
        }
        if(ret)
        {
            printf("%d %d\n",ret,pp);
        }else
        {
            printf("none\n");
        }
    }
    return 0;
}
