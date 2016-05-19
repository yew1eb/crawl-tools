#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b))
    {
        if(a==0&&b==0) break;
        if(a<b)  swap(a,b);
        bool Stan = true;
        while(1)
        {

            if(b==0 ||a%b==0||a/b>=2) break;
            int t = a;
            a = b;
            b = t - a;
            Stan = !Stan;
        }
        if(Stan) printf("Stan wins\n");
        else printf("Ollie wins\n");
    }
    return 0;
}
