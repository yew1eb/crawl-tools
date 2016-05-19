#include <iostream>
#include <stdio.h>
using namespace std;

void solve(int n)
{
    string str[] =
    {

        "-1",
        "-1",
        "-1",
        "1 * 2\n5 + 3\n6 + 4",
        "1 * 2\n6 * 3\n7 - 4\n8 / 5",
        "1 + 2\n7 + 3\n8 + 4\n9 + 5\n10 - 6",
        "1 + 2\n8 + 3\n4 + 5\n10 + 6\n11 / 7\n9 + 12",
        "1 + 2\n9 + 3\n4 + 5\n11 - 6\n12 - 7\n13 / 8\n10 + 14",
        "1 + 2\n10 + 3\n4 + 5\n12 + 6\n13 / 7\n11 - 14\n15 - 8\n16 + 9",
        "1 + 2\n3 + 4\n12 + 5\n13 + 6\n14 / 7\n11 + 15\n8 - 9\n17 / 10\n16 + 18",
        "1 + 2\n3 + 4\n13 / 5\n12 + 14\n15 - 6\n16 + 7\n17 - 8\n18 + 9\n19 - 10\n20 + 11",
        "1 + 2\n3 + 13\n4 + 14\n5 + 6\n7 + 16\n8 + 17\n9 + 15\n10 + 19\n18 / 11\n20 / 12\n21 * 22",
        "1 + 2\n3 + 4\n15 / 5\n14 - 16\n17 - 6\n18 + 7\n19 - 8\n20 + 9\n21 - 10\n22 + 11\n23 - 12\n24 + 13",
        // "1 + 2\n3 + %d\n4 + %d\n5 + 6\n7 + %d\n8 + %d\n9 + %d\n10 + %d\n%d / 11\n%d / 12\n%d * %d\n"
    };
    cout<<str[n-1]<<endl;
}
void solve1(int n)
{

    // printf("1 + 2\n3 + %d\n4 + %d\n5 + 6\n7 + %d\n8 + %d\n9 + %d\n10 + %d\n11 - 12\n%d * %d\n",n+1,n+2,n+4,n+5,n+6,n+7);
    // for(int i=1;i<=n-14;i++)
    //    printf("%d * %d\n",n+9+i-1,14+i);
    //printf("%d * %d\n%d / 13\n%d / 14\n%d + %d\n",n+3,n+8,n+10,n+11,n+12,n+9);
    printf("1 + 2\n3 + %d\n4 + %d\n5 + 6\n7 + %d\n8 + %d\n9 + %d\n10 + %d\n%d / 11\n%d / 12\n%d * %d\n13 - 14\n",n+1,n+2,n+4,n+5,n+3,n+7,n+6,n+8,n+9,n+10);
    for(int i = 15,k=0; i <= n; ++i,k++)
        printf("%d * %d\n",i,n+12+k);
    printf("%d + %d\n",n + 11,2*n-2);

}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n<=13)
            solve(n);
        if(n>=14)
            solve1(n);
    }
}
