#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 100555;

vector <int> v[N];

int a[5] = {
    1, 2, 4, 7, 15
};

void init()
{
    for( int i = 1; i <= 100005; i++ )
    {
        v[i].clear();
    }
    for( int i = 1; i <= 100005; i++ )
    {
        for( int j = 0; j < 5; j++)
            if(i - a[j] > 0)
                v[i].push_back(i-a[j]);
    }
}

int main()
{
    init();
    int n;
    while(~scanf("%d", &n))
    {
        printf("%d", v[n][v[n].size()-1]);
        for( int i = v[n].size()-2; i >= 0; i-- )
            printf(" %d", v[n][i]);
        puts("");
    }
    return 0;
}

