/*Author:Hacker_vision*/
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;

const int _max = 2e5 + 10;
int a,b,c;
map<char,int>mp;
struct player{
  int num;
  char name[30];//å§åname
  char role;//è§è²role
  int time;//çé¾
  int ok;//éæ²¡éä¸­ï¼åå§åä¸ºfalse
}p[25];

bool cmp(player a,player b){
  if(mp[a.role]!=mp[b.role]) return mp[a.role]>mp[b.role];
  return a.num<b.num;
}

bool solve(){
  sort(p,p+22,cmp);//åæroleånumæåºï¼æ¹ä¾¿æ¥æ¾ï¼éåä¸éå³å¯
  int i=0;//å¼å§éäºº
  if(p[i].role=='G') p[i].ok=true;else return false;//é1ä¸ªå®é¨å
  while(p[i].role=='G') {i++;if(i>=22)return false;}
  for(int j=0;i < 22&&j<a; ++ i,++ j) {//éaä¸ªååºçå
    if(p[i].role=='D') p[i].ok=true;
    else return false;
  }
  while(p[i].role=='D') {i++;if(i>=22)return false;}
  for(int j=0;i < 22&&j<b; ++ i,++ j) {//ébä¸ªä¸­åºçå
    if(p[i].role=='M') p[i].ok=true;
    else return false;
  }
  while(p[i].role=='M') {i++;if(i>=22)return false;}
  int j;
  for(j=0;i < 22&&j<c; ++ i,++ j) {//écä¸ªååºçå
    if(p[i].role=='S') p[i].ok=true;
    else return false;
  }
  if(j<c) return false;
  return true;
}

int main(){
 //freopen("input.txt","r",stdin);
 mp.clear();
 mp['G']=3;//æ¹ä¾¿ç»roleæåº
 mp['D']=2;
 mp['M']=1;
 mp['S']=0;
 while(scanf("%d",&p[0].num)==1&&p[0].num){
    for(int i = 0; i<22; ++i)p[i].ok=false;//åå§å
    for(int i = 0; i < 22; ++ i){
        if(i) scanf("%d",&p[i].num);
        scanf("%s %c",p[i].name,&p[i].role);
        int st,end;char ch;p[i].time=0;
        while(scanf("%d-%d%c",&st,&end,&ch)==3){ //è¯»å¥æ´æ°çé¾time
           p[i].time+=(end-st+1);
            if(ch=='\n')break;
        }
    }
    scanf("%d-%d-%d",&a,&b,&c);

    if(!solve())puts("IMPOSSIBLE TO ARRANGE");
    else{
      player q;q.num=10000;q.time=-1;int j=0;//ééé¿
      for( int i= 0;i<22; ++ i)
      if(p[i].ok){
       if(p[i].time>q.time||(p[i].time==q.time&&p[i].num>q.num)){
        q=p[i];//ç»æä½èµå¼
        j=i;
      }
     }
     printf("%d %s %c\n",p[j].num,p[j].name,p[j].role);//è¾åºéé¿ä¿¡æ¯
     p[j].ok=false;
     for(int i = 0 ;i< 22; ++ i)//è¾åºå¶ä»æåä¿¡æ¯
     if(p[i].ok) printf("%d %s %c\n",p[i].num,p[i].name,p[i].role);
    }
    puts("");//ä¸å®è¦æ³¨ææ¯ç»æµè¯æ°æ®ä¹é´æç©ºè¡ï¼ï¼
 }
 return 0;
}


