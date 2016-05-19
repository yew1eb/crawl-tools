#include<cstring>
#include<fstream>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
bool same(string a,string b)
{
    if(a.size()!=b.size())
        return false;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return a==b;
}
int main()
{
    //fstream cin("d:\\test.txt");
    map<string,int> m; //æå­å¸åºæåº
    string word;
    while(cin>>word)
    {
        if(word=="XXXXXX")
            break;
        ++m[word];
    }

    map<string,int>::const_iterator it;
    while(cin>>word)
    {
        bool matched=false;
        if(word=="XXXXXX")
            break;
        it=m.begin();
        while(it!=m.end())
        {
            if(same(it->first,word))
            {
                matched=true;
                cout<<it->first<<endl;
            }
            ++it;
        }
        if(!matched)
            cout<<"NOT A VALID WORD\n";
        cout<<"******\n";
    }
    return 0;
}
