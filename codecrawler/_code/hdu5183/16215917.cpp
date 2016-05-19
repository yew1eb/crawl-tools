#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXN=1000010;
const int HASH=1000007;

inline LL read()//è¾å¥å¤æ
{
    char ch=getchar();LL x=0,f=1;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct hashmap//å»ºç«åå¸è¡¨
{
    LL a[MAXN];
    int head[HASH],next[MAXN],size;
    void init(){//åå§å
        memset(head,-1,sizeof(head));
        size=0;
    }
    bool find(LL val){//æ¥æ¾ä¸ä¸ªåç´ æ¯å¦å¨åå¸è¡¨å
        int tmp = (val%HASH + HASH)%HASH;
        for(int i = head[tmp];i!=-1;i=next[i])
            if(val==a[i]) return true;
        return false;
    }
    void add(LL val){//æ·»å åç´ å°åå¸è¡¨ä¸­
        int tmp =(val%HASH+HASH)%HASH;
        if(find(val)) return;
        a[size]=val;
        next[size]=head[tmp];
        head[tmp]=size++;
    }
}h1,h2;

LL a[MAXN];

int main()
{
    int t,n,cas=1,k;
    t=read();
    while(t--){
        n=read();
        k=read();
        for(int i=0;i<n;i++)
            a[i]=read();
        LL sum=0;
        h1.init(),h2.init();
        h1.add(0),h2.add(0);
        bool flag = 0;
        for(int i=n-1;i>=0;i--){
            if(i&1) sum-=a[i];
            else sum+=a[i];
            if(i%2==0){
                if(h1.find(sum-k)) flag=1;
            }
            else{
                if(h1.find(sum+k)) flag=1;
            }
            h1.add(sum);
            h2.add(-sum);
            if(flag) break;
        }
        printf("Case #%d: ",cas++);
        if(flag)puts("Yes.");
        else puts("No.");
    }
    return 0;
}
