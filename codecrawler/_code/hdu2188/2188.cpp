#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,m,T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        if(n%(m+1)==0)cout<<"Rabbit"<<endl;
        else cout<<"Grass"<<endl;
    }
    return 0;
}
/*
    简单博弈，一个捐款a，令一个人都能捐款b，使得a+b=m-1；
    如果n是m+1的倍数，则每次徐队捐的数加上林队捐的数都是m+1，则最后必定徐队胜。
    如果n不是m+1的倍数，则林队捐一定的钱使得n是m+1的倍数，那么就跟上述情况相同，林队必胜。
*/