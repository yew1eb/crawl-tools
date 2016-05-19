/*
Pro: 0

Sol:

date:
*/
#include<cstdio>
#include<cstring>
using namespace std;
#define mod 1000000007
int t;
long long mod_pow(int a,int n,int p)
{
    long long ret=1;
    long long A=a;
    while(n){
        if (n & 1)
            ret=(ret*A)%p;
        A=(A*A)%p;
        n>>=1;
    }
    return ret;
}
int main(){
    scanf("%d",&t);
    while( t -- ){
        char str[808];
        scanf("%s",str);
        int len = strlen(str);
        int unknown = 0, r_num = 0;
        for(int i = 0; i < len; i ++){
            if(str[i] == '?') unknown ++;
            else if(str[i] == 'R') r_num ++;
        }
        long long unbea = (r_num == 0);//全为G的是不beautiful的。
        
        for(int i = 0; i < len; i ++){//开始遍历
            if(str[i] == 'R' || str[i] == '?'){//可能是R的情况
                int x = (str[i] == 'R');
                unbea = (unbea + (x == r_num) ) % mod;//这是给出的串只有一个R的情况
                
                for(int dis = 1; dis + i < len; dis += 2){// + i 枚举距离
                    int y = x;
                    for(int sta = i + dis; sta < len; sta += dis){//枚举第二个位置以及以后
                        y += (str[sta] == 'R');
                        if(str[sta] == 'G') break;
                        unbea = (unbea + (y == r_num) )% mod;//如果遍历到的点和R的个数相同
                        //那么，就加上一个不美丽字符串
                        //这一句话包含了（拿样例4做解释）
                        //RRRR
                        //RRRG RRGG
                        //RGGR
                        //GRRR GRRG
                        //GGRR
                    }
                }
            }
        }
        printf("%I64d\n",mod_pow(2,unknown,mod) - unbea);
    }
    return 0;
}
