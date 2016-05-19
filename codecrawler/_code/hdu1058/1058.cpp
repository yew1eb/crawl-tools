#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <map>
#include <iostream>
#define MAXN 5850
using namespace std;

int n, a[4] = {2, 3, 5 ,7};
long long ans[MAXN];  


priority_queue<long long, vector<long long>, greater<long long> > q;

map<long long,bool> mp;

void pre()
{ 
    int pos = 1, cnt = 0;
    q.push(pos); 
    mp[1] = 1;
    while (1) {
        long long pos = q.top();
        ans[++cnt] = pos;
        if (cnt >= 5842) {
            break;
        }
        q.pop();
        for (int i = 0; i < 4; ++i) {
            if (!mp.count(pos*a[i])) {
                q.push(pos*a[i]);
                mp[pos*a[i]] = 1;
            }
        }
    }
}

int main()
{
    pre();
    while (scanf("%d", &n), n) {
        if (n % 10 == 1 && n%100 != 11) {
            printf("The %dst humble number is ", n);
        }
        else if (n % 10 == 2 && n%100!= 12) {
            printf("The %dnd humble number is ", n);
        }
        else if (n % 10 == 3 && n%100 != 13) {
            printf("The %drd humble number is ", n);
        }
        else { 
            printf("The %dth humble number is ", n);
        } 
        cout << ans[n] << "." << endl; 
    }
    return 0;
}