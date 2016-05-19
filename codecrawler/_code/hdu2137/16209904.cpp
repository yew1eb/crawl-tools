#include<stdio.h>
#include<string.h>
char ch[83];
int main(){
    int i,j,k,n,v,t;
    while(~scanf("%s %d",ch,&t)){
        n=strlen(ch);
        k=t%8;//ååä½å¨è¿è¡ä¸è¾¹å¾ªç¯ï¼å ä¸ºå¦ætæ¯è´çå¾å¤§çæ°ï¼æ§è¡å¾ªç¯å°±ä¼è¶æ¶ 
        while(k<0)
            k+=8;
        if(k==7){
            for(i=0;i<n;i++){
                for(j=0;j<i;j++){
                    printf(" ");
                }
                printf("%c\n",ch[i]);
            }
        }    
        else if(k==6){
            for(i=0;i<n;i++){
                for(j=0;j<n/2;j++){
                    printf(" ");
                }
                printf("%c\n",ch[i]);    
            }        
        }
        else if(k==5){
            for(i=0;i<n;i++){
                for(j=n-1;j>i;j--){
                    printf(" ");
                }
                printf("%c\n",ch[i]);
            }
        }
        else if(k==4){
            for(i=n-1;i>=0;i--){
                printf("%c",ch[i]);
            }
            printf("\n");
        }
        else if(k==3){
            for(i=0;i<n;i++){
                for(j=0;j<i;j++){
                    printf(" ");
                }
                printf("%c\n",ch[n-i-1]);
            }
        }
        else if(k==2){
            for(i=n-1;i>=0;i--){
                for(j=0;j<n/2;j++){
                    printf(" ");
                }
                printf("%c\n",ch[i]);
            }
        }
        else if(k==1){
            for(i=n-1;i>=0;i--){
                for(j=0;j<i;j++){
                    printf(" ");
                }
                printf("%c\n",ch[i]);
            }
        }
        else if(k==0){
                puts(ch);
                        
        }
    }
    return 0;
}