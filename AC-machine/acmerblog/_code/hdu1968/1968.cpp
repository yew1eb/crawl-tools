#include<set>
#include<map>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20;
const int MAXN = 2010;

int cnt;
stack<set<int> >stk;
map<set<int> , int>mp;
set<int>s1 , s2;

void pop(){
    s1 = stk.top();
    stk.pop();
    
    s2 = stk.top();
    stk.pop();
}
// push
void Push(){
    set<int>s;
    stk.push(s);
    puts("0");
}
// dup 
void Dup(){
    set<int>s;
    s = stk.top();
    stk.push(s);
    printf("%d\n" , s.size());
}
// union 
void Union(){
    pop();
    // 
    set<int>::iterator it;
    for(it = s1.begin() ; it != s1.end() ; it++)
        s2.insert(*it);
    stk.push(s2);
    printf("%d\n" , s2.size());
}
// Intersect
void Intersect(){
    pop();
    //
    set<int>s3;
    set<int>::iterator it;
    for(it = s1.begin() ; it != s1.end() ; it++){
        if(s2.find(*it) != s2.end())   
            s3.insert(*it); 
    }
    stk.push(s3);
    printf("%d\n" , s3.size());
}
// add
void Add(){
    pop();
    //
    if(s1.empty())
        s2.insert(0); 
    else{
        if(!mp[s1])
            mp[s1] = cnt++;
        s2.insert(cnt++);
    }
    stk.push(s2);
    printf("%d\n" , s2.size());
}

int main(){
    int Case , n;
    char str[N];
    scanf("%d" , &Case);
    while(Case--){
        scanf("%d" , &n); 
        while(!stk.empty())
            stk.pop();
        cnt = MAXN;
        mp.clear();
        while(n--){
            scanf("%s" , str); 
            if(str[0] == 'P')
                Push();
            else if(str[0] == 'D')
                Dup();
            else if(str[0] == 'U')
                Union();
            else if(str[0] == 'I')
                Intersect();
            else
                Add();
        } 
        puts("***");
    }
    return 0;
}