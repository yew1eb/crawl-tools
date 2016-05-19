#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

char s[110];

int main()
{
    int N;
    while(cin >> s)
    {
        scanf("%d",&N); //æ¹æcin >> N;å¤é è¿æ è¯­çè¯å¤
        N %= 8;
        if(N < 0)
            N += 8;
        int len = strlen(s);

        if(N == 0)
            cout << s << endl;
        else if(N == 1)
        {
            for(int i = len-1; i >= 0; --i)
            {
                for(int j = i;j > 0; --j)
                    cout << ' ';
                cout << s[i] << endl;
            }
        }
        else if(N == 2)
        {
            for(int i = len-1; i >= 0; --i)
            {
                for(int j = 0; j < (len/2); ++j)
                    cout << ' ';
                cout << s[i] << endl;
            }
        }
        else if(N == 3)
        {
            for(int i = len-1; i >=0; --i)
            {
                for(int j = len-1; j > i; --j)
                    cout << ' ';
                cout << s[i] << endl;
            }
        }
        else if(N == 4)
        {
            for(int i = len-1; i >= 0; --i)
                cout << s[i];
            cout << endl;
        }
        else if(N == 5)
        {
            for(int i = 0; i < len; ++i)
            {
                for(int j = i+1; j < len; ++j)
                    cout << ' ';
                cout << s[i] << endl;
            }
        }
        else if(N == 6)
        {
            for(int i = 0; i < len; ++i)
            {
                for(int j = 0; j < len/2; ++j)
                    cout << ' ';
                cout << s[i] << endl;
            }
        }
        else if(N == 7)
        {
            for(int i = 0; i < len; ++i)
            {
                for(int j = 0; j < i; ++j)
                    cout << ' ';
                cout << s[i] << endl;
            }
        }
        memset(s,0,sizeof(s));
    }

    return 0;
}
