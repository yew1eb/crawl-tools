#include <iostream>
#include <algorithm>
using namespace std;
long long a, b, c;

long long tra(long long num) {
    return num > 2 ? 2 : num;
}

int main() {
    while (cin >> a >> b >> c) {
    long long sum = tra(a) + tra(b) + tra(c);
    long long hav = max(0ll, a + b + c - sum);
    cout << (hav * sum + (sum - 1) * sum / 2) << endl;
    }
    return 0;
}