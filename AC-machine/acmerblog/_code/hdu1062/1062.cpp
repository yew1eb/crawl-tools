#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int T;
char str[1000];
int begin,end;


int main()
{
    while(scanf("%d",&T)!=EOF)
    {
          getchar();
          for(int i = 1;i <= T; i++)
          { 
                 gets(str);
                 begin = end = 0;
                 while(str[end] != '\0')
                 {
                        if(str[end] == ' ')
                        {
                             for(int j = end-1; j >= begin; j--)
                             {
                                     printf("%c",str[j]);
                                     
                             }
                             printf(" ");
                             begin = end + 1;
                        }
                        end++;
                  
                 }
                 if(str[end] == '\0')
                 {
                             for(int j = end-1; j>= begin; j--)
                             {
                                     printf("%c",str[j]);
                             }
                 }
                 cout<<endl; 
           }
    }
    return 0;
}