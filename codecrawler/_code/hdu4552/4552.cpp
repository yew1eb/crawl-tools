#include <stdio.h>
#include<string.h>
#define maxn 100000+1

#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int c0(int *r,int a,int b)
{return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];}
int c12(int k,int *r,int a,int b)
{if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
 else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];}
void sort(int *r,int *a,int *b,int n,int m)
{
     int i;
     for(i=0;i<n;i++) wv[i]=r[a[i]];
     for(i=0;i<m;i++) ws[i]=0;
     for(i=0;i<n;i++) ws[wv[i]]++;
     for(i=1;i<m;i++) ws[i]+=ws[i-1];
     for(i=n-1;i>=0;i--) b[--ws[wv[i]]]=a[i];
     return;
}
void dc3(int *r,int *sa,int n,int m)      // r为待匹配数组  n为总长度 m为字符范围
{
     int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
     r[n]=r[n+1]=0;
     for(i=0;i<n;i++) if(i%3!=0) wa[tbc++]=i;
     sort(r+2,wa,wb,tbc,m);
     sort(r+1,wb,wa,tbc,m);
     sort(r,wa,wb,tbc,m);
     for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;i++)
     rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
     if(p<tbc) dc3(rn,san,tbc,p);
     else for(i=0;i<tbc;i++) san[rn[i]]=i;
     for(i=0;i<tbc;i++) if(san[i]<tb) wb[ta++]=san[i]*3;
     if(n%3==1) wb[ta++]=n-1;
     sort(r,wb,wa,ta,m);
     for(i=0;i<tbc;i++) wv[wb[i]=G(san[i])]=i;
     for(i=0,j=0,p=0;i<ta && j<tbc;p++)
     sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
     for(;i<ta;p++) sa[p]=wa[i++];
     for(;j<tbc;p++) sa[p]=wb[j++];
     return;
}
int rank[maxn],height[maxn];
void calheight(int *r,int *sa,int n) //  求height数组。
{
     int i,j,k=0;
     for(i=1;i<=n;i++) rank[sa[i]]=i;
     for(i=0;i<n;height[rank[i++]]=k)
     for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
     return;
}
int RMQ[maxn];
int mm[maxn];
int best[20][maxn];//best[i][j] 表示从j开始的长度为2的i次方的一段元素的最小值
void initRMQ(int n)
{
     int i,j,a,b;
     for(mm[0]=-1,i=1;i<=n;i++)
     mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
     for(i=1;i<=n;i++) best[0][i]=i;
     for(i=1;i<=mm[n];i++)
     for(j=1;j<=n+1-(1<<i);j++)
     {
       a=best[i-1][j];
       b=best[i-1][j+(1<<(i-1))];
       if(RMQ[a]<RMQ[b]) best[i][j]=a;
       else best[i][j]=b;
     }
     return;
}
int askRMQ(int a,int b)//询问a,b后缀的最长公共前缀
{
    int t;
    t=mm[b-a+1];b-=(1<<t)-1;
    a=best[t][a];b=best[t][b];
    return RMQ[a]<RMQ[b]?a:b;
}
int lcp(int a,int b)
{
    int t;
    a=rank[a];b=rank[b];
    if(a>b) {t=a;a=b;b=t;}
    return(height[askRMQ(a+1,b)]);
}

char c;
int r[maxn*3],sa[maxn*3];
int ans[maxn];
char str[maxn*3];
int main()
{
    int i,j,n,cas;
      while(scanf("%s",str)!=EOF)
      {
      n=strlen(str);
      for(i=0;i<n;i++)  r[i]=str[i]-'a'+1;
      r[n]=0;
      dc3(r,sa,n+1,30);//千万注意是n+1
      calheight(r,sa,n);
      for(i=1;i<=n;i++)  RMQ[i]=height[i];
      initRMQ(n);

     /*   for(i=0; i<n+1; i++)  // rank[i] : suffix(i)排第几
           printf("rank[%d] =  %d\n",i,rank[i]);
        printf("\n");
        for(i=0; i<n+1; i++)   // sa[i] : 排在第i个的是谁
           printf("sa[%d] =  %d\n",i,sa[i]);
        for(i=0;i<n+1;i++)
            printf("height[%d]=%d\n",i,height[i]);
     */

///     对后缀数组没有直观认识 可以打印出来上面注释的内容
/*
        由于我们是从0开始输入的，所以注意rank的有效下标是从0到n-1的
        sa的下标是从1到n的   height也是从1到n的
*/
        int ans=n%256;
        for(i=1;i<n;i++)
        {
             ans+=lcp(0,i);
        //printf("%d %d\n",i,ans);
             ans%=256;
        }
        printf("%d\n",ans%256);
    }
    return 0;
}
