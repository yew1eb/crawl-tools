#include <stdio.h>
#include <string.h>
char ans[110] ;
char s1[110], s2[110], s3[110] ;
char ss[110] ;
int next[110];
void getnext(char s[]){//kmpç®æ³æ±nextæ°ç»çå¼ 
    int i,j,len=strlen(s);
    i=0;j=-1;
    next[i]=j;
    while(i<len){
        if(j==-1||s[i]==s[j]){
            ++i;++j;
            next[i]=j;
        }
        j=next[j];
    }
}
int kmp(char s[], char p[]){//kmpç®æ³æ ¸å¿ 
    int i, j, len1 = strlen(s), len2 = strlen(p) ;
    getnext(p);
    i=j=0;
    while(i<len1&&j<len2){
        if(j==-1||s[i]==p[j]){
            ++i;++j;
        }
        else j=next[j];
    }
    if(!p[j]) return 1;//å½å­ä¸²æ¯è¾å®æ¯ 
    else return 0;
 }
int test(){
    if (kmp(ss,s2) == 0) return 0;
    if (kmp(ss,s3) == 0) return 0;
    return 1;
}
int main (){
     int T, i, j;
     scanf("%d", &T);
     while(T--){
         scanf("%s%s%s",s1,s2,s3);
         strcpy(ans,"No");//ç¨ä¸ä¸ªansæ°ç»æ¥åä¸´æ¶å¨å­çå­ç¬¦æ°ç» 
         for(i=0;s1[i];i++){//è¿ä¸¤ä¸ªå¾ªç¯å¾å·§å¦ï¼i++å¯ä»¥è®©ä¸»ä¸²çæ¯æ¬¡é½å»æç¬¬ä¸ä¸ªå­æ¯ï¼ççæ¯å¦è¿å¹é
              for(j=i;s1[j];j++){ //å¦æè¿å¹éï¼é£ä¹åæ¥çå°±ä¸æ¯æç­çå­ä¸²ï¼è¿è¦ç»§ç»­è¿è¡ä¸è¾¹ 
                 ss[j-i]=s1[j];
                 ss[j-i+1]='\0';
                 if(test()){
                     if (strcmp(ans,"No")==0||strlen(ss)<strlen(ans)||strcmp(ss,ans)<0)
                         strcpy(ans,ss);//è¾åºçç»æè¦ä¿è¯æç­å­ä¸²ï¼è¿è¦æ¯å­å¸æåºå³bcä¸è½æ¯cbï¼æåçç»æå­å¥anséè¾¹ 
                    break;
                 }
             }
         }
        puts(ans);
     }
     return 0;
 }