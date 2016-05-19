#include <iostream>

using namespace std;

int a[6];

int main()

{

    int temp;

    int i,n;

    cin>>n;

    while (n--)

    {

        for(i=0;i<6;i++)

        {

            scanf("%d",&a[i]);

        }

        temp=a[0]-a[1]+a[2]-a[3]+a[4]-a[5];

        if (temp==0)

        {

            printf("YES\n");

        }

        else

            printf("NO\n");

    }

    return 0;

}