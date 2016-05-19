#include<stdio.h>
#include<string.h>
#define M 10
char str[M],ch[M];
char a[M],b[M];
int main(){
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        memset(a,'\0',sizeof(a));
        memset(b,'\0',sizeof(b));
        scanf("%s %s",str,ch);
        printf("Case %d: ",cas++);
        //åæ¯è¾ç¬¬ä¸ä¸ªå­æ¯ 
        if(str[0]==ch[0])
            printf("= ");
        else if(str[0]>ch[0])
            printf("> ");
        else 
            printf("< ");
        //å¦æç¬¬äºä¸ªå­æ¯ä¸æ ·çè¯ï¼ç´æ¥æ¯è¾ååä¸ª 
        if(str[1]==ch[1]){
            strncpy(a,str+2,4);
            strncpy(b,ch+2,4);
            if(strcmp(a,b)<0)
                printf("<");
            else if(strcmp(a,b)==0)
                printf("=");
            else 
                printf(">");     
        }else{//ä¸ä¸æ ·å°±æ¯è¾åä¸ä¸ª 
            strncpy(a,str+2,3);
            strncpy(b,ch+2,3);
            if(strcmp(a,b)<0)
                printf("<");
            else if(strcmp(a,b)==0)
                printf("=");
            else 
                printf(">");
             
        }
        printf("\n");
    }
    return 0;
} 