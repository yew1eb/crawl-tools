#include <iostream>
using namespace std;

int main(){
    int n,m,min,a;
    while (scanf("%d%d",&n,&m)!=EOF){
        min=INT_MAX;
        while (n--){
            scanf("%d",&a);
            if (a<min)
                min=a;
        }
        printf("%d\n",m/min);
    }
    return 0;
}