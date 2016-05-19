#include"cstdlib"
#include"cstdio"
#include"cstring"
#include"cmath"
#include"queue"
#include"algorithm"
#include"iostream"
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=-1)
    {
        if(n<=3)
        {
            puts("-1");
            continue;
        }
        if(n==4)
        {
            puts("1 * 2");
            puts("5 + 3");
            puts("6 + 4");
            continue;
        }
        if(n==5)
        {
            puts("1 * 2");
            puts("6 * 3");
            puts("7 - 4");
            puts("8 / 5");
            continue;
        }
        if(n==6)
        {
            puts("1 + 2");
            puts("3 + 4");
            puts("5 - 6");
            puts("7 + 8");
            puts("9 + 10");
            continue;
        }
        if(n==7)
        {
            puts("1 + 2");
            puts("8 + 3");
            puts("9 / 4");
            puts("5 / 6");
            puts("7 + 11");
            puts("12 * 10");
            continue;
        }
        if(n==8)
        {
            puts("1 + 2");
            puts("9 + 3");
            puts("5 - 4");
            puts("6 * 11");
            puts("7 * 12");
            puts("8 * 13");
            puts("10 + 14");
            continue;
        }
        if(n==9)
        {
            puts("1 / 2");  //10  1
            puts("3 - 10"); //11  8
            puts("4 + 5");  //12 18
            puts("12 + 6"); //13 27
            puts("13 / 7"); //14  3
            puts("11 * 14");//15 24
            puts("8 - 9");  //16  0
            puts("15 + 16");
            continue;
        }
        if(n==10)
        {
            puts("1 + 2");  //11 20
            puts("3 + 4");  //12 20
            puts("5 + 6");  //13 20
            puts("7 - 8");  //14 0
            puts("9 * 14"); //15 0
            puts("12 + 13");//16 40
            puts("16 / 10");//17 4
            puts("17 + 11");//18 24
            puts("18 + 15");
            continue;
        }
        if(n==11)
        {
            puts("1 + 2");  //12 22
            puts("3 + 4");  //13 22
            puts("13 / 5"); //14 2
            puts("14 + 12");//15 24
            puts("6 - 7");  //16 0
            puts("8 * 16"); //17 0
            puts("9 * 17"); //18 0
            puts("10 * 18");//19 0
            puts("11 * 19");//20 0
            puts("20 + 15");//21 24
            continue;
        }
        if(n==12)
        {
            puts("1 + 2"); //13 2n
            printf("%d + 3\n",n+1); //14 3n
            printf("%d + 4\n",n+2); //15 4n
            printf("%d + 5\n",n+3); //16 5n
            printf("%d + 6\n",n+4); //17 6n
            printf("%d / 7\n",n+5); //18(n+6) 6
            puts("8 + 9"); //19 2n
            printf("%d + 10\n",n+7); //20 3n
            printf("%d + 11\n",n+8); //21 4n
            printf("%d / 12\n",n+9); //22(n+10) 4
            printf("%d * %d\n",n+6,n+10); //23(n+11) 24
            continue;
        }
        if(n==13)
        {
            puts("1 / 2");  //14 1
            puts("3 - 14"); //15 12
            puts("4 + 5");  //16 26
            puts("16 / 6"); //17 2
            puts("15 * 17");//18 24
            puts("7 - 8");  //19 0
            puts("9 * 19"); //20 0
            puts("10 * 20"); //21 0
            puts("11 * 21"); //22 0
            puts("12 * 22"); //23 0
            puts("13 * 23"); //24 0
            puts("24 + 18"); //25 24
            continue;
        }
        puts("1 + 2"); //13 2n
        printf("%d + 3\n",n+1); //14 3n
        printf("%d + 4\n",n+2); //15 4n
        printf("%d + 5\n",n+3); //16 5n
        printf("%d + 6\n",n+4); //17 6n
        printf("%d / 7\n",n+5); //18(n+6) 6
        puts("8 + 9"); //19 2n
        printf("%d + 10\n",n+7); //20 3n
        printf("%d + 11\n",n+8); //21 4n
        printf("%d / 12\n",n+9); //22(n+10) 4
        printf("%d * %d\n",n+6,n+10); //23(n+11) 24
        puts("13 - 14");//n+12 0
        int tep=n+12;
        for(int i=15;i<=n;i++)
        {
            printf("%d * %d\n",i,tep);
            tep++;
        }
        printf("%d + %d\n",n+11,tep);
    }
    return 0;
}
