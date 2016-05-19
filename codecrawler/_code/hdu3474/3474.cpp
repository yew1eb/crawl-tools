#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000005;
struct queuey
{
    int flag,key;
}q[maxn*2];
int r,f;
void insert(int flag,int key)
{
    while(r>f&&key<q[r].key)
        r--;
    q[++r].flag=flag;
    q[r].key=key;
}
void init()
{
    r=f=0;
}
char s[2*maxn],ss[2*maxn];
bool vd[2*maxn];
int sum[2*maxn];
int main()
{
    int c,len,count=0,d=0;    
    scanf("%d",&c);
    while(c--)
    {
        d++;
        scanf("%s",s);
        len=strlen(s);
        for(int i=0;i<len;i++)
            ss[i]=s[i];
        for(int i=0;i<len;i++)
            ss[len+i]=s[i];
        sum[0]=ss[0]=='C'?1:-1;
        init();
        for(int i=1;i<2*len;i++)
            sum[i]=sum[i-1]+(ss[i]=='C'?1:-1);
        count=0;
        memset(vd,0,sizeof(vd));
        for(int i=0;i<2*len;i++)
        {
            insert(i,sum[i]);
            while(q[f+1].flag<=i-len&&r>f)
                f++;
            if(i-len>=0)
            {
                if(q[f+1].key>=sum[i-len])
                    if(vd[i]==0)
                    {
                        count++;
                        vd[i]=1;
                    }
            }
        }
        init();
		sum[2*len]=0;
        sum[2*len-1]=ss[2*len-1]=='C'?1:-1;
        for(int i=2*len-2;i>=0;i--)
        {
            sum[i]=sum[i+1]+(ss[i]=='C'?1:-1);
        }
        for(int i=2*len;i>0;i--)
        {
            insert(i,sum[i]);
            while(q[f+1].flag>=i+len&&r>f)
                f++;
            if(i<=len)
            {
                if(q[f+1].key>=sum[i+len])
                    if(vd[i+len-1]==0)
                    {
                        count++;
                        vd[i+len-1]=1;
                    }
            }
        }
        printf("Case %d: %d\n",d,count);
    }
}