#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

int mat[109][109];

int main()
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        memset(mat,0,sizeof(mat));
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                scanf("%d",&mat[i][j]);
        }
        if(mat[n-1][m-1]==1)
            cout<<"Alice"<<endl;
        else
            cout<<"Bob"<<endl;

    }
    return 0;
}

