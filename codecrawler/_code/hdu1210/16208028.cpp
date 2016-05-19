#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int flat=1;int k=1;int s=0;   //flatä¸ºæ è®°ç¬¬ä¸å¼ ççä½ç½®ï¼flat=1è¡¨ç¤ºå¨ç¬¬ä¸é¨åï¼flat=0è¡¨ç¤ºå¨ç¬¬äºé¨åãsè¡¨ç¤ºæ´çæ¬¡æ°
        while(1)
        {
            s++;
            if(flat)               //ç¬¬ä¸å¼ çå¨ç¬¬ä¸é¨å
            {
                k=2*k;
                if(k>n)
                {
                    k-=n;flat=0;
                    if(k==1)break;   //å¤å¨ç¬¬äºé¨åï¼ä¸k==1ï¼åä¸æ¬¡æ´çä¸å®è½è¾¾å°åå§ç¶æ
                }
            }
            else                      //ç¬¬ä¸å¼ çå¨ç¬¬äºé¨å
            {
                k=2*(k-1)+1;
                if(k<=n){flat=1;}
                else
                {
                     k-=n;if(k==1)break;   //å¤å¨ç¬¬äºé¨åï¼ä¸k==1ï¼åä¸æ¬¡æ´çä¸å®è½è¾¾å°åå§ç¶æ
                }
            }
        }
        cout<<s+1<<endl;
    }

}