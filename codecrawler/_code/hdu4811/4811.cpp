#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
using namespace std;
int main()
{
    int f[5]={0,0,1,3};
    int x,y,z;
    int qian,hou;
    while(cin>>x>>y>>z)
    {
        long long ans=0;
        qian=hou=0;
        if(x>0){qian++;x--;}//往前面加不用颜色的先
        if(y>0){qian++,y--;}
        if(z>0){qian++,z--;}
        if(x>0){hou++,x--;}//往后面加不同的颜色
        if(y>0){hou++,y--;}
        if(z>0){hou++,z--;}
        ans+=f[qian];
        ans+=qian*hou+f[hou];//计算一下把两边都放好获得的点数
        ans+=(long long)(qian+hou)*(x+y+z);//因为两边的状态已经放好，后来的计算就是固定的
        cout<<ans<<endl;
    }
    return 0;
}
