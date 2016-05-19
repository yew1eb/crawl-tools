#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    int T,N;
    scanf("%d",&T);
    for(int j = 0; j<T; j++)
    {
        scanf("%d",&N);
        int flag = 1;
        char str[35];
        double C,S;
        double sumC = 0, sumS = 0;
        for(int i = 0; i<N; i++)
        {
            scanf("%s%lf%lf",str,&C,&S);
            if(S < 60) flag = 0;
            else
            {
                sumC +=C;
                sumS +=C*S;
            }
        }
        double temp = sumS/sumC;
        if(flag) printf("%.2lf\n",temp);
        else printf("Sorry!\n");
        if(j != T-1) printf("\n");
    }
    return 0;
}
