#include<iostream>
#include<cstdio>

using namespace std;

char ch[11111];

int main()
{
    int l, i, j, sum;
    while(cin >> l)
    {
        cin >> ch;
        for(i = 0; i < l; i += 5)
        {
            sum = 0;
            for(j = i; j < i + 5; j++)
            {
                sum *= 2;
                if(ch[j] >= '0' && ch[j] <= '9')
                    sum++;
            }
            cout << char(sum % 26 + 'A');
        }
        cout << endl;
    }
}