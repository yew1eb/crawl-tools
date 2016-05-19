/*  
 * http://acm.hdu.edu.cn/showproblem.php?pid=1097
 *
 */
#include <iostream>
using namespace std;

int main()
{
    //freopen("E:\\input.txt", "r", stdin);
    int a,b;
    int loop[10];
    while(cin>>a>>b)
    {
        a %= 10;
        loop[0] = a;
        loop[1] = a*a % 10;
        int i = 1;
        while(1)
        {
            if(loop[i] == a)
                break;
            else            
                loop[++i] = loop[i-1]*a % 10;
        }
        if(b%i == 0)
            cout << loop[i-1];
        else
            cout << loop[b%i-1];
        cout << endl;
        
    }
    return 0;
}
