#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int N,T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(j != N)
                    printf("%d ",i*j);
                else
                    printf("%d\n",i*j);
            }
        }
    }

    return 0;
}
