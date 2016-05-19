/*

给你整数 a,b; 要你求a,a+1,a+2...a+b-1,使用的是二进制的加法计算，
求二进制加法过程中进位了多少次 
分析：假设 a = 0， b = 20
位i 54321 
0   00000
1   00001
2   00010
3   00011
4   00100
5   00101
6   00110
7   00111
8   01000
9   01001
10  01010
11  01011
12  01100
13  01101
14  01110
15  01111
16  10000
17  10001
18  10010
19  10011
20  10100
观察发现 pos_1 周期 2
		 pos_2 周期 4
   		 pos_3 周期 8
      	 pos_4 周期 16
然后通过计算 a->b ：dp[pos_1]中1个数 
					dp[pos_2]中1个数
     				dp[pos_3]中1个数
         			dp[pos_4]中1个数 
         			。。。。。
         			这里有各种方法，我是使用dfs()搜索，注意若干特殊情况，代码中有详解 
最后通过 k += dp[i-1]/2; dp[i] += dp[i-1]/2; 进行累加计算 k  

*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
#define manx 100

__int64 dp[manx],num ;

void dfs(__int64 a,__int64 b,__int64 val,int flag){
    if(flag > 51) return;
    __int64 sum = b - a + 1; // sum 表示区间 
    __int64 ans = sum/val*(val/2); // ans表示周期个数 * 周期内1的个数 
    if(sum%val) {
        if(a%val >= val/2){ // 第一次出现 1 的时候 
        	if(sum%val>val-a%val + val/2) // 当出现1100001的情况 
         		ans += (val-a%val)+(sum%val-val+a%val-val/2);
       		else  ans += min(sum%val,val-a%val);
        }    
        else{  // 第一次出现 0 的时候 
            if(sum%val - (val/2-a%val) >= 0) { 
                if(sum%val-(val/2-a%val)<=val/2) 
                	ans += sum%val-(val/2-a%val);
               	else ans += val/2; // 当出现0011110的情况 
           	} 
        }    
    }
    dp[++num] = ans;
    dfs(a,b,val*2,flag+1);
}

int main(){
    __int64 a,b;
    while(cin>>a>>b){
        if(a>b) swap(a,b);
        memset(dp,0,sizeof(dp));
        __int64 sum = b-a+1,ans = sum/2;
        if(sum%2 && a%2) ans++; 
        num = 0; 
        dp[++num] = ans;
        dfs(a,b,2*2,1);
        __int64 k = 0;
        for(int i=1;i<100;i++){
            k += dp[i]/2;
            dp[i+1] += dp[i]/2;
        }
        cout<<k<<endl;
    }
}