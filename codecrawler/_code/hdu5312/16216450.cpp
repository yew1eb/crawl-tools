#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<iostream>
using namespace std;
const int maxn = 1e6+5;
map<int,int>Map;
int v[maxn];
int main()
{
    int t;
    for(int i=1;i<=100000;i++){ //é¢å¤ç
        int tmp=3*i*(i-1)+1;
        if(tmp>1e9) break;
        v[i]=tmp;
        Map[tmp]=1;             //ç¨äºåé¢æ¥çæ­¤æ°æ¯å¦è½å¤ç±3*n*(n-1)+1è¡¨ç¤º
    }
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int k=(n-1)%6+1;        //(n-1)%6+1==n%6=0?6:n%6,ä¸¤ç§åæ³é½å¯ä»¥
        if(k>=3){               //k>=3,æ­¤æ¶ä¸å®å­å¨èªç¶æ°è½ç±A1+â¦Akçæ°è¡¨ç¤º
            printf("%d\n",k);
        }
        else if(k==1){          //k==1 æ£éªnæ¯å¦è½ç±è¯¥å¼å­è¡¨ç¤º
            if(Map.count(n)) printf("1\n");
            else printf("7\n");
        }
        else if(k==2){          //k==2ï¼æ£éªnæ¯å¦è½ç±ä¸¤ä¸ªè¯¥å¼å­çæ°è¡¨ç¤º
            int flag=0;
            for(int i=1;v[i]<=n/2;i++){
                if(Map.count(n-v[i])) flag=1;
            }
            if(flag) printf("2\n");
            else printf("8\n");
        }
    }
}
