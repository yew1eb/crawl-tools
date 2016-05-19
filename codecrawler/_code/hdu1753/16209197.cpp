#include<cstdio>
#include<cstring>
#include<cmath>
#define Maxn 310

int an[Maxn],ann[Maxn],xn[Maxn],xnn[Maxn];//åå«è¡¨ç¤ºä¸¤æ´æ°å·¦å³ä¸¤é¨å 
    //anè¡¨ç¤ºAçæ´æ°é¨åï¼xnè¡¨ç¤ºBçæ´æ°é¨å,å¦å¤ä¸¤ä¸ªæ¯å°æ°é¨å! 
char st[Maxn],sv[Maxn];//ä¸¤æ´æ°ç¨å­ç¬¦åè¯»å¥ 
void debug(){//è°è¯æç¨ 
    for(int i=0;i<Maxn;i++)
    printf("%d",an[i]);
    puts("");
}
int main(){
    int i,j,k,t;
    bool flaga,flagb;
    while(~scanf("%s %s",st,sv)){
        flaga=flagb=false;//æ è®°æ¯å¦ä¸ºæ´æ° 
        memset(an,0,sizeof(an));//è¿äºè¡memset()æ¯ç¨æ¥æ¸0ç 
        memset(ann,0,sizeof(ann));
        memset(xn,0,sizeof(xn));
        memset(xnn,0,sizeof(xnn));
        for(k=1;st[k]!=0;k++)
        if(st[k]=='.'){//åç°å°æ°ç¹ï¼å·¦å³å­è¿æ°ç» 
            for(i=k-1,t=0;i>=0;i--)    an[t++]=st[i]-'0';
            for(t=0,i=k+1;st[i]!=0;i++) ann[t++]=st[i]-'0';
            flaga=true;
            break;
        }
        if(!flaga){//å¦æAæ¯æ´æ° 
            for(t=0,i=strlen(st)-1;i>=0;i--)
                an[t++]=st[i]-'0';
        }
        for(k=1;sv[k]!=0;k++)
        if(sv[k]=='.'){
            for(i=k-1,t=0;i>=0;i--)    xn[t++]=sv[i]-'0';
            for(t=0,i=k+1;sv[i]!=0;i++) xnn[t++]=sv[i]-'0';
            flagb=true;
            break;
        }
        if(!flagb){//å¦æBä¸ºæ´æ° 
            for(t=0,i=strlen(sv)-1;i>=0;i--)
                xn[t++]=sv[i]-'0';
        }
        if(!flaga&&!flagb){//å¦æé½æ¯æ´æ°åæ­¤if 
            for(i=0;i<Maxn;i++){
                an[i]+=xn[i];
                if(an[i]>9){
                    an[i+1]+=an[i]/10;
                    an[i]%=10;
                }
            }
            bool flag=false;
            for(i=Maxn;i>=0;i--){
                if(flag) printf("%d",an[i]);
                else if(an[i]){
                    flag=true;
                    printf("%d",an[i]);
                }
            }
            puts("");
            continue;
        }
        if(!flaga&&flagb){//Aæ¯æ´æ°ï¼Bä¸æ¯ 
            for(i=0;i<Maxn;i++){
                an[i]+=xn[i];
                if(an[i]>9){
                    an[i+1]+=an[i]/10;
                    an[i]%=10;
                }
            }
            bool flag=false;
            for(i=Maxn-1;i>=0;i--){//å°å¿æ¯maxn-1,æMaxnçæ¶åéäºï¼ 
                if(flag) printf("%d",an[i]);
                else if(an[i]){
                    flag=true;
                    printf("%d",an[i]);
                }
            }
            int sp=-1;
            for(i=Maxn-1;i>=0;i--){
                if(xnn[i]){
                    sp=i;
                    break;
                }
            }
            if(sp==-1){//å¦æå°æ°é¨åå¨é¨æ¯0ä»¥ä¸åæ­¤ 
                puts("");
                continue;
            }
            else{
                printf(".");
                for(i=0;i<=sp;i++)
                printf("%d",xnn[i]);
            }
            puts("");
            continue;
        }
        if(flaga&&!flagb){//Aä¸æ¯æ´æ°ï¼Bæ¯ï¼ 
            for(i=0;i<Maxn;i++){
                an[i]+=xn[i];
                if(an[i]>9){
                    an[i+1]+=an[i]/10;
                    an[i]%=10;
                }
            }

            bool flag=false;
            for(i=Maxn-1;i>=0;i--){
                if(flag) printf("%d",an[i]);
                else if(an[i]){
                    flag=true;
                    printf("%d",an[i]);
                }
            }
            int sp=-1;
            for(i=Maxn-1;i>=0;i--)
                if(ann[i]){
                    sp=i;
                    break;
                }
            if(sp!=-1){
                printf(".");
                for(i=0;i<=sp;i++){
                    printf("%d",ann[i]);
                }
            }
            puts("");
            continue;
        }//ä¸é¢æ¯ AåBé½æ¯æµ®ç¹æ°ï¼ 
        for(i=Maxn-1;i>0;i--){//åå å°æ°é¨å 
            ann[i]+=xnn[i];
            if(ann[i]>9){
                ann[i-1]+=ann[i]/10;
                ann[i]%=10;
            }
        }
        ann[0]+=xnn[0];//ann[0] è¦ç¹å¤å¯è½è¦è¿ä½ 
        if(ann[0]>9){
            an[0]+=ann[0]/10;
            ann[0]%=10;
        }
        for(i=0;i<Maxn;i++){//æ´æ°é¨åç¸å (ä¸å®è¦å¨å°æ°é¨ååå ä¹å) 
            an[i]+=xn[i];
            if(an[i]>9){
                an[i+1]+=an[i]/10;
                an[i]%=10;
            }
        }
        bool flag=false;//ä¸é¢æ¯è¾åº 
        for(i=Maxn-1;i>=0;i--){
            if(flag) printf("%d",an[i]);
            else if(an[i]){
                flag=true;
                printf("%d",an[i]);
            }
        }
        int sp=-1;
        for(i=Maxn-1;i>=0;i--){
            if(ann[i]){
                sp=i;
                break;
            }
        }
        if(sp==-1){
            puts("");
            continue;
        }    
        else{
            printf(".");
            for(i=0;i<=sp;i++)
            printf("%d",ann[i]);
        }
        puts("");
    }
    return 0;
}