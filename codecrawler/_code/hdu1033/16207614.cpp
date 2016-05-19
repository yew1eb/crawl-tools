#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define LEN 300

int main() {
    char cmd[LEN];
    while(scanf("%s", cmd) != EOF) {
        int i, j, len;
        int x, y, dir;
        dir = 0;
        x = 310;
        y = 420;
        len = strlen(cmd);
        printf("300 420 moveto\n");
        printf("310 420 lineto\n");
        for(i = 0; i < len; i++) {
            if('V' == cmd[i]) {
                if(0 == dir) {
                    y += 10;
                }
                else if(1 == dir) {
                    x += 10;
                }
                else if(2 == dir) {
                    y -= 10;
                }
                else if(3 == dir) {
                    x -= 10;
                }
                dir = (dir+3)%4;
                printf("%d %d lineto\n", x, y);
            }
            else if('A' == cmd[i]) {
                if(0 == dir) {
                    y -= 10;
                }
                else if(1 == dir) {
                    x -= 10;
                }
                else if(2 == dir) {
                    y += 10;
                }
                else if(3 == dir) {
                    x += 10;
                }
                dir = (dir+1)%4;
                printf("%d %d lineto\n", x, y);
            }
        }
        printf("stroke\nshowpage\n");
    }
}
