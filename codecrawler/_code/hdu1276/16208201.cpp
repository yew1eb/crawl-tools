#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        while(n--)
        {
            int m,a[5005] = {0},i;
            cin >> m;
            int sum;
            sum = m;
            for(i = 1; i<=m; i++)
            {
                a[i] = i;
            }
            if(m<=3)
            {
                cout << "1";
                for(i = 2; i<=m; i++)
                {
                    if(a[i])
                    {
                        cout << " " << a[i];
                    }
                }
                cout << endl;
                continue;
            }
            while(1)
            {
                int flag = 0;
                for(i = 1; i<=m; i++)
                {
                    if(a[i])
                        flag++;
                    if(flag==2)
                    {
                        a[i] = 0;
                        flag = 0;
                        sum--;
                    }
                }
                if(sum<=3)
                break;
                flag = 0;
                for(i = 1; i<=m; i++)
                {
                    if(a[i])
                        flag++;
                    if(flag==3)
                    {
                        a[i] = 0;
                        flag = 0;
                        sum--;
                    }
                }
                if(sum<=3)
                    break;
            }
            cout << "1";
            sum--;
            for(i = 2; sum; i++)
            {
                if(a[i])
                {
                    cout << " " << a[i];
                    sum--;
                }
            }
            cout << endl;
        }
    }

    return 0;
}
