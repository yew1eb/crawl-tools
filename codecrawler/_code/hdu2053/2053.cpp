/*
 * =====================================================================================
 *
 *       Filename:  hdu2053.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年11月17日 22时05分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wenxian Ni (Hello World~), [email protected]/* <![CDATA[ */!function(t,e,r,n,c,a,p){try{t=document.currentScript||function(){for(t=document.getElementsByTagName('script'),e=t.length;e--;)if(t[e].getAttribute('data-cfhash'))return t[e]}();if(t&&(c=t.previousSibling)){p=t.parentNode;if(a=c.getAttribute('data-cfemail')){for(e='',r='0x'+a.substr(0,2)|0,n=2;a.length-n;n+=2)e+='%'+('0'+('0x'+a.substr(n,2)^r).toString(16)).slice(-2);p.replaceChild(document.createTextNode(decodeURIComponent(e)),c)}p.removeChild(t)}}catch(u){}}()/* ]]> */
 *   Organization:  AMS/ICT
 *Switch Game

Time Limit: 1000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 9223    Accepted Submission(s): 5515


Problem Description
There are many lamps in a line. All of them are off at first. A series of operations are carried out on these lamps. On the i-th operation, the lamps whose numbers are the multiple of i change the condition ( on to off and off to on ).
 

Input
Each test case contains only a number n ( 0< n<= 10^5) in a line.
 

Output
Output the condition of the n-th lamp after infinity operations ( 0 - off, 1 - on ).
 

Sample Input
1
5
 

Sample Output
1
0

Hint
hint
 

Consider the second test case:

The initial condition	   : 0 0 0 0 0 …
After the first operation  : 1 1 1 1 1 …
After the second operation : 1 0 1 0 1 …
After the third operation  : 1 0 0 0 1 …
After the fourth operation : 1 0 0 1 1 …
After the fifth operation  : 1 0 0 1 0 …

The later operations cannot change the condition of the fifth lamp any more. So the answer is 0.
 * =====================================================================================
 */

#include <stdio.h>
int main()
{
    int n;
    int i;
    int count;
    while(~scanf("%d",&n))
    {
        count = 0;
        for(i=1;i<=n;i++)
        {
            if(n%i == 0)
                count++;
        }
        
        if(count%2==0)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}