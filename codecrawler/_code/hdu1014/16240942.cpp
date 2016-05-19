//Problem:hdu1014
//Data:2011/10/30

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
bool num[100000];        //æ­¤æ°ç»ï¼ä¸æ è¡¨ç¤ºéæºæ°ï¼å¦ææ­¤æ°åºç°ï¼åå¯¹åºçå¼è®¾ä¸ºtrue(åå§å¨ä¸ºfalse) 
int main()
{
    //freopen("E:\\in.txt","r",stdin);
    int step,mod;
    int i,j;
    //bool first = true;
    while(cin>>step>>mod)
    {        
        /*
        if(first)        
            first = false;            
        else
            cout << endl;
        */
        bool result = false;
                
        for(i=0; i<mod; i++)// Every "i" is an initial seed
        {
            bool this_time_isok = true; 
            memset(num, false, mod);
            
            int temp = i;
            num[temp] = true;
            
            while(true)
            {
                temp = (temp + step) % mod;
                
                if(temp == i)    //å¦æç¸ç­ååºç°å¨æäºï¼å ä¸ºæ¯ä¸ªæ°å­çå¤çæ¹å¼åä¸æ · 
                    break;
                    
                num[temp] = true;
            }
            //æ£éªç»æ 
            for(j=0; j<mod; j++)
            {
                if(num[j] == false)
                {
                    this_time_isok = false;
                    break;
                }                    
            }
            
            if(this_time_isok)
            {
                result = true;
                break;
            }            
        }
        
        //è¾åºç»æ 
        //æ³¨æä¸­é´é£éè¾åº4ä¸ªç©ºæ ¼
        //æ¯è¡è¾åºå®åä¸é¢è·ä¸è¡ç©ºè¡ï¼åæ¬æåä¸è¡ 
        cout << setiosflags(ios::right) << setw(10) << step << setw(10) << mod << "    "; 
        cout << setiosflags(ios::left); 
        if(result)
            cout << "Good Choice" << endl << endl;
        else
            cout << "Bad Choice" << endl << endl;
    }
    
    return 0;
}
