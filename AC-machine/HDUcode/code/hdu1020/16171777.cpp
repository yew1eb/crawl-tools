/*
        Author:snowflake
        Time:2012/5/13
        Desc:Water
*/
/*
题目大意：统计相等连续字母个数，1个直接输出，>=2输出个数加上一个字符
15ms的代码，很容易懂。。 就是逐位比较 
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    char str[10005];
    int num, i, j;
    cin >> n;
    while(n--)
    {
        scanf("%s",&str);
        int a = 1;//循环增量指针 
        for(i = 0; i < strlen(str); i += a)
        {
            //这两个注意回溯 
            num = 1;
            a = 1;
            for(j = i + 1; j < strlen(str); j++)
            {
                //判断 
                if(str[i] == str[j])
                {
                    num++;
                    a++;//下一次循环从加a的地方开始    
                }    
                else
                    break;    
            }
            if(num == 1)
                printf("%c",str[i]);
            else
                printf("%d%c",num,str[i]);
        }
        printf("\n");
    }
    return 0;
}
