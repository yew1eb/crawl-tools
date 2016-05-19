#include <iostream>
using namespace std;
int main()
{
    int T,res,n;
    while(scanf("%d",&T)&&T){
        res=0;
        for(int i=0;i<T;i++){
            scanf("%d",&n);
            res^=n;
        }
        cout<<res<<endl;
    }
    return 0;
}