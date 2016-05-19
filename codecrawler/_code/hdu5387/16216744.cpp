#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int c=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){c=c*10+ch-'0';ch=getchar();}
    return c*f;
}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main(){
  int t,h,m,s;
   t=read();
   while(t--){
       scanf("%d:%d:%d",&h,&m,&s);
       h%=12;
       m%=60;
       s%=60;

       int ss=s*720;    //ç§éèµ°è¿çè§åº¦
       int mm=720*m+12*s;  //åéèµ°è¿çè§åº¦
       int hh=3600*h+60*m+s;  //æ¶éèµ°è¿çè§åº¦

      //è®¡ç®è§åº¦ä¹å·®
       int hm=abs(hh-mm);
       int hs=abs(hh-ss);
       int ms=abs(mm-ss);
      //å¤æ­
       hm=min(hm,120*360-hm);
       hs=min(hs,120*360-hs);
       ms=min(ms,120*360-ms);
      //åæå¤§å¬çº¦æ°
       int ghm=gcd(hm,120);
       int ghs=gcd(hs,120);
       int gms=gcd(ms,120);

       if(ghm==120) cout<<hm/120;
       else cout<<hm/ghm<<"/"<<120/ghm;

       if(ghs==120) cout<<" "<<hs/120<<" ";
       else cout<<" "<<hs/ghs<<"/"<<120/ghs<<" ";

        if(gms==120) cout<<ms/120<<" "<<endl;
       else cout<<ms/gms<<"/"<<120/gms<<" "<<endl;
   } return 0;
}