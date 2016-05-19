//题意：有f+1个人分n块披萨，每个人要求分得的面积一样，
//      且披萨只能被切开而不能重新组合，求每个人能分到的最大面积v。
//思路：对于每个确定的v，可以计算出最多能满足的人数p。
//      因此得到一个单调递减的函数关系，并且v的范围也可以确定为0~max(size(i)),i=1...n。（图中）
//      一般要求什么酒对什么进行二分，对某一个面积进行判断，如果满足条件，那么找比这个面积大的满足条件的
//调试：编译的时候出现 undefined reference to [email protected]/* <![CDATA[ */!function(t,e,r,n,c,a,p){try{t=document.currentScript||function(){for(t=document.getElementsByTagName('script'),e=t.length;e--;)if(t[e].getAttribute('data-cfhash'))return t[e]}();if(t&&(c=t.previousSibling)){p=t.parentNode;if(a=c.getAttribute('data-cfemail')){for(e='',r='0x'+a.substr(0,2)|0,n=2;a.length-n;n+=2)e+='%'+('0'+('0x'+a.substr(n,2)^r).toString(16)).slice(-2);p.replaceChild(document.createTextNode(decodeURIComponent(e)),c)}p.removeChild(t)}}catch(u){}}()/* ]]> */'  
//     由于把main写成 mian啦
//     这个题貌似很恶心 Pi  还是用反三角函数比较好
//      人数是输入的F+1个儿不是F个他本人也要分       
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define  Pi acos(-1)
#define maxlen 10010
using namespace std;
long long high,mid,low,ans,s[maxlen];
int T,N,i,F;
double r;
bool judge(long long mid)
{
    int i;
    bool  flag;
    long long p = 0;
    for (i = 0; i < N; i++)
        p += s[i] / mid;
    if(p>=F+1)flag=true;//注意这里是f+1
    else flag=false;
    return flag;
}//判断分成这个面积可不可以
int main()
{
    cin >> T;
    while(T--)
    {
        low=0,high=0,ans=0;
        cin >> N >> F;
        memset(s,0,sizeof(s));
        for(i=0; i<N; i++)
        {
            cin >> r;
            s[i]=r*Pi*r*1000000;//先乘以一个大的树，再除回来，怕精度问题
            high+=s[i];
        }
        while(low<=high)
        {
            mid=(low+high)/2;
            if (judge(mid))
            {
                low = mid + 1;
                ans = mid;
            }
            else
                high = mid - 1;
        }
        printf("%.4lf\n", (double)ans/1000000);
    }
    return 0;
}