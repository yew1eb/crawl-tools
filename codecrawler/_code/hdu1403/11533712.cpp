#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 200000+1000;

struct SuffixArray {
    char s[maxn];
    int sa[maxn],rank[maxn],height[maxn];
    int t1[maxn],t2[maxn],c[maxn],n, m;

    void init(char *str) {
        n = strlen(str);
        strcpy(s, str);
        m = 256;
    }
    void build_sa() {
        int i,*x=t1,*y=t2;
        for(i=0; i<m; i++) c[i]=0;
        for(i=0; i<n; i++) c[x[i]=s[i]]++;
        for(i=1; i<m; i++) c[i]+=c[i-1];
        for(i=n-1; i>=0; i--) sa[--c[x[i]]]=i;
        for(int k=1; k<=n; k<<=1) {
            int p=0;
            for(i=n-k; i<n; i++) y[p++]=i;
            for(i=0; i<n; i++)if(sa[i]>=k) y[p++]=sa[i]-k;
            for(i=0; i<m; i++) c[i]=0;
            for(i=0; i<n; i++) c[x[y[i]]]++;
            for(i=1; i<m; i++) c[i]+=c[i-1];
            for(i=n-1; i>=0; i--) sa[--c[x[y[i]]]]=y[i];
            swap(x,y);
            p=1;
            x[sa[0]]=0;
            for(i=1; i<n; i++)
                x[sa[i]]= y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
            if(p>=n) break;
            m=p;
        }
    }
    void build_height() {
        int i,j,k=0;
        for(i=0; i<n; i++) rank[sa[i]]=i;
        for(i=0; i<n; i++) {
            if(k)k--;
            j=sa[rank[i]-1];
            while(s[i+k]==s[j+k]) k++;
            height[rank[i]]=k;
        }
    }
    void solve(int len1) {
        int ans=0;
        for(int i=2; i<n; i++) {
            if(sa[i]<len1 && sa[i-1]>len1
                    ||sa[i]>len1 && sa[i-1]<len1) {
                ans = max(ans, height[i]);
            }
        }
        printf("%d\n", ans);
    }
};

SuffixArray sa;

char str[maxn];

int main() {
    while(~scanf("%s", str)) {
        int len1 = strlen(str);
        str[len1] = 1;
        scanf("%s", str + len1 + 1);

        sa.init(str);
        sa.build_sa();
        sa.build_height();
        sa.solve(len1);
    }
    return 0;
}
