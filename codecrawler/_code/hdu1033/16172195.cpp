#include <iostream>
using namespace std;
const int N = 205; 
struct point{
    int x, y; 
    point(int x = 0, int y = 0): x(x), y(y) {}
};
char in[N]; 
void solve(){
    point st(300, 420), ed(310, 420), ted; 
    printf("300 420 moveto\n310 420 lineto\n");
    int i; 
    for(i = 0; in[i]; i++){
        if(in[i] == 'A'){ //é¡ºæ¶éè½¬
            ted.x = (ed.y - st.y) + ed.x; 
            ted.y = -(ed.x - st.x) + ed.y; 
        }else{ //éæ¶éæè½¬
            ted.x = -(ed.y - st.y) + ed.x; 
            ted.y = (ed.x - st.x) + ed.y; 
        }
        st = ed; 
        ed = ted; 
        printf("%d %d lineto\n", ed.x, ed.y);
    }
    printf("stroke\nshowpage\n");
}
int main()
{
    while(scanf("%s", in) != EOF) 
        solve(); 
    return 0;
}