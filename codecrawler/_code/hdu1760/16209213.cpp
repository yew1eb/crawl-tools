#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<memory.h>
using namespace std;
map<string,int>sg;
map<string,bool>h;
char str[51][51],s[2505];
int n,m;
bool judge(int x,int y)
{
    if(str[x][y+1]=='0'&&str[x+1][y]=='0'&&str[x+1][y+1]=='0')
    return true;
    return false;
}
void change(int x,int y,char c)
{
   str[x][y]=c;str[x+1][y]=c;str[x][y+1]=c;str[x+1][y+1]=c;
}
void zhuanhuan()
{
    strcpy(s,"");
    for(int i=0;i<n;i++)
    strcat(s,str[i]);
}
int search()
{
    int num[50];
    memset(num,0,sizeof(num));
    zhuanhuan();h[s]=1;
    for(int i=0;i<n-1;i++)
    for(int j=0;j<m-1;j++)
    {
        if(str[i][j]=='0')
        {
            if(judge(i,j))
            {
                change(i,j,'1');zhuanhuan();
                int k;
                if(h[s]) k=sg[s];
                else k=search();
                num[k]=1;
                change(i,j,'0');
            }
        }
    }
    for(int i=0;;i++)
    if(num[i]==0) {zhuanhuan();sg[s]=i;return i;    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        scanf("%s",str[i]);
        sg.clear();h.clear();
        int ans=search();
        if(ans) puts("Yes");
        else puts("No");
    }
    return 0;
}
/*
4 4
0000
0000
0000
0000
4 4
0000
0010
0100
0000
*/
