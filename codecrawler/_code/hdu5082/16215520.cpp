#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
string s1,s2;
int main()
{
    while(cin>>s1>>s2)
    {
        string s;
        s.clear();
        int i;
        for(i=0;i<s1.size();i++)
        {
            if(s1[i]=='_')
            break;
        }
        for(i=i+1;i<s1.size();i++)
        {
            s.push_back(s1[i]);
        }
        string temp="_small_";
        s=s+temp;
        for(i=0;i<s2.size();i++)
        {
            if(s2[i]=='_')
            break;
        }
        for(i=i+1;i<s2.size();i++)
        {
            s.push_back(s2[i]);
        }
        cout<<s<<endl;
    }
    return 0;
}
