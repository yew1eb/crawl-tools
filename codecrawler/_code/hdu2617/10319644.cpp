#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#define MIN(a,b) (a)>(b)?(b):(a)
int main(){
    char str[11000];
    while(gets(str)){
        int i,h=0,a=0,p=0,y=0,ans;
        for(i=0;str[i];i++){
            if(str[i]=='h')
                h++;
            if(str[i]=='a'&&a<h)
                a++;
            if(str[i]=='p'&&p<2*a)
                p++;
            if(str[i]=='y'&&y<p/2)
                y++;
        
        }
            ans=MIN(MIN(h,a),MIN(p/2,y));
        cout<<ans<<endl;
    }
    return 0;
}
