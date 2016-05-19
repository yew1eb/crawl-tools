#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int T;
    int hh,mm,ss;
    scanf("%d",&T);
    while(T--) {
        scanf("%d:%d:%d",&hh, &mm, &ss);
        int sum = hh * 60 * 60 + mm * 60 + ss;
        sum %= (12 * 3600);
        int h = sum % (12 * 60 * 60);
        int m = sum % (60 * 60);
        int x = h - m * 12;
        if(x < 0) x = -x;
        int y = 120;
        int z = __gcd(x,y);
        x/=z;y/=z;
        if(x > y * 180) {
            int xx = 360 * y - x;
            int yy = y;
            int zz = __gcd(xx, yy);
            xx /= zz;
            yy /= zz;
            x = xx;
            y = yy;
        }
        if(x == 0 || x % y == 0) {
            printf("%d ", x/ y);
        } else {
            printf("%d/%d ",x,y);
        }

        h = sum % (12 * 60 * 60);
        m = sum % 60;
        x = h - m * 12 * 60;
        if(x < 0) x = -x;
        y = 120;
        z = __gcd(x,y);
        x/=z;y/=z;
        if(x > y * 180) {
            int xx = 360 * y - x;
            int yy = y;
            int zz = __gcd(xx, yy);
            xx /= zz;
            yy /= zz;
            x = xx;
            y = yy;
        }
        if(x == 0 || x % y == 0) {
            printf("%d ", x/ y);
        } else {
            printf("%d/%d ",x,y);
        }

        h = sum % (60 * 60);
        m = sum % 60;
        x = h - m *  60;
        if(x < 0) x = -x;
        y = 10;
        z = __gcd(x,y);
        x/=z;y/=z;
        if(x > y * 180) {
            int xx = 360 * y - x;
            int yy = y;
            int zz = __gcd(xx, yy);
            xx /= zz;
            yy /= zz;
            x = xx;
            y = yy;
        }
        if(x == 0 || x % y == 0) {
            printf("%d ", x/ y);
        } else {
            printf("%d/%d ",x,y);
        }
        puts("");
    }
}