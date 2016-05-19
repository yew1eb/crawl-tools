#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n , m ;
char mp[155][155] ;
typedef __int64 LL ;  
typedef unsigned __int64 uLL ;

uLL Hash[155][155] ;
uLL xp[155] ;
#define maxn 40005

int wa[maxn],wb[maxn],wv[maxn],wt[maxn];    

int cmp(int *r,int a,int b,int l)    
{return r[a]==r[b]&&r[a+l]==r[b+l];}    
  
void da(int *r,int *sa,int n,int m){    
    int i,j,p,*x=wa,*y=wb,*t;    
    for(i=0;i<m;i++) wt[i]=0;    
    for(i=0;i<n;i++) wt[x[i]=r[i]]++;    
    for(i=1;i<m;i++) wt[i]+=wt[i-1];    
    for(i=n-1;i>=0;i--) sa[--wt[x[i]]]=i;    
    for(j=1,p=1;p<n;j*=2,m=p){    
        for(p=0,i=n-j;i<n;i++) y[p++]=i;    
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;    
        for(i=0;i<n;i++) wv[i]=x[y[i]];    
        for(i=0;i<m;i++) wt[i]=0;    
        for(i=0;i<n;i++) wt[wv[i]]++;    
        for(i=1;i<m;i++) wt[i]+=wt[i-1];    
        for(i=n-1;i>=0;i--) sa[--wt[wv[i]]]=y[i];    
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)    
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;    
    }    
}    
  
int Rank[maxn],height[maxn];    
  
void calheight(int *r,int *sa,int n){    
    int i , j , k = 0 ;    
    for( i=1 ; i<=n ; i++ ) Rank[sa[i]]=i;    
    for(i=0;i<n;i++) {    
        if(k)k--;    
        int j = sa[Rank[i]-1];    
        while(r[i+k]==r[j+k]) k++ ;    
        height[Rank[i]] = k ;    
    }       
    return;    
}    

uLL x[maxn] ;

int lisanhua( int n , uLL * x ) {
	int Index = 1 ;
	for( int i = 1 ; i < n ; i ++ ) {
		if( x[i] != x[i-1] ) 
			x[Index++] = x[i] ;
	}
	return Index - 1 ;
}

int r[maxn] , sa[maxn] ;
int len[maxn] ;

int main(){
	int cas ;
	int casn = 1 ;
	scanf( "%d" , &cas ) ;
	while( cas -- ) {
		scanf( "%d%d" , &n , &m ) ;
		for( int i = 1 ; i <= n ; i ++ )
			scanf( "%s" , mp[i] + 1 ) ;
		memset( Hash , 0 , sizeof(Hash) ) ;
		xp[0] = 1 ;
		for( int i = 1 ; i <= n ; i ++ ) xp[i] = xp[i-1] * 133 ;
		for( int i = 1 ; i <= n ; i ++ ) {
			for( int j = 1 ; j <= m ; j ++ ) {
				Hash[i][j] = Hash[i-1][j] * 133 + mp[i][j] - 'A' ;
			}
		}
		__int64 ans = 0 ;
		// 枚举高度
		for( int h = 1 ; h <= n ; h ++ ) {
			// 离散化用 ， 不然基数排序太苦逼
			int Index = 0 ;
			for( int i = 1 ; i + h - 1 <= n ; i ++ ) {
				for( int j = 1 ; j <= m ; j ++ ) {
					x[Index++] = Hash[i+h-1][j] - Hash[i-1][j] * xp[h] ; 
				}
			}
			sort( x , x + Index ) ;
			Index = lisanhua( Index , x ) ;
			int k = 0 ; 
			memset( len , 0 , sizeof(len) ) ;
			for( int i = 1 ; i + h - 1 <= n; i ++ ) {
				for( int j = 1 ; j <= m; j ++ ) {
					uLL key = Hash[i+h-1][j] - Hash[i-1][j] * xp[h] ;
					int Id = lower_bound( x , x + Index + 1 , key ) - x ;
					len[k] = m - j + 1 ;
					r[k++] = Id + 1 ;
				}
				r[k++] = Index + 5 + i ;
			}
			r[k] = 0 ;
			da( r , sa , k + 1 , Index + n + 50 ) ;
			calheight( r , sa , k ) ;
			ans += len[sa[1]] ;
			for( int i = 2 ; i <= k ; i ++ ) {
				ans += len[sa[i]] - height[i] ;
			}
		}
		printf( "Case #%d: %I64d\n" , casn ++ , ans ) ;
	}
	return 0 ;
}