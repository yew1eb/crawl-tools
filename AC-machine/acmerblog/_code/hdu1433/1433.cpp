#include <stdio.h>
#include <string.h>
int main ()
{    
      char arr[256];    
      while (scanf ("%s",arr) != EOF)    
      {          
            getchar();          
            int len = strlen (arr) ,count = 0 ,flog = 0;          
            for (int i = len - 1 ;i >= 0 ;i--)          
            {               
                  if (arr[i] >= 'p' && arr[i] <= 'z') count++;               
                  else if (arr[i] == 'C' || arr[i] == 'D' ||arr[i] == 'E' ||arr[i] =='I') count--;               
                  else if (arr[i] == 'N'){}               
                  else flog = 1;          
            }          
            if (!flog && count)printf("YES\n");          
            else printf("NO\n");    
      }    
      return 0;
}