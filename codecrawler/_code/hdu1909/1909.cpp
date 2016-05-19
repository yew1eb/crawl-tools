#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <limits>
#include <algorithm>
using namespace std;
const int maxn = 20000;
struct bign{
    int len, s[maxn];
    bign(){memset(s, 0, sizeof(s)); len = 1;}
    bign(int num){*this = num;}
    bign(char *num){*this = num;}
    bign operator = (const char* num){
        len = strlen(num);
        for(int i = 0; i < len; i++)
            s[i] = num[len - i - 1] - '0';//反转
        return *this;
    }
    bign operator = (const int num){
        char s[maxn];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }
    string str() const {
        string res = "";
        for(int i = 0; i < len; i++)
            res = (char)(s[i] + '0') + res;
        if(res == "")
            res = "0";
        return res;
    }
    bign operator + (const bign & b) const {
        bign c;
        c.len = 0;
        for(int i = 0, g = 0; g || i < max(len, b.len); i++){// g 只判断最后是否进位
            int x = g;
            if(i < len) x += s[i];
            if(i < b.len) x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }
    bign operator += (const bign & b) {
        *this = *this + b;
        return *this;
    }
    void clean(){
        while(len > 1 && !s[len - 1])   len--;
    }
    bign operator - (const bign & b){
        bign c; c.len = 0;
        for(int i = 0, g = 0; i < len; i++){
            int x = s[i] - g;
            if(i < b.len)   x -= b.s[i];
            if(x >= 0)  g = 0;
            else {g = 1; x += 10;}
            c.s[c.len++] = x;
        }
        c.clean();
        return c;
    