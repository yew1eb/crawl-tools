/****************************************
*****************************************
*        Author:Tree                    *
*From :http://blog.csdn.net/lttree      *
* Title : Energy Conversion             *
*Source: hdu 4823  百度之星资格赛      *
* Hint  : water                         *
*****************************************
****************************************/

#include <iostream>
using namespace std;

int main()
{
    int n,m,v,k,t;
    int step;
    // 要用long long 哟~！
    long long now,pre;
    cin>>t;
    while( t-- )
    {
        cin>>n>>m>>v>>k;
        step=0;

        now=m;
        while( now<n )
        {
            pre=now;
            now=(pre-v)*k;
            // 如果剩余能量小于施展转换魔法的能量，或者当前能量小于转换之前的能量，则永远无法成功
            if( now<v || pre>=now )
            {
                step=-1;
                break;
            }
            ++step;
        }
        cout<<step<<endl;
    }
    return 0;
}