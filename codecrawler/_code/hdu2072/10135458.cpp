#include <stdio.h>
#include <string.h>
#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;

map<string,int> m;

int main()
{
    string str, tmp;
    int i;
    while(getline(cin,str)) {
        if(str =="#") break;
        m.clear();
        i = 0;
        int len = str.size();
        while(i<len){
            tmp = "";
            while(i<len&&'a'<=str[i]&&str[i]<='z') tmp +=str[i++];
            if(tmp !="")
            {
                m[tmp] = 1;
            }
            i++;
        }
        cout<<m.size()<<endl;
    }
    return 0;
}
