#include <stdio.h>
#include <string.h>
int main()
{   char str[100000];
     while(gets(str))
    {  for(int i=0; str[i]; ++i)
            if( str[i] >='A' && str[i] <='Z')
                      str[i] += 32;
       puts(str);
     }
    return 0;
}
