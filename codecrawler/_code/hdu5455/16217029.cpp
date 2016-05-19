#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
#define ll long long
#define CL(a) memset(a,0,sizeof(a))

char s[1000010];
int main ()
{
    int T;
    cin>>T;
    for (int cas=1; cas<=T; cas++)
    {
        cin>>s;
        cout<<"Case #"<<cas<<": ";

        int k=0;
        bool flag = false;

        if (s[0]==' ')
        {
            cout<<"0"<<endl;
            continue;
        }
        for (int i=0; s[i]; i++,k++)//æ¾å°ç¬¬ä¸ä¸ªc
        {
            if (s[i]!='c'&&s[i]!='f') {flag=true; break;}
            if (s[i]=='c') {break;}
        }
        //cout<<k<<endl;
        if (s[k]=='\0')//è¥å¨ä¸ºfï¼è¾åºæå°ä¸ªæ°
        {
            cout<<k/2+k%2<<endl;
            continue;
        }
        int cnt=0,ans=1;
        for(int i=k+1; s[i]; i++)//ä»ç¬¬ä¸ä¸ªcåé¢å¼å§æ¾
        {
            if (s[i]!='c'&&s[i]!='f') {flag = true; break;}
            if (s[i]!='c') cnt++;
            else
            {
                if (cnt>=2){cnt=0; ans++;}//å¦æcåé¢çfä¸ªæ°å¤§äº2ä¸ªï¼å 1
                else {flag=true; break;}
            }
        }
        if (k+cnt<2) flag=true;//ç¹å¤ï¼å¦æç¬¬ä¸ä¸ªcåé¢çfä¸è¶³2ä¸ª
        if (flag) cout<<"-1"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
