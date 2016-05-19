#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define mst(a,b) memset(a,b,sizeof(a))
#define eps 10e-8

const int MAX_ = 1001;
const int N = 100010;
const int INF = 0x7fffffff;

int main() {
    int n, T, k, p;
    map<int, int> m;
    map<int, int>::iterator it;
    map<int, int>::reverse_iterator iter;
    m.clear();
    while(scanf("%d", &n), n){
        switch(n){
            case 1:
            scanf("%d%d", &k, &p);
            m.insert(pair<int, int>(p, k));
            break;
            case 2:
            if(m.empty()){
                printf("0\n");
                break;
            }
            iter = m.rbegin();
            printf("%d\n", iter->second);
            m.erase(iter->first);
            break;
            case 3:
            if(m.empty()){
                printf("0\n");
                break;
            }
            it = m.begin();
            printf("%d\n", it->second);
            m.erase(it);
            break;
        }
    }
    return 0;
}
