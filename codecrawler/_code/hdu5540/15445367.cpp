#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

string a[20];
string s[5];
int main()
{
#ifdef LOCAL
    freopen("in.h","r", stdin);
    freopen("out.h", "w", stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; ++cas)
    {
        for(int i=0; i<4; ++i) {cin>>a[i]; a[i]+='#';}

        s[0] = a[0] + a[1] + a[3] + a[2];
        s[1] = a[1] + a[3] + a[2] + a[0];
        s[2] = a[3] + a[2] + a[0] + a[1];
        s[3] = a[2] + a[0] + a[1] + a[3];
        //cout<<s[0]<<endl<<s[1]<<endl<<s[2]<<endl<<s[3]<<endl;
        for(int i=0; i<4; ++i) {
            cin>>a[4+i];
            a[4+i] +='#';
        }
        s[4] = a[4] + a[5] + a[7] + a[6];
       // cout<<endl<<s[4]<<endl<<endl;
        printf("Case #%d: ", cas);
        int i = 0;
        for(; i<4; ++i) if(s[i] == s[4]) {
            break;
        }
        puts(i<4?"POSSIBLE":"IMPOSSIBLE");
    }
    return 0;
}



