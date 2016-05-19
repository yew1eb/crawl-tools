#include<iostream>
#include<algorithm>
#include<string.h>
const int MAX=260;
char s[MAX];
using namespace std;
int main()
{
    int n,sum,i,j;
    while(gets(s))
    {
        if(s[0]=='#')
        break;
        n=strlen(s);
        sum=0;
        for(i=n;i>=1;i--)
        {
            s[i]=s[i-1];
        }
        for(i=1;i<=n;i++)
        {
            if(s[i]==' ')
            continue;
            if(s[i]=='A')
            sum+=i;if(s[i]=='B')
            sum+=i*2;if(s[i]=='C')
            sum+=i*3;if(s[i]=='D')
            sum+=i*4;if(s[i]=='E')
            sum+=i*5;if(s[i]=='F')
            sum+=i*6;if(s[i]=='G')
            sum+=i*7;if(s[i]=='H')
            sum+=i*8;if(s[i]=='I')
            sum+=i*9;if(s[i]=='J')
            sum+=i*10;if(s[i]=='K')
            sum+=i*11;if(s[i]=='L')
            sum+=i*12;if(s[i]=='M')
            sum+=i*13;if(s[i]=='N')
            sum+=i*14;if(s[i]=='O')
            sum+=i*15;if(s[i]=='P')
            sum+=i*16;if(s[i]=='Q')
            sum+=i*17;if(s[i]=='R')
            sum+=i*18;if(s[i]=='S')
            sum+=i*19;if(s[i]=='T')
            sum+=i*20;if(s[i]=='U')
            sum+=i*21;if(s[i]=='V')
            sum+=i*22;if(s[i]=='W')
            sum+=i*23;if(s[i]=='X')
            sum+=i*24;if(s[i]=='Y')
            sum+=i*25;if(s[i]=='Z')
            sum+=i*26;
        }
        cout<<sum<<endl;
    }
    return 0;
}