#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define M 300
int n,m;
int num[M];
struct node{
    char name[80];
    int kills,rank;
}s[M];
bool cmp(node a,node b){
    if(a.kills!=b.kills)
        return a.kills>b.kills;
    else
        return strcmp(a.name,b.name)<0;
}
int main(){
    char ch[80];
    int i,j;
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++){
            scanf("%s %d",s[i].name,&s[i].kills);
        }
        sort(s,s+n,cmp);
        for(i=0;i<n;i++){
            printf("%s %d\n",s[i].name,s[i].kills);
            s[i].rank=i+1;//åææ¯ä¸ªäººçæååå§å 
        }
        int c=0;//cè®°å½æææ°ä¸æ ·çä¸ªæ° 
        memset(num,0,sizeof(num));
        for(i=1;i<n;i++){
            if(s[i].kills==s[i-1].kills){
                c++; 
                s[i].rank=s[i-1].rank;//å¦ææææ°ä¸æ ·ï¼ä¸»åæ¬¡ä¹ä¸æ · 
                num[i]=c;//num[i]è¡¨ç¤ºiåè¾¹æå ä¸ªåä»æææ°ä¸æ ·ç 
            }else{
                num[i-1]=c;
                c=0;
            }
        }
        scanf("%d",&m);
        while(m--){
            scanf("%s",ch);
            for(i=0;i<n;i++){
                if(strcmp(ch,s[i].name)==0){
                    if(num[i]>0){
                        printf("%d %d\n",s[i].rank,num[i]+1);
                    }
                    else 
                        printf("%d\n",s[i].rank);
                }
            }
        }
    }
    return 0;
} 