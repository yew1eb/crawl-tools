/*
æ¶é´ï¼
    2012.03.14
ä½èï¼
    çå¤§æ´ä»
é¢ç®ï¼
    Problem Description
Your task is to calculate the sum of some integers.

Input
Input contains multiple test cases, and one case one line. Each case starts with an integer N, and then N integers follow in the same line. 

Output
For each test case you should output the sum of N integers in one line, and with one line of output for each line in input. 

Sample Input
4 1 2 3 4
5 1 2 3 4 5
 

Sample Output
10
15
é¢ç®åæï¼
    åçå°è¯¥é¢ç®çæ¶åä¼¼ä¹æ¯ä¹ååè¿ï¼å¾é¡ºæçå°±ååºæ¥å¦
    çæ¥å¿è¦çç»ä¹ è¿æ¯æç¨ç
*/
#include <iostream>
using namespace std;
int main()
{
    int n,a,sum=0;
    while(cin>>n)
    {
        sum=0;
        while (n--)
        {
            cin>>a;
            sum=sum+a;
        }

    cout<<sum<<endl;
    }

    return 0;

}
