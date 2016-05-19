#include <iostream>
 #include <cctype>
 #include <cstring>
 #include <string>
 using namespace std;
 
 string s;
 int fun(int ith)
 {
      int k,e;
      char c;
      for(c=s[ith++];ith<s.size()&&c!=')';c=s[ith++])//éå½ç»æçæ¡ä»¶æ¯å­ç¬¦ä¸²ç»ææéå°å³æ¬å· 
      {
           for(k=0;isdigit(c);c=s[ith++])
               k=k*10+c-'0';
           if(!k) k=1;
           if(c=='('){
               while(k--)
                   e=fun(ith);
               ith=e;//éç½®ithçå¼ï¼å°ä¸å±éå½ç»æçä½ç½® 
      }
      else
      {
          while(k--)
              putchar(c);
      }
  }
  if(c==')') return ith;//è¿åæ¬æ¬¡è¯»å°ç»å°¾çä½ç½® 
 }
 int main()
 {
      int i,j,k,T;
      cin>>T;
      while(T--)
      {
           s.clear();
           cin>>s;
           fun(0);//è¿å¥éå½ 
           cout<<endl;
      }
      return 0;
 }