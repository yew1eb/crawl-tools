/*
 *    Author:
 *        OpenPandora 
 *     Date:
 *          2014.08.24 
 */ 

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cls(a) memset(a,0,sizeof(a))
#define rise(i,a,b) for(int i=a;i<=b;i++)
#define fall(i,a,b) for(int i=a;i>=b;i--)
const int base = 1e9;
char a[600];
bool ined, flag;
int cnt, cntt, ep;
void init()
{
    ined = false; cnt = 0;    
    while( true )
    {
        a[cnt] = getchar();
        if( a[cnt] >= '0' && a[cnt] <= '9' ) 
        {
            ined = true;
            cnt ++;    
        }
        else if( ined ) break;
    }
    a[cnt] = '\0';
    cnt --;
}
struct point
{
    int num[70], len;
    point() { clear(); }
    void clear(){ len = 1 ; cls(num); }
    void out( int x ) 
    { 
        printf( "%d" , num[len] );
        fall( i , len - 1 , 1 ) printf( "%09d" , num[i] );
        if( x )putchar('\n');
        else putchar( ' ' );
    }
    void in()
    {
        init(); cntt = 0; ep = 1; clear();
        fall( i , cnt , 0 )
        {
            if( cntt == 9 )
            {
                cntt = 0;
                len ++;
                ep = 1;
            }
            cntt ++;
            num[len] += (int) ( a[i] - '0' ) * ep;
            ep *= 10;
        }
        while( len > 1 && num[len] == 0 ) len --; 
    }
    void inc()
    {
        num[1] ++;
        rise( i , 1 , len )
        {
            if( num[i] >= base )
            {
                num[i+1] ++;
                num[i] -= base;
            }
            else break;
        }
        if( num[len+1] == 1 ) len ++;
    }
    void dec( int x )
    {
        num[1] -=x;
        rise( i , 1 , len )
        {
            if( num[i] < 0 )
            {
                num[i+1] --;
                num[i] += base;
            }
            else break;
        }
        if( num[len] == 0 ) len --;
    }
    void divid()
    {
        fall( i , len , 1 )
        {
            num[i-1] += ( num[i] & 1 ) * base;
            num[i] >>= 1;
        }
        if( num[len] == 0 ) len --;
    }
    point &operator = ( const point& ); 
    point operator - ( const point& )const; 
    point operator + ( const point& )const;
    point(const int);
    bool operator>(const point &p )const;
    bool operator<(const point &p )const;
    bool operator==(const point &p )const;
}n, m, one, zero, two, now[3], tmp[5], nv[3], tv[5], ans;
point & point :: operator=(const point &p)
{
    clear();
    len = p.len;
    rise( i , 1 , len ) num[i] = p.num[i];
    return *this;
}
point point ::operator+(const point &p)const
{
    point ret = *this;
    int l = max( ret.len , p.len );
    rise( i , 1 , l )
    {
        ret.num[i] += p.num[i];
        if( ret.num[i] >= base ) 
        {
            ret.num[i+1] ++;
            ret.num[i] -= base;
        }
    }
    if( ret.num[l+1] > 0 ) l ++;
    ret.len = l;
    return ret;
}
point point ::operator-(const point &p)const
{
    point ret = *this;
    if( ret > p )
    {
        rise( i , 1 , ret.len )        
        {
            ret.num[i] -= p.num[i];
            
//            cout << ret.num[i] << " " << p.num[i] << endl;
            if( ret.num[i] < 0 ) 
            {
                ret.num[i] += base;
                ret.num[i+1] --;
            }
//            cout << ret.num[i] << endl;
        }
        while( ret.len > 1 )
        if( ret.num[ret.len] == 0 ) ret.len --;
        else break;
        return ret;
    }
    if( ret == p )
    return zero;
    if( ret < p )
    {
        point tmp = ret;
        ret = p;
        rise( i , 1 , ret.len )        
        {
            ret.num[i] -= tmp.num[i];
            if( ret.num[i] < 0 ) 
            {
                ret.num[i] += base;
                ret.num[i+1] --;
            }
        }
        while( ret.len > 1 )
        if( ret.num[ret.len] == 0 ) ret.len --;
        else break;
        return ret;
    }
}
point::point( const int b )
{
    clear();
    num[1] = b;
}
bool point::operator==(const point &p)const
{
    if( len != p.len ) return false;
    fall( i , len , 1 ) if( num[i] != p.num[i] ) return false;
    return true;
}
bool point::operator>(const point &p)const
{
    if( len > p.len ) return true;
    if( len < p.len ) return false;
    fall( i , len , 1 ) 
    {
        if( num[i] > p.num[i] ) return true;
        if( num[i] < p.num[i] ) return false;
    }
    return false;
}
bool point::operator<(const point &p)const
{
    if( len < p.len ) return true;
    if( len > p.len ) return false;
    fall( i , len , 1 ) 
    {
        if( num[i] < p.num[i] ) return true;
        if( num[i] > p.num[i] ) return false;
    }
    return false;
}

int main()
{    
    one = point(1);
    zero = point(0);
    two = point(2);
    int cnt = 1;
    while( true )
    {
        m.in();
        n.in();
        if( n == zero && m == zero ) break;
        if( n > m || n == m )
        {
            ( n - m ).out(1);
            continue;
        }
        now[1] = m;
        ans = m - n;
        cnt = 1;cntt=0;
        while( cnt )
        {
            rise( i , 1 , cnt )
            {
                if( ans > now[i] - n + nv[i] ) ans = now[i] - n + nv[i];
                if( now[i].num[1] % 2 == 0 )
                {
                    flag = 0;
                    rise( j , 1 , cntt )
                    if( now[i] == tmp[j] )
                    {
                        if( nv[i] < tv[j] )
                        tv[j] = nv[i];
                        flag = true;
                    }
                    if( !flag )
                    {
                        tmp[++cntt] = now[i];
                        tv[cntt] = nv[i];
                    }
                }
                else
                {
                	nv[i].inc();
                    flag = false;
                    now[i].inc();
                    rise( j , 1 , cntt )
                    if( now[i] == tmp[j] )
                    {
                        if( nv[i] < tv[j] )
                        tv[j] = nv[i];
                        flag = true;
                    }
                    if( !flag )
                    {
                        tmp[++cntt] = now[i];
                        tv[cntt] = nv[i];
                    }
                    
                    if( now[i] > two ) 
                    {
                        flag = false;
                        now[i].dec(2);
                        rise( j , 1 , cntt )
                        if( now[i] == tmp[j] )
                        {
                            if( nv[i] < tv[j] )
                            tv[j] = nv[i];
                            flag = true;
                        }
                        if( !flag )
                        {
                            tmp[++cntt] = now[i];
                            tv[cntt] = nv[i];
                        }
                    }
                }
                now[i].clear();
                nv[i].clear();
            }
            cnt = 0;
            rise( i , 1 , cntt )
            {
                if( ( tmp[i].len > 1 || tmp[i].num[1] > 2 ) && tmp[i] > n )
                {
                    tmp[i].divid();
                    nv[++cnt] = tv[i] + one;
                    now[cnt] = tmp[i];
                }
                tmp[i].clear();
                tv[i].clear();
            }
            cntt = 0;
        }
        ans.out(1);
    }
    return 0;
}