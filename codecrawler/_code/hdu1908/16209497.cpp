#pragma warning(disable:4786)
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n,k,p;
    map<int ,int > aQueue;
    while (scanf("%d",&n)!=EOF && n!=0)
    {
        if (n==1)
        {
            cin>>k>>p;
            aQueue.insert(map<int ,int>::value_type(p,k));
        }
        else if (n==3)
        {
            if (!aQueue.empty())
            {
                cout<<aQueue.begin()->second<<endl;
                aQueue.erase(aQueue.begin());
            }
            else
            {
                cout<<0<<endl;
            }
        }
        else 
        {
            if (!aQueue.empty())
            {
                cout<<aQueue.rbegin()->second<<endl;
                aQueue.erase(aQueue.find(aQueue.rbegin()->first));
            }
            else
            {
                cout<<0<<endl;
            }
        }
    }
    return 0;
}