#include <iostream>
using namespace std;
int main()  
{ 
    int t, res, n;  
    scanf ("%d", &t);  
    while (t--)  
    {  
        res = 0;  
        scanf ("%d", &n);  
        while (n)  
        {  
            res += n / 5;  
            n /= 5;  
        }  
        printf ("%d\n", res);  
    }  
    return 0;  
}  