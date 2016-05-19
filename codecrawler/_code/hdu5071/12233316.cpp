#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;
struct node{
    int u;
    ll c;
    node(int _u=0,ll _c=0):u(_u),c(_c){}
};
vector<node> q;
int aot;

int find(int x){
    for(int i=0; i<q.size(); ++i)
        if(q[i].u==x) return i;
    return -1;
}

void Add(int x){
    if(find(x)!=-1) puts("same priority.");
    else{
        q.push_back(node(x,0));
        puts("success.");
    }
}
void Close(int x){
    int pos = find(x);
    if(pos!=-1){
        if(x==aot) aot = 0;
        printf("close %d with %I64d.\n", q[pos].u, q[pos].c);
        q.erase(q.begin()+pos);
    }else 
        puts("invalid priority.");
}

void Chat(int x){
    if(!q.size()) puts("empty.");
    else {
        int pos = 0;
        if(aot)
            pos = find(aot);
        q[pos].c += x;
        puts("success.");
    }
}

void Rotate(int x){
    if(x<1 || x>q.size()){
        puts("out of range.");
    }
    else{
        int pos = x-1;
        node p= q[pos];
        q.erase(q.begin()+pos);
        q.insert(q.begin(),p);
        puts("success.");
    }
}

void Prior(){
    int maxp=0, pos=-1;
    if(q.empty()){
        puts("empty.");
        return;
    }
    for(int i=0;i<q.size();i++){
        if(q[i].u > maxp)
            maxp=q[i].u,pos=i;
    }
    Rotate(pos+1);
}

void Choose(int x){
    int pos=find(x);
    if(pos==-1)
        puts("invalid priority.");
    else
        Rotate(pos+1);
}

void Top(int x){
    int pos=find(x);
    if(pos==-1)
        puts("invalid priority.");
    else{
        aot=x;
        puts("success.");
    }
}

void Untop()
{
    if(aot==0)
    {
        puts("no such person.");
    }
    else
    {
        aot=0;
        puts("success.");
    }
}

void Bye(){
    if(aot){
        int pos = find(aot);
        if(q[pos].c)
            printf("Bye %d: %I64d\n",q[pos].u, q[pos].c);
        q.erase(q.begin()+pos);
    }
    for(int i=0;i<q.size();i++)
    {
        if(q[i].c)
            printf("Bye %d: %I64d\n",q[i].u, q[i].c);
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int T, n;
    int x;
    string s;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        q.clear(); aot = 0;
        for(int k=1; k<=n; ++k){
            printf("Operation #%d: ", k);
            cin>>s;
               if(s!="Prior" && s!="Untop")
                   scanf("%d", &x);
              if(s=="Add")    Add(x);
               else if(s=="Close")    Close(x);
              else if(s=="Chat")    Chat(x);
            else if(s=="Rotate") Rotate(x);
            else if(s=="Prior")    Prior();
            else if(s=="Choose") Choose(x);
            else if(s=="Top") Top(x);
            else if(s=="Untop") Untop();
        }
        Bye();
    }
    return 0;
}
