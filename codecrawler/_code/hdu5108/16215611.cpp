#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,ans;

int main(){
        while(~scanf("%d",&n)){
                if(n==1) printf("0\n");
                else{
                        int cnt=n;
                        for(int i=2;i*i<=cnt;++i)
                                while(cnt%i==0){
                                        cnt/=i;
                                        ans=i;
                                }
                        if(cnt>1) ans=cnt;
                        printf("%d\n",n/ans);
                }
        }
        return 0;
}
