#include <iostream>
#include <algorithm>
using namespace std;
#define N 1005

struct warehouse_node{
    double j,f,unit_price;
};
warehouse_node warehouse[N];

bool cmp(warehouse_node a,warehouse_node b){
    if (a.unit_price>=b.unit_price)
        return true;
    else return false;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("1009in.txt","r",stdin);
#endif
    int n,i;
    double max,m;
    while (scanf("%lf%d",&m,&n)!=EOF){
        if (m==-1&&n==-1)
            break;
        for (i=0;i<n;i++){
            scanf("%lf%lf",&warehouse[i].j,&warehouse[i].f);
            warehouse[i].unit_price=warehouse[i].j/warehouse[i].f;
        }
        sort(warehouse,warehouse+n,cmp);
        max=0;
        for (i=0;i<n&&m;i++){
            if (m>=warehouse[i].f){
                m=m-warehouse[i].f;
                max+=warehouse[i].j;
            }
            else {
                max+=m/warehouse[i].f*warehouse[i].j;
                m=0;
            }
        }
        printf("%.3lf\n",max);
    }
    return 0;
}