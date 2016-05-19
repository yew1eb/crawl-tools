#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char s[105];
char a[20];
int main()
{
    int m;
    while(cin>>m,m)
    {
        int suma=0,sumb=0;
        for(int k=1; k<=m; k++)
        {
            getchar();
            gets(s);
            int len=strlen(s);
            if(k % 2 == 1)
            for(int i=0; i<len; i++)
            {
                if(s[len-8] == ' ' && s[len-7] == 'n' && s[len-6] == 'o' && s[len-5] == ' ')
                {
                    //suma=0;
                    a[k]='X';
                    break;
                }
                else //if()
                {
                    suma++;
                    a[k]='O';
                    break;
                }
            }
            else
            for(int i=0; i<len; i++)
            {
                if(s[len-8] == ' ' && s[len-7] == 'n' && s[len-6] == 'o' && s[len-5] == ' ')
                {
                    //sumb=0;
                    a[k]='X';
                    break;
                }
                else //if()
                {
                    sumb++;
                    a[k]='O';
                    break;
                }
            }
        }
        if(m % 2 ==1)
            a[m+1]='-';
        for(int i=1; i<=(m+1)/2; i++)
            cout<<i<<" ";
        cout<<"Score"<<endl;
        for(int i=1; i<=m; i+=2)
        cout<<a[i]<<" ";
        cout<<suma<<endl;
        for(int i=2; i<=m+1; i+=2)
        cout<<a[i]<<" ";
        cout<<sumb<<endl;
    }
    return 0;
}
/*

Sample Input

6
Riise good
Ballack good
Gerrard no good
Lampard no good
Fernando Torres good
Malouda good
9
Christiano Ronaldo no good
Messi no good
Giggs good
Abidal no good
Carrick good
Ronaldinho good
Rooney good
Henry no good
Tevez good
0





Sample Output

1 2 3 Score
O X O 2
O X O 2
1 2 3 4 5 Score
X O O O O 4
X X O X - 1



*/
