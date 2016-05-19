#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
map<string,int> MP;
struct Name{
    char s[60];
    int v;
    bool operator < (const Name &A)const{
        return v>A.v || (v==A.v && strcmp(s, A.s)<=0);
    }
}p[300];
char s[60];
int main(){
    int n, m;
    while(~scanf("%d", &n) && n){
        MP.clear();
        for(int i=0; i<n; i++){
            scanf("%s %d", p[i].s, &p[i].v);
            MP[p[i].s] = p[i].v;
        }
        sort(p, p+n);
        for(int i=0; i<n; i++)    printf("%s %d\n", p[i].s, p[i].v);
        scanf("%d", &m);
        int a, b, c;
        while(m--){
            a = b = 0;
            scanf("%s", s);
            c = MP[s];
            for(int i=0; i<n; i++){
                if(strcmp(p[i].s, s)==0)    break;
                if(p[i].v>c)    a++;
                else    b++;
            }
            printf("%d", a+1);
            if(b)    printf(" %d", b+1);
            puts("");
        }
    }
    return 0;
}