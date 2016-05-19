#include <iostream>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

class hospital
{
    public:
        int level;
        int id;
    friend bool operator < (hospital c1,hospital c2)
    {
        if(c1.level!=c2.level)
            return c1.level<c2.level;
        else
            return c1.id>c2.id;
    }
};

int main()
{
    int testcase;
    while(cin>>testcase)
    {
        int doc,level;
        int as=0;
        string op;
        priority_queue<hospital> p[4];
        hospital tmp;
        while(testcase--)
        {
        cin>>op;
        if(op=="IN")
        {
            as++;
            cin>>doc>>level;
            tmp.level=level;
            tmp.id=as;
            //cout<<"idis"<<tmp.id<<endl;
            p[doc].push(tmp);

        }
        else if(op=="OUT")
        {
            cin>>doc;
            if(p[doc].empty())
                cout<<"EMPTY"<<endl;
            else
            {
                tmp=p[doc].top();
                p[doc].pop();
                cout<<tmp.id<<endl;

            }
        }
        }


    }
    return 0;
}