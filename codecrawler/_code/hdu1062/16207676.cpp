#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    for(int k = 0; k < t; k++) {
        char str[1002];
        stack<char> s;
        int index = 0;
        gets(str);
        for(int i = 0; str[i] != '\0'; i++) {
            if(str[i] != ' ') {
                s.push(str[i]);
            }
            else {
                while(!s.empty()) {
                    printf("%c", s.top());
                    s.pop();
                }
                printf(" ");
            }
        }
        while(!s.empty()) {
            printf("%c", s.top());
            s.pop();
        }
        printf("\n");
    }
    return 0;
}