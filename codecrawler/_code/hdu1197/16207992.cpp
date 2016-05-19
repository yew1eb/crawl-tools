#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 100010
#define MAX 1000010

int p[] = {2992,2993,2994,2995,2996,2997,2998,2999,4470,4471,4472,4473,4474,4475,4970,4971
,4972,4973,4974,4975,5460,5461,5462,5463,5464,5465,5466,5467,5468,5469,5960,5961
,5962,5963,6456,6457,6458,6459,7440,7441,7442,7443,7444,7445,7446,7447,7448,7449
,7940,7941,7942,7943,8436,8437,8438,8439,9424,9425,9426,9427,9428,9429,9924,9925
,9926,9927,9928,9929};

int f(int x,int n){
    int cnt = 0;
    while(x){
        cnt += x%n;
        x /= n;
    }
    return cnt;
}


void init(){
    //printf("{");
    int cnt = 0;
    for(int i = 1000; i < 10000; ++i){
        int a = f(i,10), b = f(i,16), c= f(i,12);
        if(a == b && b == c){
            printf("%d\n",i);//cnt++;
        }
    }
    //printf("}%d\n",cnt);
}



int main() {
    int x;
    init();
    /*for(int i = 0; i < 68; ++i){
        printf("%d\n",p[i]);
    }
    while(~scanf("%d",&x),x) {
        printf("%d\n",f(x,2));
    }*/
    return 0;
}
