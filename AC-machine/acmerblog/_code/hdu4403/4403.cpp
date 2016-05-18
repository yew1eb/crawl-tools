#include <iostream>
#include <string>
using namespace std;
const int maxn = 15;
string str;
int num[maxn][maxn];
int ans;
int len;

void get_num(int n)
{
    for(int i = 0; i < n; i++)
    {
        int temp = 0;
        for(int j = i; j < n; j++)
        {
            temp += str[j] - '0';
            num[i][j] = temp;
            temp *= 10;
        }
    }
}
void dfs_right(int s,int A,int sum,int len)
{
    if(s == len )
    {
        if(A == sum)
        {
            ans++;
            return ;
        }
    }
    if(A < sum) return ;
    for(int i = s; i < len; i++)
    {
        dfs_right(i+1,A,sum+num[s][i],len);
    }
}
void dfs_left(int s,int sum,int mid)
{
    if(s == mid)
    {
        dfs_right(mid,sum,0,len);
    }
    for(int i = s; i < mid; i++)
    {
        dfs_left(i+1,sum+num[s][i],mid);
    }
}
void print_num()
{
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++) cout<<num[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    while(cin>>str)
    {
        if(str[0] == 'E') break;
        len = str.size();
        get_num(len);
        //print_num();
        ans = 0;
        for(int i = 0; i < len-1; i++) dfs_left(0,0,i+1);
        cout<<ans<<endl;
    }
    return 0;
}
