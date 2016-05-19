#include <iostream>
#include <cstdio>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    list<int> l;
    list<int>::iterator pos = l.begin();
    int lucky[3001];
    int i(2);
    for ( ; i != 35000; ++i)
        l.push_back(i);

    for ( i = 0; i < 3001; ++i ) {
        lucky[i] = l.front();
        int key = lucky[i];
        pos = l.begin();
        while (pos != l.end()) {
            pos = l.erase(pos);
            int k = key - 1;
            while (k--) {
                if(pos == l.end())  break;
                ++pos;
            }
        }
    }

    int n;
    while (scanf("%d", &n), n){
        printf("%d\n", lucky[n - 1]);
    }

}
