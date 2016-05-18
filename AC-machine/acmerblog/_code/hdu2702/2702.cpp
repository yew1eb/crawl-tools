Code
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <stack>
using namespace std;

int R,C;
char Map[10][10];
int Move2[6][2] = {{-1,-1},{-1,0},{0,-1},{0,1},{1,-1},{1,0}};
int Move1[6][2] = {{-1,0},{-1,1},{0,-1},{0,1},{1,0},{1,1}};
char Path[20];
bool bVisited[10][10];
int ileft,iright;
int cnum,pos;

inline bool InBoundary(int x,int y)
{
    
    if(x >= 0 && x<R && y>=0 && y<C+x%2)
        return true;
    return false;
}


bool Evaluate(int start,int n,int &value)
{
     stack<int> s1;
     stack<char> s2;
     int i = start;
     int t = 0;
      t = Path[i]-'0';  i++;
      if(isdigit(Path[i]))
      {
           if(t == 0)  return false;
       }
       while(isdigit(Path[i]))
       {
            t*=10; t+=Path[i]-'0';
            if(t >= 100)
                 return false;
             i++;
        }

    s1.push(t);
     while(1)
     {
             if(i > n-1)
             { 
                  if(!isdigit(Path[n-1])) return false;
                  break;
             }
             if(!isdigit(Path[i]))
             {
                 if(!s2.empty()) return false;
                 else     s2.push(Path[i]); 
                 i++;
             }
             else
             {
                 t = Path[i]-'0';  i++;
                 if(isdigit(Path[i]))
                 {
                    if(t == 0)
                       return false;
                 }
                 while(isdigit(Path[i]))
                 {
                     t*=10; t+=Path[i]-'0';
                     if(t >= 100)
                       return false;
                     i++;
                 }
                 
                    char op = s2.top();s2.pop();
                    int re = s1.top();s1.pop();
                    switch(op)
                    {
                              case '+':s1.push(re+t); break;    
                              case '-':s1.push(re-t);break;
          