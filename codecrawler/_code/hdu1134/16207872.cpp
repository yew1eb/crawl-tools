#include<iostream>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<algorithm>
using namespace std;

#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4

class BigNum
{
private:
    int a[500];    //å¯ä»¥æ§å¶å¤§æ°çä½æ°
    int len;       //å¤§æ°é¿åº¦
public:
    BigNum(){ len = 1;memset(a,0,sizeof(a)); }   //æé å½æ°
    BigNum(const int);       //å°ä¸ä¸ªintç±»åçåéè½¬åä¸ºå¤§æ°
    BigNum(const char*);     //å°ä¸ä¸ªå­ç¬¦ä¸²ç±»åçåéè½¬åä¸ºå¤§æ°
    BigNum(const BigNum &);  //æ·è´æé å½æ°
    BigNum &operator=(const BigNum &);   //éè½½èµå¼è¿ç®ç¬¦ï¼å¤§æ°ä¹é´è¿è¡èµå¼è¿ç®

    friend istream& operator>>(istream&,  BigNum&);   //éè½½è¾å¥è¿ç®ç¬¦
    friend ostream& operator<<(ostream&,  BigNum&);   //éè½½è¾åºè¿ç®ç¬¦

    BigNum operator+(const BigNum &) const;   //éè½½å æ³è¿ç®ç¬¦ï¼ä¸¤ä¸ªå¤§æ°ä¹é´çç¸å è¿ç®
    BigNum operator-(const BigNum &) const;   //éè½½åæ³è¿ç®ç¬¦ï¼ä¸¤ä¸ªå¤§æ°ä¹é´çç¸åè¿ç®
    BigNum operator*(const BigNum &) const;   //éè½½ä¹æ³è¿ç®ç¬¦ï¼ä¸¤ä¸ªå¤§æ°ä¹é´çç¸ä¹è¿ç®
    BigNum operator/(const int   &) const;    //éè½½é¤æ³è¿ç®ç¬¦ï¼å¤§æ°å¯¹ä¸ä¸ªæ´æ°è¿è¡ç¸é¤è¿ç®

    BigNum operator^(const int  &) const;    //å¤§æ°çnæ¬¡æ¹è¿ç®
    int    operator%(const int  &) const;    //å¤§æ°å¯¹ä¸ä¸ªintç±»åçåéè¿è¡åæ¨¡è¿ç®
    bool   operator>(const BigNum & T)const;   //å¤§æ°åå¦ä¸ä¸ªå¤§æ°çå¤§å°æ¯è¾
    bool   operator>(const int & t)const;      //å¤§æ°åä¸ä¸ªintç±»åçåéçå¤§å°æ¯è¾

    void print();       //è¾åºå¤§æ°
};
BigNum::BigNum(const int b)     //å°ä¸ä¸ªintç±»åçåéè½¬åä¸ºå¤§æ°
{
    int c,d = b;
    len = 0;
    memset(a,0,sizeof(a));
    while(d > MAXN)
    {
        c = d - (d / (MAXN + 1)) * (MAXN + 1);
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}
BigNum::BigNum(const char*s)     //å°ä¸ä¸ªå­ç¬¦ä¸²ç±»åçåéè½¬åä¸ºå¤§æ°
{
    int t,k,index,l,i;
    memset(a,0,sizeof(a));
    l=strlen(s);
    len=l/DLEN;
    if(l%DLEN)
        len++;
    index=0;
    for(i=l-1;i>=0;i-=DLEN)
    {
        t=0;
        k=i-DLEN+1;
        if(k<0)
            k=0;
        for(int j=k;j<=i;j++)
            t=t*10+s[j]-'0';
        a[index++]=t;
    }
}
BigNum::BigNum(const BigNum & T) : len(T.len)  //æ·è´æé å½æ°
{
    int i;
    memset(a,0,sizeof(a));
    for(i = 0 ; i < len ; i++)
        a[i] = T.a[i];
}
BigNum & BigNum::operator=(const BigNum & n)   //éè½½èµå¼è¿ç®ç¬¦ï¼å¤§æ°ä¹é´è¿è¡èµå¼è¿ç®
{
    int i;
    len = n.len;
    memset(a,0,sizeof(a));
    for(i = 0 ; i < len ; i++)
        a[i] = n.a[i];
    return *this;
}
istream& operator>>(istream & in,  BigNum & b)   //éè½½è¾å¥è¿ç®ç¬¦
{
    char ch[MAXSIZE*4];
    int i = -1;
    in>>ch;
    int l=strlen(ch);
    int count=0,sum=0;
    for(i=l-1;i>=0;)
    {
        sum = 0;
        int t=1;
        for(int j=0;j<4&&i>=0;j++,i--,t*=10)
        {
            sum+=(ch[i]-'0')*t;
        }
        b.a[count]=sum;
        count++;
    }
    b.len =count++;
    return in;

}
ostream& operator<<(ostream& out,  BigNum& b)   //éè½½è¾åºè¿ç®ç¬¦
{
    int i;
    cout << b.a[b.len - 1];
    for(i = b.len - 2 ; i >= 0 ; i--)
    {
        cout.width(DLEN);
        cout.fill('0');
        cout << b.a[i];
    }
    return out;
}

BigNum BigNum::operator+(const BigNum & T) const   //ä¸¤ä¸ªå¤§æ°ä¹é´çç¸å è¿ç®
{
    BigNum t(*this);
    int i,big;      //ä½æ°
    big = T.len > len ? T.len : len;
    for(i = 0 ; i < big ; i++)
    {
        t.a[i] +=T.a[i];
        if(t.a[i] > MAXN)
        {
            t.a[i + 1]++;
            t.a[i] -=MAXN+1;
        }
    }
    if(t.a[big] != 0)
        t.len = big + 1;
    else
        t.len = big;
    return t;
}
BigNum BigNum::operator-(const BigNum & T) const   //ä¸¤ä¸ªå¤§æ°ä¹é´çç¸åè¿ç®
{
    int i,j,big;
    bool flag;
    BigNum t1,t2;
    if(*this>T)
    {
        t1=*this;
        t2=T;
        flag=0;
    }
    else
    {
        t1=T;
        t2=*this;
        flag=1;
    }
    big=t1.len;
    for(i = 0 ; i < big ; i++)
    {
        if(t1.a[i] < t2.a[i])
        {
            j = i + 1;
            while(t1.a[j] == 0)
                j++;
            t1.a[j--]--;
            while(j > i)
                t1.a[j--] += MAXN;
            t1.a[i] += MAXN + 1 - t2.a[i];
        }
        else
            t1.a[i] -= t2.a[i];
    }
    t1.len = big;
    while(t1.a[len - 1] == 0 && t1.len > 1)
    {
        t1.len--;
        big--;
    }
    if(flag)
        t1.a[big-1]=0-t1.a[big-1];
    return t1;
}

BigNum BigNum::operator*(const BigNum & T) const   //ä¸¤ä¸ªå¤§æ°ä¹é´çç¸ä¹è¿ç®
{
    BigNum ret;
    int i,j,up;
    int temp,temp1;
    for(i = 0 ; i < len ; i++)
    {
        up = 0;
        for(j = 0 ; j < T.len ; j++)
        {
            temp = a[i] * T.a[j] + ret.a[i + j] + up;
            if(temp > MAXN)
            {
                temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
                up = temp / (MAXN + 1);
                ret.a[i + j] = temp1;
            }
            else
            {
                up = 0;
                ret.a[i + j] = temp;
            }
        }
        if(up != 0)
            ret.a[i + j] = up;
    }
    ret.len = i + j;
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}
BigNum BigNum::operator/(const int & b) const   //å¤§æ°å¯¹ä¸ä¸ªæ´æ°è¿è¡ç¸é¤è¿ç®
{
    BigNum ret;
    int i,down = 0;
    for(i = len - 1 ; i >= 0 ; i--)
    {
        ret.a[i] = (a[i] + down * (MAXN + 1)) / b;
        down = a[i] + down * (MAXN + 1) - ret.a[i] * b;
    }
    ret.len = len;
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}
int BigNum::operator %(const int & b) const    //å¤§æ°å¯¹ä¸ä¸ªintç±»åçåéè¿è¡åæ¨¡è¿ç®
{
    int i,d=0;
    for (i = len-1; i>=0; i--)
    {
        d = ((d * (MAXN+1))% b + a[i])% b;
    }
    return d;
}
BigNum BigNum::operator^(const int & n) const    //å¤§æ°çnæ¬¡æ¹è¿ç®
{
    BigNum t,ret(1);
    int i;
    if(n<0)
        exit(-1);
    if(n==0)
        return 1;
    if(n==1)
        return *this;
    int m=n;
    while(m>1)
    {
        t=*this;
        for( i=1;i<<1<=m;i<<=1)
        {
            t=t*t;
        }
        m-=i;
        ret=ret*t;
        if(m==1)
            ret=ret*(*this);
    }
    return ret;
}
bool BigNum::operator>(const BigNum & T) const   //å¤§æ°åå¦ä¸ä¸ªå¤§æ°çå¤§å°æ¯è¾
{
    int ln;
    if(len > T.len)
        return true;
    else if(len == T.len)
    {
        ln = len - 1;
        while(a[ln] == T.a[ln] && ln >= 0)
            ln--;
        if(ln >= 0 && a[ln] > T.a[ln])
            return true;
        else
            return false;
    }
    else
        return false;
}
bool BigNum::operator >(const int & t) const    //å¤§æ°åä¸ä¸ªintç±»åçåéçå¤§å°æ¯è¾
{
    BigNum b(t);
    return *this>b;
}

void BigNum::print()    //è¾åºå¤§æ°
{
    int i;
    cout << a[len - 1];
    for(i = len - 2 ; i >= 0 ; i--)
    {
        cout.width(DLEN);
        cout.fill('0');
        cout << a[i];
    }
    cout << endl;
}
int main(void)
{
    int i,n;
    BigNum x[101];      //å®ä¹å¤§æ°çå¯¹è±¡æ°ç»
    x[0]=1;
    for(i=1;i<101;i++)
        x[i]=x[i-1]*(4*i-2)/(i+1);
    while(scanf("%d",&n)==1 && n!=-1)
    {
        x[n].print();
    }
}
