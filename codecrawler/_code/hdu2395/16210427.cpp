/*
hdu 2395 Alarm Clock
è¿é¢å¤ªæ°´äº
ä¸ä¸å ä¸ å°æ¶ä¸å³è
å°æ¶ ä¸ åçåä½ä¸å³è
åçåä½ ä¸ ä¸ªä½ä¸å³è
*/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int cha(int a,int b,int mod)
{
    int ret=1000;
    if(b-a>0&&b-a<ret)
    {
            ret=b-a;
    }
    if(a-b>0&&a-b<ret)
    {
            ret=a-b;
    }
    if(a+mod-b>0&&a+mod-b<ret)
    {
        ret=a+mod-b;
    }
    if(b+mod-a>0&&b+mod-a<ret)
    {
        ret=b+mod-a;//ä»ä¸ºäºä¹åç é®çè¯¯ ret=a+mod-b;
    }
    return ret;
}
int main()
{
    int t,ret;
    int h1,h2,m1,m2,n1,n2;
    char p1,p2;
    string s1,s2;
    cin>>t;
    while(t--)
    {
        ret=0;
        cin>>s1>>s2;
        stringstream strs;
        strs.str(s1);
        strs>>h1;
        strs.get();
        m1=strs.get()-'0';
        n1=strs.get()-'0';
        p1=strs.get();

        strs.str(s2);

        strs>>h2;
        strs.get();
        m2=strs.get()-'0';
        n2=strs.get()-'0';
        p2=strs.get();

        if(p1!=p2)
            ++ret;
        if(h1!=h2)
        {
            ret+=cha(h1,h2,12);
        }
        if(m1!=m2)
        {
            ret+=cha(m1,m2,6);
        }
        if(n1!=n2)
        {
            ret+=cha(n1,n2,10);
        }
        cout<<"Going from "<<s1<<" to "<<s2<<" requires "<<ret<<((ret==1)?" push.":" pushes.")<<endl;
    }
    return 0;
}
