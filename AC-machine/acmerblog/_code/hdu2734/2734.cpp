#include <iostream>
#include <string>
using namespace std;
int main()
{
    char a[2013];
    int l;
    while(1)
    {
        gets(a);
        if(a[0]=='#')
            break;
        l=strlen(a);
        int i;
        int sum=0;
        for(i=0;i<l;i++)
        switch(a[i])
        {
        case 'A':sum=sum+(i+1)*1;break;
        case 'B':sum=sum+(i+1)*2;break;
        case 'C':sum=sum+(i+1)*3;break;
        case 'D':sum=sum+(i+1)*4;break;
        case 'E':sum=sum+(i+1)*5;break;
        case 'F':sum=sum+(i+1)*6;break;
        case 'G':sum=sum+(i+1)*7;break;
        case 'H':sum=sum+(i+1)*8;break;
        case 'I':sum=sum+(i+1)*9;break;
        case 'J':sum=sum+(i+1)*10;break;
        case 'K':sum=sum+(i+1)*11;break;
        case 'L':sum=sum+(i+1)*12;break;
        case 'M':sum=sum+(i+1)*13;break;
        case 'N':sum=sum+(i+1)*14;break;
        case 'O':sum=sum+(i+1)*15;break;
        case 'P':sum=sum+(i+1)*16;break;
        case 'Q':sum=sum+(i+1)*17;break;
        case 'R':sum=sum+(i+1)*18;break;
        case 'S':sum=sum+(i+1)*19;break;
        case 'T':sum=sum+(i+1)*20;break;
        case 'U':sum=sum+(i+1)*21;break;
        case 'V':sum=sum+(i+1)*22;break;
        case 'W':sum=sum+(i+1)*23;break;
        case 'X':sum=sum+(i+1)*24;break;
        case 'Y':sum=sum+(i+1)*25;break;
        case 'Z':sum=sum+(i+1)*26;break;
        case ' ':sum=sum;break;
        default:break;
        }
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}