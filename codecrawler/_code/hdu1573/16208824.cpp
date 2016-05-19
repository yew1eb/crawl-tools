#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
void gcd(int a,int b,int &d,int &x,int &y)
{//a*x+b*y=gcd(a,b)=d;(x,y)ä¸ºå¶ä¸ç»æ´æ°è§£
    if(!b){d=a;x=1;y=0;}
    else{ gcd(b,a%b,d,y,x);y-=x*(a/b);}
}
int main()
{
    int n,m,m1,r1,m2,r2,flag=0,a[11],b[11],T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        int i,j,k,d,x,y,c,t;
        for(i=0;i<m;i++)
            cin>>a[i];
        for(i=0;i<m;i++)
            cin>>b[i];
        flag=0;
        m1=a[0];r1=b[0];
        for(i=1;i<m;i++)
        {
            m2=a[i];r2=b[i];
            if(flag)continue;
            gcd(m1,m2,d,x,y);//d=gcd(m1,m2);x*m1+y*m2=d;
            c=r2-r1;
            if(c%d)//å¯¹äºæ¹ç¨m1*x+m2*y=cï¼å¦æcä¸æ¯dçåæ°å°±æ æ´æ°è§£
            {
                flag=1;
                continue;
            }
            t=m2/d;//å¯¹äºæ¹ç¨m1x+m2y=c=r2-r1,è¥(x0,y0)æ¯ä¸ç»æ´æ°è§£,é£ä¹(x0+k*m2/d,y0-k*m1/d)ä¹æ¯ä¸ç»æ´æ°è§£(kä¸ºä»»ææ´æ°)
                    //å¶ä¸­x0=x*c/d,y0=x*c/d;
            x=(c/d*x%t+t)%t;//ä¿è¯x0æ¯æ­£æ°ï¼å ä¸ºx+k*tæ¯è§£ï¼(x%t+t)%tä¹å¿å®æ¯æ­£æ°è§£(å¿å®å­å¨æä¸ªkä½¿å¾(x%t+t)%t=x+k*t)
            r1=m1*x+r1;//æ°æ±çr1å°±æ¯åiç»çè§£ï¼Mi=m1*x+M(i-1)=r2-m2*y(m1ä¸ºåiä¸ªmçæå°å¬åæ°);å¯¹m2åä½æ¶ï¼ä½æ°ä¸ºr2ï¼
                        //å¯¹ä»¥åçmåä½æ¶ï¼Mi%m=m1*x%m+M(i-1)%m=M(i-1)%m=r
            m1=m1*m2/d;
        }
        if(flag||n<r1)cout<<0<<endl;
        else
        {
            int ans=(n-r1)/m1+1;//m1ä¸ºaiçæå°å¬åæ°ï¼å¡æ¯m1*i+r1çé½æ¯ç¬¦åè¦æ±çæ°ï¼å¶ä¸­r1æå°
            if(r1==0)ans--;//è¦æ±æ¯æ­£æ´æ°
            cout<<ans<<endl;
        }
    }
    return 0;
}
/*
    ä¸­å½å©ä½å®ççæ®éæåµï¼aiä¸ä¸å®ç¸äºäºè´¨
*/