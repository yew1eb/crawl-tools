/* 题意：中文题 ...
指数型母函数详解神牛博文 ：   http://hi.baidu.com/nicker2010/item/fea0a5254208a30377272ced  */ 
#include<iostream>
#include<cmath>
using namespace std;
#define manx 13
double a[manx],b[manx];   /// a[] 代表第一个式子的系数 
long long num[manx];
long long fan(int n){
    long long sum=1;
    for(int i=1;i<=n;i++)
        sum *= i;
    return sum;
}
int main(){
    int n,m;
    while(cin>>n>>m){
        memset(b,0,sizeof(b));
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
            cin>>num[i];
        for(int i=0;i<=num[0];i++)   
            a[i] = 1.0/fan(i);
        for(int i=1;i<n;i++){  /// 从第二个式子开始... 
            for(int j=0;j<manx;j++) /// 第一个式子 x^j，系数是 a[j]... 
                for(int k=0;k<=num[i]&&k+j<manx;k++){ /// 第二个式的 x^k ,x^K的系数是 1  
                    b[j+k] += a[j]/fan(k);
                }
            for(int j=0;j<manx;j++){
                a[j] = b[j];
                b[j] = 0;
            }
        }
        printf("%.lf\n",a[m]*fan(m));  /// 组合数学 
    }
}