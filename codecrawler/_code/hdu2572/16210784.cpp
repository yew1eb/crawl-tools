#include <iostream>
#include <string>
#include <cstdio>
#include <set>
using namespace std;

set<string> vis;
int Judge(string str1,string str2)//å¤æ­ä¸¤ä¸ªä¸²æ¯å¦æåå«å³ç³»
{
    int flag = 0;
    string str3;
    int len1 = str1.length();
    int len2 = str2.length();
    for(int i = 0; i <= (len1-len2); i++)
    {
        str3 = str1.substr(i,len2);
        if(str3==str2) {flag = 1; break;}
    }
    if(flag) return 1;
    else return 0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        string str1,str2;
        string str3,str4;
        cin>>str1>>str2>>str3;
        int len1 = str1.length();
        int len2 = str2.length();
        int len3 = str3.length();
        int Max = max(len2,len3);
        int flag1 = 0;
        for(int j = Max; j<=len1; j++)//æªåå­ä¸²çé¿åº¦ä»æé¿çä¸ä¸ªä¸²çé¿åº¦å¼å§ä¾æ¬¡å¢å 
        {
            vis.clear();
            for(int i = 0; i<= (len1-j); i++)//æ¯æ¬¡æ¹åæªåé¿åº¦æ¶é½è¦ä»æ°éåä¾æ¬¡æ¯ä¸²
            {
              str4 = str1.substr(i,j);
              if(Judge(str4,str2) && Judge(str4,str3)) vis.insert(str4);//å°é¿åº¦ç¸ç­çç¬¦åæ¡ä»¶çå­ä¸²æ¾è¿setä¸­
            }
            if(vis.size()) {flag1 = 1; break;}//å¦æéåå¤§å°ä¸ä¸ºé¶ç´æ¥è·³åº
        }
        if(flag1) cout<<*vis.begin()<<endl;//å½flag1==1æ¶ï¼ç´æ¥è¾åºéåå½ä¸­çç¬¬ä¸ä¸ªå­ç¬¦ä¸²å³ä¸ºæ»¡è¶³æ¡ä»¶çå­ä¸²
        else cout<<"No"<<endl;//å¦åè¾åºNo
    }
    return 0;
}
