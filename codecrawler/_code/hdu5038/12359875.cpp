#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1100000;
int a[maxn], s[maxn];
int n;
int cnt[maxn];
set<int> st;
set<int>::iterator it;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.cpp","r",stdin);
    freopen("out.cpp","w",stdout);
#endif // ONLINE_JUDGE
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof cnt );
        st.clear();
        int Count = 0;
        int unq = -1;
        bool unique = true;
        for(int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            if(unq==-1) {
                unq = a[i];
            } else {
                if(unq != a[i]) {
                    unique = false;
                }
            }
            s[i] = 10000 - (100-a[i])*(100-a[i]);
            cnt[s[i]]++;
            if(st.find(s[i])==st.end()) st.insert(s[i]);
            if(cnt[s[i]]>Count) {
                Count = cnt[s[i]];
            }
        }
        printf("Case #%d:\n", cas);
        bool f = false;
        for(it=st.begin(); it!=st.end(); ++it) {
            if(cnt[*it]!=Count) {
                    f = true;
                    break;
            }
        }
        if(!f){
            if(!unique){
                puts("Bad Mushroom");
            }else {
                printf("%d\n", s[n]);
            }
            continue;
        }
        //=================================
        vector<int> ans;
        for(it=st.begin(); it!=st.end(); ++it) {
            if(cnt[*it]==Count) {
                ans.push_back(*it);
            }
        }
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); ++i) {
            printf("%d", ans[i]);
            if(i<ans.size()-1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}