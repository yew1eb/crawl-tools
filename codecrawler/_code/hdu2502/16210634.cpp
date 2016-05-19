//Problem:hdu2502
//Data:2011-11-02

#include <iostream>
using namespace std;

__int64 combination(int n, int m)
{
    //æ±ç»åæ°çå½æ°ï¼è¦ç¨__int64,ä¸ç¶æº¢åº
    //è¿ç¨åºå¾å¼±ï¼åªè½å¤çnè¾å°çæåµ     
    if(m > n/2)
        m = n-m;
        
    __int64 resulT = 1;
    int tempM = m;
    int tempN = n;
    while(tempM--)
    {
        resulT *= tempN--;
    }
    m++;
    while(--m)
    {
        resulT /= m;
    }
    return resulT;
}

int pow(int x)
{
    //æ±2^x 
    int ans = 1;
    while(x--)
    {
        ans *= 2;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int input;
        cin >> input;
        
        //===========first step============== 
        int total = 0;
        total += pow(input-1);
        
        //==========second step============= 
        for(int i=0; i<=input-1; i++)
        {
            total += combination(input-1, i) * i;
        }
        cout << total << endl;
    }
    return 0;
}
