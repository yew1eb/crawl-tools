#ifdef _MSC_VER
#define DEBUG
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <stack>
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  stack<char> mstack;
  int ncases;
  char str[200];
  scanf("%d",&ncases);
  getchar();

  for(int nc=1;nc<=ncases;++nc)
  {
      gets(str);
      int len=strlen(str);
      while(!mstack.empty())
          mstack.pop();
      int total=0,maxlen=0;
      for(int i=0;i<len;++i)
          if(str[i]=='[')
          {
              mstack.push('[');
        ++total;
              maxlen=max(total,maxlen);
          }
          else
      {
        --total;
              mstack.pop();
      }
      printf("%d %d\n",nc,1<<maxlen);
  }

  return 0;
}
