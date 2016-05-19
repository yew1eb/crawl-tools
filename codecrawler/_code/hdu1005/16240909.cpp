//Problem:hdu1005
//Data:2011/10/30
#include <iostream>
using namespace std;

int arr[10000]; 
 
int main()
{
    int A,B,n;
    //freopen("E:\\in.txt","r",stdin);
    arr[1] = arr[2] = 1;
    while(cin>>A>>B>>n, A || B || n)
    {
        int i;
        for(i=3; i<10000 ;i++)
        {
            arr[i] = (A*arr[i-1] + B*arr[i-2]) % 7;
            
            //å¦ææä¸¤ä¸ªè¿ç =1ï¼ååé¢çå¨é¨ååé¢ç¸åï¼å³åºç°äºå¨æ
            //è¿æ¶å°±æ²¡å¿è¦åè¿è¡ä¸å»äºï¼è·³åºå¾ªç¯, i-2ä¸ºå¨æ 
            if(arr[i] == 1 && arr[i-1] == 1)            
                break;
        }
        n = n % (i-2);
        
        // ænå¯¹å¨ææ±æ¨¡ï¼å½n = i-2æ¶, n=0,æ­¤æ¶æ¬æ¥åºè¯¥åarr[i-2]çï¼æä»¥æarr[0]=arr[i-2] 
        //ä¹å¯ä»¥è¿æ ·ï¼
        //if(n==0)     n=i-2; 
                   
        arr[0] = arr[i-2];
        
        cout << arr[n] << endl;
    }
    return 0;
}
