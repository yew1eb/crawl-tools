#include <iostream>
#include <string.h>
using namespace std;
int c[30],vis[30];
char a[30];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int i,j,k,t,flag=0;
        cin>>a;
        memset(c,0,sizeof(c));
        memset(vis,0,sizeof(vis));
        for(i=0;i<26;i++)
        {
            if(vis[i])continue;
            t=1;
            vis[i]=1;
            j=i;
            while(a[j]-'A'!=i)
            {
                t++;
                j=a[j]-'A';
                vis[j]=1;
            }
            c[t]++;
        }
        for(i=2;i<=26;i+=2)
        if(c[i]%2==1){flag=1;break;}
        if(flag)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}
/*
(a1,a2,a3)就是a1->a2,a2->a3,a3->a1
(a1,a2,a3)*(a1,a2,a3)就是a1->a2->a3,a2->a3->a1,a3->a1->a2=(a1,a3,a2)

(b1,b2,b3,b4)*(b1,b2,b3,b4)就是b1->b2->b3,b2->b3->b4,b3->b4->b1,b4->b1->b2=(b1,b3)(b2,b4)

    本题求得是是否存在A*A=B，B为输入的置换
    通过研究我们可以得出,奇数长度相同循环相乘还是奇数循环，
偶数长度n相同循环相乘会分裂成两个长度为n/2的循环
    所以本题本题我们只要找B中偶数循环中是否出现奇数个，出现就是No，否则Yes。
因为奇数循环可以由相同长的奇数循环相乘得到，而偶数循环只能是成对的，由偶数循环相乘分裂得到。
*/