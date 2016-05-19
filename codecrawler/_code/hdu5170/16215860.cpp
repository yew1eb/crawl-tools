#include <stdio.h>
#include <math.h>
#define eps 1e-12  //10çè´åäºæ¬¡æ¹
int main()
{
    double a,b,c,d;
    while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d)!=EOF)
    {
        double s,s1;
        s=b*log(a);
        s1=d*log(c);
        if(a==1 &&c==1)  //ç­äº1è¯å®é½æ¯ç¸ç­ç
        {
            printf("=\n");
            continue;
        }  
        if(fabs(s-s1)<eps)     //å¯¹æ°è®¡ç®åï¼ç¸å·®åªè¦ä¸è¶è¿10çè´åäºæ¬¡æ¹ï¼å°±å¯ä»¥è®¤ä¸ºå®ä»¬ç¸ç­ã
            printf("=\n"); 
        else if(s>s1)
            printf(">\n");
        else  if(s<s1)
            printf("<\n");
    }
    return 0;
}