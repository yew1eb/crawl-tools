#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
  char   s[100000];
  int i,j;
  while(gets(s))
  {
     j=0;
     while(s[j])j++;
     for(i=0;s[i];i++)
     {
         if((i+4)<j&&s[i]=='A'&&s[i+1]=='p'&&s[i+2]=='p'&&s[i+3]=='l'&&s[i+4]=='e')
            {
                printf("MAI MAI MAI!\n");
                i=i+4;
            }
       else  if((i+5)<j&&s[i]=='i'&&s[i+1]=='P'&&s[i+2]=='h'&&s[i+3]=='o'&&s[i+4]=='n'&&s[i+5]=='e')
       {
           printf("MAI MAI MAI!\n");
                i=i+5;
       }
       else if((i+3)<j&&s[i]=='i'&&s[i+1]=='P'&&s[i+2]=='a'&&s[i+3]=='d')
       {
         printf("MAI MAI MAI!\n");
                i=i+3;
       }
       else if((i+3)<j&&s[i]=='i'&&s[i+1]=='P'&&s[i+2]=='o'&&s[i+3]=='d')
       {
           printf("MAI MAI MAI!\n");
                i=i+3;
       }
       else  if((i+3)<j&&s[i]=='S'&&s[i+1]=='o'&&s[i+2]=='n'&&s[i+3]=='y')
        printf("SONY DAFA IS GOOD!\n");
     }

 }
  return 0;
}