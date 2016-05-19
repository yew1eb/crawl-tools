/*
 * =====================================================================================
 *
 *       Filename:  hdu2071.c
 *
 *
 *        Version:  1.0
 *        Created:  2013å¹´11æ19æ¥ 14æ¶48å00ç§
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wenxian Ni (Hello World~), niwenxianq@qq.com
 *   Organization:  AMS/ICT
 *    Description:  
Max Num

Time Limit: 1000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 11527    Accepted Submission(s): 7381


Problem Description
There are some students in a class, Can you help teacher find the highest student .
 

Input
There are some cases. The first line contains an integer t, indicate the cases; Each case have an integer n ( 1 â¤ n â¤ 100 ) , followed n studentsâ height.
 

Output
For each case output the highest height, the height to two decimal plases;
 

Sample Input
2
3 170.00 165.00 180.00
4 165.00 182.00 172.00 160.00
 

Sample Output
180.00
182.00
 *
 * =====================================================================================
 */

#include <stdio.h>

int main()
{
    int ncase;
    int n;
    float height, max_he;
    scanf("%d",&ncase);
    while(ncase--)
    {
        max_he = 0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%f",&height);
            if(height > max_he)
                max_he = height;
        }
        printf("%.2f\n",max_he);

    }
    return 0;
}
