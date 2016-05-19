#include "stdio.h"
#include "stdlib.h"
#include "string.h"


const long  nMax =200012;

long   num[nMax];
long  sa[nMax], rankk[nMax], height[nMax];
long  wa[nMax], wb[nMax], wv[nMax], wd[nMax];

long  cmp(long  *r, long  a, long  b, long  l){
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(long  *r, long  n, long  m){
    long  i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < m; i ++) wd[i] = 0;
    for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;
    for(i = 1; i < m; i ++) wd[i] += wd[i-1];
    for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p){
        for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;
        for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
        for(i = 0; i < n; i ++) wv[i] = x[y[i]];
        for(i = 0; i < m; i ++) wd[i] = 0;
        for(i = 0; i < n; i ++) wd[wv[i]] ++;
        for(i = 1; i < m; i ++) wd[i] += wd[i-1];
        for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++){
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1: p ++;
        }
    }
}

void calHeight(long  *r, long  n){
    long  i, j, k = 0;
    for(i = 1; i <= n; i ++) rankk[sa[i]] = i;
    for(i = 0; i < n; i++){
        for(k ? k -- : 0, j = sa[rankk[i]-1]; r[i+k] == r[j+k]; k ++);
        height[rankk[i]] = k;
    }
}

char str[nMax];
long  ans[nMax];
long  tot[nMax];
long mark[nMax];
long n,k;

int trylen(long r,long le){
    long i,j,count,mar;
    memset(mark, 0, sizeof(short)*nMax);
    mark[sa[r]+le-1]=le;
    for (i=r;height[i]>=le&&i>=1;i--){
        mark[sa[i-1]+le-1]=le;
    }
    mar=le;
    for (i=r+1;i<=n;i++){
        if (height[i]<mar)
            mar=height[i];
        mark[sa[i]+mar-1]=mar;
    }
    for (i=0,count=0,j=-1;i<n-1;i++){
        if (mark[i]>0){
            if ((i-j)>=mark[i]){
                j=i;
                count++;
            }
        }
    }
    if ((count+1)>k)
        return 0;
    else
        return 1;
}

long tryrank(long r){
    long ll,rr,mm;
    ll=height[r]+1;
    rr=n-sa[r];
    if (trylen(r, rr)==0)
        return 0;
    while (ll<rr){
        mm=(ll+rr)/2;
        if (trylen(r, mm))
            rr=mm;
        else
            ll=mm+1;
    }
    return ll;
}

int main(){
    long i,lll,rrr,mmm,an;
    scanf("%ld",&k);
    while (k!=0){
        scanf("%s",str);
        n=strlen(str);
        for (i=0;i<n;i++){
            num[i]=str[i]-'a'+1;
        }
        num[n]=0;
        da(num,n+1,30);
        calHeight(num, n);
        for (lll=1;lll<=n;lll++)
            if (str[sa[lll]]==str[sa[n]])
                break;
        rrr=n;
        while (lll<rrr){
            mmm=(lll+rrr)/2;
            an=tryrank(mmm);
            
            if (an>0){
                rrr=mmm;
            }
            else {
                lll=mmm+1;
            }
        }
        an=tryrank(lll);
        for (i=0;i<an;i++){
            printf("%c",str[sa[lll]+i]);
        }
        printf("\n");
        scanf("%ld",&k);
    }
    return 0;
}