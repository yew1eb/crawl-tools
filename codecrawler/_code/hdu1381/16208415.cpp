#include <iostream>
#include <map>
#include <cstring>
#include <string>
using namespace std;
int test,N,NC;
string  str;
map<string,int> m;
int main()
{
    cin>>test;
    while (test--)
    {
        m.clear();
        cin>>N>>NC;
        cin>>str;
        string temp;
        int i,length;
        length=str.size();
        for(i=0;i<=length-N;++i)
        {
            temp=string(str,i,N);  //æªåå­ç¬¦ä¸²,nä»£è¡¨é¿åº¦
            if(m.count(temp)==0)  ++m[temp];
        }
        cout<<m.size()<<endl;
    }

}