#pragma warning (disable : 4786)
#include <iostream>
#include <map>
using namespace std;

map<int,int>M;
map<int,int>::iterator p;

int main()
{
    int command;
    int name,num;
    while (scanf("%d",&command)&&command)
    {
        if (command==1)
        {
            scanf("%d%d",&name,&num);
            M.insert(pair<int,int>(num,name));
        }
        else if(command==2)
        {
            if (M.empty())
                printf("0/n");
            else
            {
                cout<<M.rbegin()->second<<endl;
                M.erase(M.find(M.rbegin()->first));
            }
        }
        else if (command==3)
        {
            if (M.empty())
                printf("0/n");
            else
            {
                p = M.begin();
                cout<<p->second<<endl;
                M.erase(p);
            }
        }
    }
    return 0;
}
