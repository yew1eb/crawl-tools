/*
é¢æï¼aæç¡®å®çå¼ å¶ä»çæ¯éæºå¼
éè¿è¿ç®ï¼é£äºåéæ¯ç¡®å®çå¼
map çåºç¨
*/
//#pragma warning(disable: 4786)//å ä¸è¿å¥å¯ä»¥å±è½é¿æ ç¤ºç¬¦å¸¦æ¥çè­¦å
#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,bool>m;
map<string,bool>::iterator it;
void pro(string s,string ss)
{
    it=m.find(ss);
    if(it==m.end())
    {
        m[ss]=false;
    }

    m[s]=m[ss];
}
int main()
{
    string s,ss;
    int i,n,j,ni=1;
    while(scanf("%d",&n),n)
    {
        m.clear();
        m.insert(pair<string,bool>("a",true));
        printf("Program #%d\n",ni++);
        for(i=1;i<=n;i++)
        {    
            cin>>s>>ss>>ss;
            pro(s,ss);
        }
        it=m.begin();
        int flag=0;
        while(it!=m.end())
        {
            if(it->second==true)
            {
                cout<<(it->first)<<" ";
                flag=1;
            }
            it++;
        }
        if(flag==0)
            cout<<"none";
        cout<<endl<<endl;
    }
    return 0;
}