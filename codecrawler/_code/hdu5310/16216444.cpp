#include <iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    long long t,m,n,p,q,sum;    //è¦ç¨long long
    double cur;
    cin>>t;
    while(t--){
        sum=0;
        cin>>n>>m>>p>>q;
        cur=q/m;
        if(cur<p){              //çæ¯å¥è£åéè¿æ¯åä¹°åé
            sum=n/m*q;
            if(q<n%m*p)         //éè¦å¤æ­ä¸ä¸ï¼ä¸ªæ°ä¸è¶³ä¸ä¸ªå¥è£æ¶æ¯åä¹°åéè¿æ¯å¥è£åé
            sum+=q;
            else
            sum+=n%m*p;
        }
        else                    //å¨åä¹°è¯å®æ¯æåéçéæ©
        sum=n*p;
        cout<<sum<<endl;
    }
    return 0;
}                               //æäº¤æ¶éæ©C++éG++ä¼è¶æ¶
