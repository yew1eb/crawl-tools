#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <cstring>
using namespace std;

class student
{
public:
    int solve;
    int time;
    int idx;
    int score;
};

int div(int g)
{
    if(g==1)
        return 1;
    else
        return g/2;
}

int wastetime(string tar)
{
    string a,b,c;
    int an,bn,cn,res=0;
    for (int i=0;i<=1;i++)
        a+=tar[i];
    for (int j=3;j<=4;j++)
        b+=tar[j];
    for (int k=6;k<=7;k++)
        c+=tar[k];
    an=atoi(a.c_str());
    bn=atoi(b.c_str());
    cn=atoi(c.c_str());

    res=an*3600+bn*60+cn;
    return res;
}

bool cmp(student c1,student c2)
{
    if (c1.solve!=c2.solve)
        return c1.solve>c2.solve;
    else
        return c1.time<c2.time;
}

bool cmp2(student c1,student c2)
{
    return c1.idx<c2.idx;
}

int main()
{
    student aclass[109];
    int grade[109];
    int countstu[6];
    int testcase;
    while (cin>>testcase && testcase!=-1)
    {
        memset(countstu,0,sizeof(countstu));
        string tar;
        for (int i=0;i<testcase;i++)
        {
            cin>>aclass[i].solve>>tar;

            aclass[i].time=wastetime(tar);
            aclass[i].score=aclass[i].solve*10+50; //ç¬¬ä¸æ¬¡å¤ç åç»åºç¡å
            aclass[i].idx=i;
            countstu[aclass[i].solve]++;
        }

        sort(aclass,aclass+testcase,cmp);

        
        int pos=countstu[5];
        
        for(int i=pos;i<pos+div(countstu[4]);i++) //ä¸æ­¥ä¸æ­¥çæ¢æ¢æ³ï¼ä¸è¦çæ¥= = 
        {
            aclass[i].score+=5;
        }
        pos+=countstu[4];
        for(int i=pos;i<pos+div(countstu[3]);i++)
        {
            aclass[i].score+=5;
            
        }
        pos+=countstu[3];
        for(int i=pos;i<pos+div(countstu[2]);i++)
        {
            aclass[i].score+=5;
            
        }
        pos+=countstu[2];
        for(int i=pos;i<pos+div(countstu[1]);i++)
        {
            aclass[i].score+=5;
            
        }
        pos+=countstu[1];    

        sort(aclass,aclass+testcase,cmp2);  //å¤çåç»æåå»
        for (int i=0;i<testcase;i++)
        {
            cout<<aclass[i].score<<endl;
        }
        
        cout<<endl;

    }
    return 0;
}
