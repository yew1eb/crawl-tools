#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char s[1003];
int main()
{

    while(scanf("%s",s))
    {
        if(strcmp(s,"0")==0)break;
        int sum=0;
        int len=strlen(s);
        if(len==1)
            cout<<s<<endl;
        else
        {
            for(int i=0; i<len; i++)
                sum+=(s[i]-'0');
            sum=sum%9;
            if(sum==0)
                cout<<9<<endl;
            else
                cout<<sum<<endl;
        }

    }
    return 0;
}
