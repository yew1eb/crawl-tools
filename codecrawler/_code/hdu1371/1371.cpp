#include<iostream>
using namespace std;

bool in(int sh,int sm,int eh,int em,int h,int m)
{
    if(sh>h)
        return false;
    if(sh==h&&sm>m)
        return false;
    if(eh<h)
        return false;
    if(eh==h&&em<=m)
        return false;
    return true;
}

int Turn(int sh,int sm,int eh,int em)
{
    int p=0;
    if(eh<sh)eh+=12;
    if(eh==sh&&em<sm)eh+=12;
    if(eh>=24)eh-=12,sh-=12;
    if(in(sh,sm,eh,em,0,0))p++;        //00:00:00
    if(in(sh,sm,eh,em,1,5))p++;        //01:05:27
    if(in(sh,sm,eh,em,2,10))p++;    //02:10:54
    if(in(sh,sm,eh,em,3,16))p++;    //03:16:21
    if(in(sh,sm,eh,em,4,21))p++;    //04:21:49
    if(in(sh,sm,eh,em,5,27))p++;    //05:27:16
    if(in(sh,sm,eh,em,6,32))p++;    //06:32:43
    if(in(sh,sm,eh,em,7,38))p++;    //07:38:10
    if(in(sh,sm,eh,em,8,43))p++;    //08:43:38
    if(in(sh,sm,eh,em,9,49))p++;    //09:49:05
    if(in(sh,sm,eh,em,10,54))p++;    //10:54:32
    if(in(sh,sm,eh,em,12,0))p++;    //12:00:00
    if(in(sh,sm,eh,em,13,5))p++;    //13:05:27
    if(in(sh,sm,eh,em,14,10))p++;    //14:10:54
    if(in(sh,sm,eh,em,15,16))p++;    //15:16:21
    if(in(sh,sm,eh,em,16,21))p++;    //16:21:49
    if(in(sh,sm,eh,em,17,27))p++;    //17:27:16
    if(in(sh,sm,eh,em,18,32))p++;    //18:32:43
    if(in(sh,sm,eh,em,19,38))p++;    //19:38:10
    if(in(sh,sm,eh,em,20,43))p++;    //20:43:38
    if(in(sh,sm,eh,em,21,49))p++;    //21:49:05
    if(in(sh,sm,eh,em,22,54))p++;    //22:54:32
    return p;
}

int main()
{
    int sh,sm,eh,em,p;
    cout<<"Program 3 by team X"<<endl;
    cout<<"Initial time  Final time  Passes"<<endl;
    while(cin>>sh>>sm>>eh>>em)
    {
        cout<<"       ";
        if(sh<10) cout<<0;
        cout<<sh<<":";
        if(sm<10) cout<<0;
        cout<<sm;
        cout<<"       ";
        if(eh<10) cout<<0;
        cout<<eh<<":";
        if(em<10) cout<<0;
        cout<<em<<"  ";
        p=Turn(sh,sm,eh,em);
        printf("%6d ",p);
    }
    cout<<"End of program 3 by team X"<<endl;
    return 0;
}