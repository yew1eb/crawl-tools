#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
using namespace std;

const int MAX = 512;
vector<int> gg[MAX], mm[MAX];
map<string, int> mmmap;
map<string, int> ggmap;
bool rej[MAX][MAX];
int match[MAX];
bool vis[MAX];
string mmlist[MAX], gglist[MAX];
int n;

int loc(int a, int b) {
    for (int i = 0; i < n; ++i) {
        if (mm[a][i] == b) return i;
    }
}

void solve() {
    memset(rej, false, sizeof(rej));
    memset(match, -1, sizeof(match));
    memset(vis, false, sizeof(vis));

    bool ok = true;
     while (ok) {
         ok = false;
         for (int i = 1; i <= n; ++i) {
             if (!vis[i]) {
                 for (int j = 0; j < n; ++j) {
                     int &e = gg[i][j];
                     if (match[e] == -1) {
                         vis[i] = true;
                         match[e] = i;
                         break;
                     } else if (!rej[e][i] && loc(e, i) < loc(e, match[e])) {
                         vis[match[e]] = false;
                         vis[i] = true;
                         match[e] = i;
                         break;
                     } else {
                         rej[e][i] = true;
                     }
                 }
                 ok = true;
             }
         }
     }
     set<pair<string, string> > ans;
     for (int i = 1; i <= n; ++i) {
         ans.insert(make_pair(gglist[match[i]], mmlist[i]));
     }
     for (set<pair<string, string> >::iterator it = ans.begin();
             it != ans.end(); ++it) {
         cout << it->first << " " << it->second << endl;
     }
 }

 int main() {
     cin >> n;
     string name;
     int right = 0;
     for (int i = 1; i <= n; ++i) {
         cin >> name;
         ggmap[name] = i;
         gglist[i] = name;
         for (int j = 1; j <= n; ++j) {
             cin >> name;
             if (mmmap.count(name) == 0) {
                 mmmap[name] = ++right;
                 mmlist[right] = name;
             }
             gg[i].push_back(mmmap[name]);
         }
     }
     for (int i = 1; i <= n; ++i) {
         cin >> name;
         string him;
         for (int j = 1; j <= n; ++j) {
             cin >> him;
             mm[mmmap[name]].push_back(ggmap[him]);
         }
     }
     solve();

     return 0;
 }