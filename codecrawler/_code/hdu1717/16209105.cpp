#include <stdio.h>
#include <string.h>
int gcd(int m,int n){
    return n==0?m:gcd(n,m%n);
}
int main(){
    char str[20];//è¾å¥çæ°æ®
    char str_temp[20];//ä¸´æ¶åé
    int i,gcd_value;//ä¸´æ¶åé 
    int n;//æ ·ä¾ä¸ªæ°
    int fenzi,fenmu;//éå åé:è¾å¥æ°æ®è½¬æ¢æçå°æ°
    int num,num_bxh;//éå åé:stråstrçä¸å¾ªç¯é¨åè½¬æ¢æçæ°å­å
    int len1,len2;//éå åé:éå¾ªç¯é¨åè¿ä½æ°åå¾ªç¯é¨åè¿ä½æ°

    scanf("%d",&n);

    while (n--){
        scanf("%s",str);
        len1=len2=1;
        for (i=2;str[i]!='('&&str[i]!='\0';i++){
            len1*=10;///len1=10ç éå¾ªç¯é¨åä½æ° æ¬¡æ¹
            str_temp[i-2]=str[i];
        }
        str_temp[i-2]='\0';
        if(strlen(str_temp)==0)    num_bxh=0;
        else
            sscanf(str_temp,"%d",&num_bxh);//å°éå¾ªç¯é¨åè½¬æ¢ææ°å­
        //è¥å­å¨å¾ªç¯å°æ°é¨å
        if(str[i]=='('){
            for (i++;str[i]!=')';i++){
                str_temp[i-3]=str[i];//å°å¾ªç¯é¨åæ·»å å°éå¾ªç¯é¨åå°¾é¨
                len2 *=10;
            }
            str_temp[i-3]='\0';//æ¿æ¢')'ä¸ºç»æç¬¦

            sscanf(str_temp,"%d",&num);//å°å¨é¨å­ç¬¦ä¸²è½¬æ¢ææ°å­
            fenmu = len1*len2-len1;//å¤§è¿ä½æ° å ä¸ä¸ªå¾ªç¯ååçå°è¿ä½æ°
            fenzi = num-num_bxh;//éå¾ªç¯åå¾ªç¯é¨åçæ´æ° åå» éå¾ªç¯é¨åçæ´æ°

            gcd_value=gcd(fenzi,fenmu);
            printf("%d/%d\n",fenzi/gcd_value,fenmu/gcd_value);
        }
        //è¥ä¸å­å¨å¾ªç¯å°æ°é¨å
        else {
            fenzi = num_bxh;//éå¾ªç¯é¨åæ´æ°
            fenmu= len1;//åæ¯ä¸ºå°æ°åæ´æ°éè¦ä¹ä»¥çä½æ°
            gcd_value = gcd(fenzi,fenmu);
            printf("%d/%d\n",fenzi/gcd_value,fenmu/gcd_value);
        }
    }

}