//Problem:hdu1017
//Data:2011/10/30

#include <iostream>
using namespace std;
int main()
{
    //freopen("E:\\in.txt","r",stdin);
    int N;
    cin >> N;
    while(N--)
    {
        int cas = 1;
        int n,m;
        int a,b;        
        
        while(cin>>n>>m, n||m)
        {
            int count = 0;
            for(a=1; a<n; a++)
            {
                for(b=a+1; b<n; b++)
                {
                    if((a*a + b*b + m) % (a*b) == 0)
                        count++;
                }
            }
            cout <<"Case "<<cas++<<": "<<count<<endl;
        }
        if(N)
            cout << endl;
    }
    return 0;
}
