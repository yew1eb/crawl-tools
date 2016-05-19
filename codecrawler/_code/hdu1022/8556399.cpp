#include <cstdio>
#include <stack>
using namespace std;


char A[100], B[100];
int ap, bp, n;
int list[200], t;
int main() {
    while( scanf("%d %s %s",&n, A, B)!=EOF) {
        stack<char> s;/*ÓôÃÆ,ÏÈ°Ñstack¶¨ÒåÔÚÍâÃæÁË,
        ¿ÉÄÜ»áÒòÎªÉÏ´Î²»³É¹¦,¶øÊ¹µ±Ç°Ê¹ÓÃÕ»sÊ±²ÐÁôÓÐÉÏÒ»´ÎµÄ*/
        ap = bp = t = 0;
        bool flag = true;
        while(bp<n) {
            if(!s.empty() && s.top()==B[bp]) {
                s.pop();
                bp++;
                list[t++] = 0;
            } else if(ap<n) {
                s.push(A[ap++]);
                list[t++] = 1;
            } else {
                flag = false ;
                break;
            }
        }
        if(!flag) printf("No.\nFINISH\n");
        else {
            printf("Yes.\n");
            for(int i=0; i<t; i++)
                if(list[i]) printf("in\n");
                else printf("out\n");
            printf("FINISH\n");
        }
    }
    return 0;
}
