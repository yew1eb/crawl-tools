#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

class equip
{
    public:
        int ai;
        int bi;
};

bool cmp(equip a,equip b)
{
    if((a.ai+b.bi)!=(b.ai+a.bi))
        return (a.ai+b.bi)<(a.bi+b.ai);
    else
        return a.bi<b.bi;
}

equip equipment[1005];

int main()
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int holev,eqnum;
        int pos=1;
        cin>>holev>>eqnum;
        for(int i=0;i<eqnum;i++)
        {
            cin>>equipment[i].ai>>equipment[i].bi;
        }
        
        sort(equipment,equipment+eqnum,cmp);
        
        for(int i=0;i<eqnum;i++)
        {
            if(holev>=equipment[i].ai && holev>=equipment[i].bi)
            {
                holev-=equipment[i].ai;
            }
            else
            {
                pos=0;
                break;
            }
        }
        
        if(pos==1)
            cout<<"Yes"<<endl;
        else if(pos==0)
            cout<<"No"<<endl;
        
        
    }
    
    return 0;
}
