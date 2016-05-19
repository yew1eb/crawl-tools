#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>


using namespace std;

const int MAXX = 102;

int weights[MAXX],cnt[MAXX],pos;
int res[MAXX*MAXX], tmp[MAXX*MAXX], cc[MAXX*MAXX];
vector<int> pr;

int main(){
    int n,s,weight,ans;

    while (cin >> n){
        s = 0;
        pos = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i){
            cin >> weight;
            s += weight;
            if (cnt[weight] == 0){
                weights[pos++] = weight;
            }
            ++cnt[weight];
        }

        memset(res, 0, sizeof(res));
        memset(tmp, 0, sizeof(tmp));

        //æ¯å½æ°çç»å¸ä»£ç 
        for (int i = 0; i <= cnt[weights[0]]; ++i){
            res[i*weights[0]] = 1;
        }

        for (int i = 1; i < pos; ++i){
            for (int j = 0; j <= s; ++j){
                for (int k = 0; k <= cnt[weights[i]] && k*weights[i] + j <= s; ++k){
                    tmp[k*weights[i] + j] += res[j];
                }
            }

            for (int j = 0; j <= s; ++j){
                res[j] = tmp[j];
                tmp[j] = 0;
            }
        }

        //è®¡ç®å·®å¼åå¤©å¹³çä¸¤éé½æ¾ç ç æ¶å¯ç§°åºçéé
        memset(cc, 0, sizeof(cc));
        for (int i = 0; i <= s; ++i){
            for (int j = i+1; j <= s; ++j){
                if (res[i] != 0 && res[j] != 0){
                    cc[j - i] = 1;
                }
            }
        }


        ans = 0;
        pr.clear();

        for (int i = 0; i <= s; ++i){
            if (res[i] == 0 && cc[i]==0){
                ++ans;
                pr.push_back(i);
            }
        }

        cout << ans << endl;

        if (ans == 0)continue;

        for (int i = 0; i < ans; ++i){
            cout << pr[i];
            if (i != ans - 1){
                cout << " ";
            }
        }
        cout << endl;
    }
}