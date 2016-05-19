/*
åæ:åè®¾æ°n=2^k*p1^s1*p2^s2*p3^s3*...*pi^si;//k,s1...si>=0,p1..piä¸ºnçç´ å å­ 
æä»¥T[n]=(2^0+2^1+...+2^k)*(p1^0+p1^1+...+p1^s1)*...*(pi^0+pi^1+...+pi^si);
æ¾ç¶(2^0+2^1+...+2^k)%2=1,æä»¥T[n]æ¯0æ1å°±åå³äº(p1^0+p1^1+...+p1^s1)*...*(pi^0+pi^1+...+pi^si)
èp1...pié½æ¯å¥æ°(é¤2ä¹å¤çç´ æ°ä¸å®æ¯å¥æ°),æä»¥(pi^0+pi^1+...+pi^si)åªè¦æä¸ä¸ªsiä¸ºå¥æ°(i=1...i) 
å(pi^0+pi^1+...+pi^si)%2=0,åT[n]%2=0//è¥siä¸ºå¥æ°,åpi^si+1ä¸ºå¶æ°,pi^1+pi^2+...+pi^(si-1)ä¸ºå¶æ°(å¶æ°ä¸ªå¥æ°åä¸ºå¶æ°)
æä»¥è¦T[n]%2=1,åææçsiä¸ºå¶æ°ï¼ån=2^(k%2)*m^2;//m=2^(k/2)*p1^(s1/2)*p2^(s2/2)*...*pi^(si/2)
æä»¥åªè¦nä¸ºæä¸ªæ°çå¹³æ¹æèæä¸ªæ°çå¹³æ¹ååT[n]%2=1,åªè¦ç»è®¡nçä¸ªæ°å³å¯ 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int sum=(int)sqrt(n*1.0)+(int)sqrt(n*1.0/2);
        cout<<sum%2<<endl;
    }
    return 0;
}