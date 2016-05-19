#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <cstdio>
using namespace std;
map<char,char> mp;
void init(){
    mp['A']='V';mp['B']='W';mp['C']='X';mp['D']='Y';mp['E']='Z';mp['F']='A';mp['G']='B';mp['H']='C';mp['I']='D';mp['J']='E';
    mp['K']='F';mp['L']='G';mp['M']='H';mp['N']='I';mp['O']='J';mp['P']='K';mp['Q']='L';mp['R']='M';mp['S']='N';mp['T']='O';
    mp['U']='P';mp['V']='Q';mp['W']='R';mp['X']='S';mp['Y']='T';mp['Z']='U';
}
int main(){
   // freopen("1.txt","r",stdin);
    init();
    char ss[1005];
    string s1,s2,s3;
    while(gets(ss)){
      if(strcmp("START",ss)==0);
      else if(strcmp("END",ss)==0)puts("");
      else if(strcmp("ENDOFINPUT",ss)==0)return 0;
      else{
        int len=strlen(ss);
        for(int i=0;i<len;++i){
          if(ss[i]>='A'&&ss[i]<='Z')
              printf("%c",mp[ss[i]]);
          else
              printf("%c",ss[i]);
        }
      }
    }
    return 0;
}