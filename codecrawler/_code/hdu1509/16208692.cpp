#include <iostream>
#include <queue>
#include <string>
using namespace std;

class info
{
    public:
        string task;
        string attrib;
        int youxian;
        int wulinum;
        info(string a,string b,int c,int d):task(a),attrib(b),youxian(c),wulinum(d)
        {}
};

priority_queue<info> lineinfo;

bool operator < (const info &t1,const info &t2)
{
    if(t1.youxian==t2.youxian)
    {
        return t1.wulinum > t2.wulinum;
    }
    else
        return t1.youxian > t2.youxian;
}


int main()
{
    string command;
    int wulinum=0;
    while(cin>>command)
    {
        if(command=="GET")
        {
            if(lineinfo.empty())
            {
                cout<<"EMPTY QUEUE!"<<endl;
            }
            else
            {
                info tmp=lineinfo.top();
                cout<<tmp.task<<" "<<tmp.attrib<<endl;
                lineinfo.pop();
            }
        }
        if(command=="PUT")
        {
            string tmpls;
            string tmpattr;
            int prior;
            int lastpor=prior;
            cin>>tmpls>>tmpattr>>prior;
            
            
            lineinfo.push(info(tmpls,tmpattr,prior,wulinum));
            wulinum++;
        }
        
        
        
        
    }
        return 0;
}

