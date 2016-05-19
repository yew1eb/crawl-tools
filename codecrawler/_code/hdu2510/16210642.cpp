#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAX 25
//ashione 2012-4-19
//æè¡¨ï¼ä¸æè¡¨ä¼è¶æ¶ï¼å ä¸ºåæº¯ç®æ³çæ¶é´å¤æåº¦æ¯å¾é«çãæ³¨éæçä»£ç æ¯æè¡¨çã
int q[MAX][MAX];
int readc[MAX]={0,0,0,4,6,0,0,12,40,0,0,171,410,0,0,1896,5160,0,0,32757,59984,0,0,431095,822229};
/*
int sum,count;
void make(int t,int n){
         if(count>(n+1)*(n)/4 || (t-1)*t/2 - count>(n+1)*n/4)
                return ;
         if(t>n){
                 sum++;
//               cout<<"hello"<<endl;
                 return ;
         }
         for(int i=0;i<2;i++){
                 q[1][t] = i;
                 count+=i;
                 for(int j=2;j<=t;j++){
                                q[j][t-j+1] = q[j-1][t-j+1]^q[j-1][t-j+2];
                                count+=q[j][t-j+1];
                 }
                 make(t+1,n);
                 for(int j=1;j<=t;j++)
                         count-=q[j][t-j+1];
         }

}
*/
int main(){
        int n;
/*
        for(int i=1;i<=24;i++){
                count = sum= 0;
                memset(q,0,sizeof(q));
                if((i*(i+1)/2)%2 == 0)
                        make(1,i);
                        readc[i] =sum;
                cout<<readc[i]<<",";
        }
        cout<<endl;
*/
        while(cin>>n && n){
                cout<<n<<" "<<readc[n]<<endl;
        }
        return 0;
}