#include<cstring>
#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX 110
int t,flag;
char a[] = "anniversary",  b[MAX];
bool solve(char s[])
{
    for(int i = 0; i <= 8; i++)
    {
        for(int j = i + 1; j <= 9; j++)
        {
            strcpy(b, a);
            b[i + 1] = 0;
            flag = strstr(s, b) - s;
            if(flag < 0) continue;
            flag += i + 1;
            strcpy(b, a + i + 1);
            b[j - i] = 0;
            flag = strstr(s + flag, b) - s;
            if(flag < 0) continue;
            flag += j - i;
            strcpy(b, a + j + 1);
            b[10- j] = 0;
            flag = strstr(s + flag, b) - s;
            if(flag < 0) continue;
            return true;
        }
    }
    return false;
}
int main()
{
    cin>>t;
    while(t--)
    {
        char s[MAX];
        scanf("%s", s);
        if(solve(s))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}