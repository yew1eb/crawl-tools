#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[1005];
    while(gets(str)) {
        for(int i = 0; str[i] != '\0'; i++) {
            if(str[i] <= 'Z' && str[i] >= 'A') {
                str[i] = str[i] + 32;
            }
        }
        printf("%s\n", str);
    }
    return 0;
}