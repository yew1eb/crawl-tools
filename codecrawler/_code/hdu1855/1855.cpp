#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cctype>
using namespace std;

struct node
{
    char data;
    node* left,*right;
    node(char d=0,node*l=0,node*r=0):data(d),left(l),right(r){}
};

node *build(char data,node* left,node* right)
{
    node*father=new node(data,left,right);
    return father;
}

int main()
{
    string s;
    int cas;
    cin>>cas;
    while(cas--)
    {
        cin>>s;
        stack<node*>stck;
        queue<node*>que;
        string ans;
        for(size_t i=0;i!=s.size();i++)
        {
            if(islower(s[i]))
            {
                node* tree=new node(s[i],0,0);
                stck.push(tree);
            }
            else
            {
                node* r=stck.top();stck.pop();
                node* l=stck.top();stck.pop();
                stck.push(build(s[i],l,r));
            }
        }
        que.push(stck.top());
        while(!que.empty())
        {
            node* cur=que.front();que.pop();
            ans+=cur->data;
            if(cur->left)que.push(cur->left);
            if(cur->right)que.push(cur->right);
        }
        for(int i=ans.size()-1;i>-1;i--)
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}