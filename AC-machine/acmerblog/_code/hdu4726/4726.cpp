#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int p[2][10];
char str1[1000050],str2[1000050];
int main ()
{
    int tcase,a,b,num1,num2,i,j,k,tt=1;
    scanf("%d",&tcase);
    gets(str1);
    while(tcase--)
    {
        gets(str1);
        gets(str2);
        num1=0;
        memset(p,0,sizeof(p));
        for(num1=0;str1[num1]!='\0';num1++)
        {
            p[0][str1[num1]-'0']++;
            p[1][str2[num1]-'0']++;
        }
         printf("Case #%d: ",tt++);
        bool flag=true,flag2=true;
        int li;
        for(i=0,li=9;i<num1;i++)
        {

            flag=true;
            for(;li>=0&&flag;li--)
            {
               for(j=0;j<=9&&flag;j++)
               {
                  k=(li-j+10)%10;
                  if(!i&&(!j||!k))
                  {
                    continue;
                  }
                  if(p[0][j]&&p[1][k])
                  {

                      p[0][j]--;p[1][k]--;
                      flag=false;
                      if(flag2&&li!=0)
                      printf("%d",li),flag2=false;
                      else if(!flag2)
                      printf("%d",li);
                      goto my;
                  }
               }
            }
            my:;
            if(!i)
            li=9;
        }
        if(flag2)
        {
            printf("0\n");
        }
        else
        printf("\n");

    }
    return 0;
}
