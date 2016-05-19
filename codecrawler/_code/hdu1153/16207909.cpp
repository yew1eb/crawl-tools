#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

int main () {
    long long p;
    while ((std::cin >> p) && p) {
        if (p == 2) {
            std::cout << "Impossible\n";
            continue;
        }
        std::vector <int> v (p, 1);
        for (long long i=1; i<p; ++i) {
            v [i * i % p] = 0;
        }
        std::copy (v.begin() + 1, v.end(), std::ostream_iterator <int> (std::cout));
        std::cout << "\n";
    }
    return 0;
}
