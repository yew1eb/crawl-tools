#include <stdio.h>
#include <string.h>
#define maxn 1002
char s1[maxn], s2[maxn];
int len1, len2, ans, len;

void appx(){
    int num;
    int begin1 = 0, begin2 = len2 - 1;
    while(begin2 >= 0){
        num = 0;
        int i = begin1, j = begin2;
        while(i < len1 && j < len2){
            if(s1[i++] == s2[j++]) ++num;
        }
        if(num > ans) ans = num;
        --begin2;
    }
    begin2 = begin1 = 0;
    while(begin1 < len1){
        num = 0;
        int i = begin1, j = begin2;
        while(i < len1 && j < len2){
            if(s1[i++] == s2[j++]) ++num;
        }
        if(num > ans) ans = num;
        ++begin1;
    }
}
int gcd(int i, int j){
    return !j ? i : gcd(j, i % j);
}
void huajian(){
    int t = gcd(ans, len);
    ans /= t; len /= t;
}

int main(){
    while(scanf("%s", s1), s1[0] != '-'){
        scanf("%s", s2);
        len1 = strlen(s1);
        len2 = strlen(s2);
        ans = 0;
        appx();
        len = len1 + len2;
        ans *= 2;
        printf("appx(%s,%s) = ", s1, s2);
        if(ans == 0 || ans == len){
            printf("%d\n", ans / len);
            continue;
        }
        huajian();
        printf("%d/%d\n", ans, len);
    }
    return 0;
}