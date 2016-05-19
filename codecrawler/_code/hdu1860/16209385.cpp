#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char str[100],s[10];

    while(gets(s))
    {
        if(!strcmp(s,"#"))
        break;
        gets(str);
        int lens = strlen(s),lenstr=strlen(str),i,j;
        for(i = 0;i<lens;i++)
        {
            int num = 0;
            cout << s[i] << " ";
            for(j = 0;j<lenstr;j++)
            {
                if(s[i] == str[j])
                num++;
            }
            cout << num <<endl;
        }
    }

    return 0;
}
