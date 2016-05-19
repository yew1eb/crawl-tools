/*
 * =====================================================================================
 *
 *       Filename:  1437.c
 *
 *
 *        Version:  1.0
 *        Created:  2013å¹´11æ23æ¥ 13æ¶00å07ç§
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wenxian Ni (Hello World~), niwenxianq@qq.com
 *   Organization:  AMS/ICT
 *
 *å¤©æ°æåµ

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 574    Accepted Submission(s): 227


Problem Description
å¦ææä»¬æå¤©æ°åä¸ºé¨å¤©ï¼é´å¤©åæ´å¤©3ç§ï¼å¨ç»å®åç§å¤©æ°ä¹é´è½¬æ¢çæ¦çï¼ä¾å¦é¨å¤©è½¬æ¢æé¨å¤©ï¼é´å¤©åæ´å¤©çæ¦çåå«ä¸º0.4,0.3,0.3.é£ä¹å¨é¨å¤©åçç¬¬äºå¤©åºç°é¨å¤©,é´å¤©åæ´å¤©çæ¦çåå«ä¸º0.4,0.3,0.3.ç°å¨ç»ä½ ä»å¤©çå¤©æ°æåµ,é®ä½ nå¤©åçæç§å¤©æ°åºç°çæ¦ç.
 

Input
æä»¬è¿éåè®¾1,2,3åå«ä»£è¡¨3ç§å¤©æ°æåµ,Pijè¡¨ç¤ºä»iå¤©æ°è½¬æ¢å°jå¤©æ°çæ¦ç.
é¦åæ¯ä¸ä¸ªæ°å­Tè¡¨ç¤ºæ°æ®çç»æ°.
æ¯ç»æ°æ®ä»¥9ä¸ªæ°å¼å§åå«æ¯P11,P12,P13,â¦â¦,P32,P33,æ¥çä¸ä¸è¡æ¯ä¸ä¸ªæ°å­mï¼è¡¨ç¤ºæé®çæ¬¡æ°ãæ¯æ¬¡æé®æ3ä¸ªæ°æ®ï¼i,j,n,è¡¨ç¤ºè¿äºnå¤©ä»iå¤©æ°æåµå°jå¤©æ°æåµ(1<=i,j<=3 1<=n<=1000)ã
 

Output
æ ¹æ®æ¯æ¬¡æé®è¾åºç¸åºçæ¦ç(ä¿ç3ä½å°æ°)ã
 

Sample Input
1
0.4 0.3 0.3 0.2 0.5 0.3 0.1 0.3 0.6
3
1 1 1
2 3 1
1 1 2
 

Sample Output
0.400
0.300
0.250


Hint:å¦æGCæäº¤ä¸æåï¼å¯ä»¥æ¢VCè¯è¯    Description:  
 * =====================================================================================
 */

#include<stdio.h>
#include<string.h>


int main()
{
    int ncase;
    int startd, endd, n;
    int i, j, ask;
    float p[3][3];
    float pend0, pend1, pend2;
    float pend0_t, pend1_t, pend2_t;
    scanf("%d",&ncase);
    while(ncase--)
    {
        for(i=0;i<3;i++) 
        for(j=0;j<3;j++) 
        scanf("%f",&p[i][j]);
        scanf("%d",&ask);
        while(ask--)
        {
            pend0 = pend1 = pend2 = 1.0;
            scanf("%d %d %d",&startd, &endd, &n); 
            pend0 = pend0_t = p[startd-1][0]; 
            pend1 = pend1_t = p[startd-1][1]; 
            pend2 = pend2_t = p[startd-1][2]; 
            for(i=2;i<=n;i++)
            {
                pend0_t = pend0;
                pend1_t = pend1;
                pend2_t = pend2;
                pend0 = p[0][0]*pend0_t + p[1][0]*pend1_t + p[2][0]*pend2_t;
                pend1 = p[0][1]*pend0_t + p[1][1]*pend1_t + p[2][1]*pend2_t;
                pend2 = p[0][2]*pend0_t + p[1][2]*pend1_t + p[2][2]*pend2_t;
            }
            if(endd==1)
            {
                printf("%.3f\n",pend0);
                continue;
            }
            if(endd==2)
            {
                printf("%.3f\n",pend1);
                continue;
            }
            if(endd==3)
            {
                printf("%.3f\n",pend2);
                continue;
            }
        }
    }
    return 0;
}
