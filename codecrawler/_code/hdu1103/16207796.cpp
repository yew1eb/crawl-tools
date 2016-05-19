#include <stdio.h>
#include <string.h>
#include <algorithm>
using std::min_element;
char str[10];
int ar[101], br[101], cr[101];

int main(){
    int a, b, c, h, m, num, table, count, *p;
    while(scanf("%d%d%d", &a, &b, &c), a || b || c){
        memset(ar, 0, sizeof(ar));
        memset(br, 0, sizeof(br));
        memset(cr, 0, sizeof(cr));
        count = 0;
        while(scanf("%s", str), str[0] != '#'){
            sscanf(str, "%d:%d", &h, &m);
            m += h * 60;
            scanf("%d", &num);
            table = num;
            if(num & 1) ++table;
            if(table == 2){
                p = min_element(ar, ar + a);
                if(*p <= m + 30){ 
                    if(*p <= m) *p = m + 30; 
                    else *p += 30;
                    count += num; 
                }                
            }else if(table == 4){
                p = min_element(br, br + b);
                if(*p <= m + 30){ 
                    if(*p <= m) *p = m + 30; 
                    else *p += 30;
                    count += num; 
                }
            }else{
                p = min_element(cr, cr + c);
                if(*p <= m + 30){ 
                    if(*p <= m) *p = m + 30; 
                    else *p += 30;
                    count += num; 
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}