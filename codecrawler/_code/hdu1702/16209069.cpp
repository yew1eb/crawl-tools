#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

void queueExe(int n)
{
    int x;
    string s;
    queue<int> q;
    while(n--)
    {
        cin>>s;
        if(s.compare("IN")==0)
        {   cin>>x;
            q.push(x);        
        }
        else if(s.compare("OUT")==0)
        {
            if(q.empty())
                cout<<"None"<<endl;
            else
            {
                cout<<q.front()<<endl;
                q.pop();
            }
        }
    }
}
void stackExe(int n)
{
    int x;
    string s;
    stack<int> q;
    while(n--)
    {
        cin>>s;
        if(s.compare("IN")==0)
        {   cin>>x;
            q.push(x);
        }
        else if(s.compare("OUT")==0)
        {
            if(q.empty())
                cout<<"None"<<endl;
            else
            {
                cout<<q.top()<<endl;
                q.pop();
            }
        }
    }
}

int main()
{
    int T,N;
    string strtype;
    string cmd;
    
    while(cin>>T)
    {
        while(T--)
        {
            cin>>N>>strtype;
            if(strtype.compare("FIFO")==0)
                queueExe(N);

            else if(strtype.compare("FILO")==0)
                stackExe(N);
            else 
               cout<<"error"<<endl;
        }
    }
    return 0;
}