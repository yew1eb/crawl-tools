//Problem:hdu2153
//Data:

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    //freopen("E:\\in.txt","r",stdin);
    int n,i,j;
    int data[40000];
    for(i=0; i<40; i++)
        data[i] = i;
    while(cin>>n, n)
    {
        //first line
        for(i=1; i<=n; i++)
        {
            cout << setw(3) <<data[i];        
        }
        cout << endl;
        
        //next n-2 lines
        int a=4*(n-1);
        int b=n+1;
        for(i=1; i<=n-2; i++)
        {
            //æ¯è¡ç¬¬ä¸å 
            cout << setw(3) << data[a--];
            
            //æ¯è¡ä¸­é´çç©ºæ ¼ 
            for(j=0; j<n-2; j++)
                cout << setw(3) << " ";
                
            //æ¯è¡æåä¸å 
            cout << setw(3) << data[b++] << endl;
        }
        
        //last line
        for(i=a; i>=b; i--){
            cout << setw(3) << data[i];        
        }
        cout << endl;
            
    }
    return 0;
}
