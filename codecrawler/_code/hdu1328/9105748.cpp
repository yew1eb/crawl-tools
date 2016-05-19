#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int i, T, cas;
    cin>>T;
    for(cas=1; cas<=T; cas++) {
        cin>>s;
        for(i=0; i<s.size(); i++) {
            if(s[i]!='Z') s[i]++;
            else s[i] ='A';
        }
        cout<<"String #"<<cas<<endl;
        cout<<s<<endl<<endl;
    }
    return 0;
}

