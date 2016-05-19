#include <iostream>
#include<cstdio>
using namespace std;

int main()
{

    int v,v0;
    while(scanf("%d %d",&v,&v0)!=EOF)
    {
        printf("%d\n",2*v-v0);
    }
    return 0;
}
