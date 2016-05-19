#include<stdio.h>
int main(){
    int n,p;
    while(~scanf("%d%d",&n,&p)){
        if(n==0 || p>n) {//åªæ 
            printf("Where is hero from?\n");
            continue;
        }
        int cnt=0,ans=0;
        for(int i=1;i<=n/2;i++){
            int temp=n-i+1;
            while(temp%p==0){//æ±åå­ä¸­æå ä¸ªPå å­ 
                cnt++;
                temp/=p;
            }
            temp=i;
            while(temp%p==0){//æ±åæ¯ä¸­æå ä¸ªpå å­ 
                cnt--;
                temp/=p; 
            }
            if(cnt<=0) continue;//åå­ä¸­på å­æ¯åæ¯å¤çæ¶åæè½æ´é¤ 
            if(2*i==n) ans++;//mä¸ºnçä¸åæ¶ 
            else  ans+=2; //mån-mçç»åæ°ä¸æ · 
        }
        if(ans) printf("%d\n",ans);
        else printf("Where is hero from?\n");
    }
    return 0;
} 