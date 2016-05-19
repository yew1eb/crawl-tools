#include <bits/stdc++.h>

using namespace std;
string s, s1, s2;

int main()
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        string s1;
        string s2;
        cin>>s;
        int len = s.size();
        //cout<<len<<endl;
        for(int i=0; i<len; i++)
        {
            if(i&1) s2 += s[i];
            else s1 += s[i];
        }
        reverse(s2.begin(), s2.end());
        cout<<s1<<endl;
        cout<<s2<<endl;
    }
    return 0;
}

/*
3
abdbdhhfg
andj
jdf

*/
