#include <iostream>
#include <stdio.h>

using namespace std;

const int MAX_N = 200000 + 100;
int m,sum;
int arr[MAX_N];

int main()
{
    //while(cin >> m,m)
    while(scanf("%d",&m),m)
    {
        sum = 0;
        for(int i = 0;i < m;i++)
        {
            //cin >> arr[i];
            scanf("%d",&arr[i]);
            sum ^= arr[i];
        }
        if(sum == 0)
        {
            //cout << "No" << endl;
            printf("No\n");
            continue;
        }
        //cout << "Yes" << endl;
        printf("Yes\n");
        for(int i = 0;i < m;i++)
        {
            int remain = arr[i] ^ sum;
            if(remain < arr[i])
                //cout << arr[i] << " " << remain << endl;
                printf("%d %d\n",arr[i],remain);
        }
    }
    return 0;
}