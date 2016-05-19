#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#include<stack>
#define cl(a,b) memset(a,b,sizeof(a));
#define LL long long
#define P pair<int,int>
#define X first
#define Y second
#define out(x) cout<<x<<endl;
using namespace std;
const int maxn=20;
const int inf=9999999;

int n;
int a[maxn];
bool pan(){
    for(int i=1;i<=n;i++){
        if(a[i]!=i)return false;
    }
    return true;
}
int limit;///æ·±åº¦éå¶ï¼å¯¹äºf(s)=g(s)+h(s)>limitç´æ¥è·³è¿ï¼sæä¸è¡¨ç¤ºç¶æ
int h(){///ä¼°ä»·å½æ°ï¼è¯¦ç»è§é»ä¹¦169
    int t=0;
    for(int i=0;i<=n;i++){
        if(a[i]+1!=a[i+1])t++;
    }
    return t;
}
bool flag;
void IDA_start(int dept){
    if(pan()||flag){
        flag=true;
        return ;
    }
    if(dept*3+h()>limit*3){
        return ;///å¯åå½æ°ï¼åªæ,å½åçå¯åå½æ°çå¼å¤§äºæ·±åº¦éå¶ï¼ç»æ
    }
    int tmp[maxn];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=j+1;k<=n;k++){///éæ©[i,j]çä¹¦æå¥å°[j+1,k]çæä¸ä½ç½®
               memcpy(tmp,a,sizeof(tmp));
               for(int p=j+1;p<=k;p++){
                    a[p-j-1+i]=tmp[p];
                }
                for(int p=i;p<=j;p++){
                    a[p+k-j]=tmp[p];
                }
                IDA_start(dept+1);
                memcpy(a,tmp,sizeof(tmp));
            }

            for(int k=1;k<=i-1;k++){///éæ©[i,j]çä¹¦æå¥å°[1,i-1]çæä¸ä½ç½®
                memcpy(tmp,a,sizeof(tmp));
                for(int p=k;p<=i-1;p++){
                    a[p+j-i+1]=tmp[p];
                }
                for(int p=i;p<=j;p++){
                    a[p-i+k]=tmp[p];
                }
                IDA_start(dept+1);
                memcpy(a,tmp,sizeof(tmp));
            }
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        bool ok=true;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]!=i)ok=false;
        }
        if(ok){
            puts("0");
            continue;
        }
        a[0]=0;
        a[n+1]=n+1;

        limit=1;
        flag=false;
        while(true){
            IDA_start(0);
            limit++;
            if(flag||limit>=5){
                break;
            }
        }
        if(flag){
            printf("%d\n",limit-1);
        }
        else {
            printf("5 or more\n");
        }

    }
    return 0;
}