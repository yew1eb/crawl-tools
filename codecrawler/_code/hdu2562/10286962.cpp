#include <iostream>
using namespace std;
main()
{    int t;
     string s;
     int i, l;
     cin>>t; while(t--){
cin>>s;
for(i=1; s[i]; i += 2)
{
    char ch = s[i];
    s[i] = s[i-1];
    s[i-1] = ch;
}
cout<<s<<endl;
}
}
