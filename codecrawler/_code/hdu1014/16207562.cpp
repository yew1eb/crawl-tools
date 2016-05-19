/*
        Author:snowflake
        Time:2012/5/13
        Desc:Water...
*/
/*
é¢ç®çå¤§æï¼å°±æ¯ç»å®ä¸¤ä¸ªæ°step, modç¶åå©ç¨ç»å®çå¬å¼æ±éæºæ°ï¼ä¿è¯ä»0å°modå1èå´å
æ¯ä¸ä¸ªæ°é½åºç°ä¸æ¬¡ãè¿æ ·å°±åç­åå¸äºãå°±æå°Goodå¦åå°±Bad
å°±æ¯æä¸¾äº§çéæºæ°ï¼ç¶åæåºå¨æ¯å¯¹ï¼æ³¨æä¸è¾åºçæ ¼å¼å°±OKäºã 
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 100000 + 10

int random[MAX];

int main()
{
    int step, mod;
    int i;
    bool flag;
    while(cin >> step >> mod)
    {
        flag = true;
        random[0] = 0;
        //ç¬¬ä¸ä¸ªæ°å­æ°¸è¿æ¯0 
        for(i = 1; i <= mod - 1; i++)
        {
            random[i]= (random[i - 1] + step) % mod;
        }
        sort(random, random + mod);
        for(i = 0; i < mod; i++)
        {
            if(random[i] != i)
                flag = false;
        }
        if(flag)
            printf("%10d%10d    Good Choice\n\n",step, mod);
        else
            printf("%10d%10d    Bad Choice\n\n",step, mod);
    }
    return 0;
}
