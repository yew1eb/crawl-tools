/*
æ¶é´ï¼
    20120314
ä½èï¼
    çå¤§æ´ä»
é®é¢ï¼
Problem DescriptionYour task is to Calculate the sum of some integers.

InputInput contains multiple test cases. Each test case contains a integer N, and then N integers follow in the same line. A test case starting with 0 terminates the input and this test case is not to be processed.

OutputFor each group of input integers you should output their sum in one line, and with one line of output for each line in input. 

Sample Input4 1 2 3 45 1 2 3 4 50  

Sample Output1015
è§£æï¼
    è¯¥é¢ç®ä¸»è¦æ¯è¦æ§å¶è¾å¥æ°æ®çä¸ªæ°ï¼éè¿whileè¿è¡æ§å¶è¾å¥çæ°æ®å¹¶    ä¸å¤æ­
    ç¨åºæ¯ä¸æ¯åºè¯¥ç»æï¼
        ç¬¬äºä¸ªwhileè¯­å¥ä¸ºæ§å¶è¾å¥æ°æ®çä¸ªæ°ï¼å¹¶ä¸è®¡ç®åºè¦æ±å¾å    ï¼
    ç¬¬ä¸éçæ¶ååºç°äºéè¯¯ï¼
    å ä¸ºsumå¨ç¬¬äºæ¬¡è®¡ç®ä¹åæ²¡ææ¸é¶ï¼ï¼ï¼ï¼è¿ç¹å¾éè¦

*/
#include <iostream>
using namespace std;
int main()
{
    int n,a,sum=0;
    while(cin>>n&&n!=0)
    {
        while (n--)
        {
        cin>>a;
        sum=sum+a;
        }
        cout<<sum<<endl;
        sum=0;
    }

    return 0;
}
