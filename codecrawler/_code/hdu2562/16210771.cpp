#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

char s[55];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> s;
        int len = strlen(s);
        for(int i = 0; i < len; i+=2)
        {
            swap(s[i],s[i+1]);
        }
        cout << s << endl;
    }

    return 0;
}
