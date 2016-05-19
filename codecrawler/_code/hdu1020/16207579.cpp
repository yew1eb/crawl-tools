#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n,i,cnt;
    char str[10005];
    cin >> n;
    while(n--)
    {
        cin >> str;
        for(i = 0; str[i]!='\0';)
        {
            cnt = 1;
            while(str[i] == str[i+1])
            {
                cnt++;
                i++;
            }
            if(cnt == 1)
            cout << str[i];
            else
            cout << cnt << str[i];
            i++;
        }
        cout << endl;
    }

    return 0;
}
