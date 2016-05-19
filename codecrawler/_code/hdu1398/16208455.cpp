#include <iostream>
#include <cstring> 
using namespace std;

int a[305],b[305];
int main()
{
    int n;
    int c[18];
    for(int i = 0; i <= 17; i++)
    {
        c[i] = i*i;
    }
    while(cin>>n&&n!=0)
    {
        for(int i = 0; i <= n; i++)  
        {
            a[i] = 1;
            b[i] = 0;
        }
        for(int i = 2; i <= 17; i++)  
        {
            
            for(int j = 0; j <= n; j++)    //æä¸¾å·²ç¥èå´ ï¼åé¢ææé¡¹ç»æé¡¹ç»æï¼ 
            for(int k = 0; k+j <= n; k+=c[i])  //æä¸¾æ°å¢èå´ï¼ä¸ä¸é¡¹ ï¼ 
            {
                   b[j+k] += a[j];
            }
            for(int j = 0; j <= n; j++)    //éç½® 
            {
                    a[j] = b[j];
                    b[j] = 0;    
            }
        }
        cout<<a[n]<<endl;
    }
} 