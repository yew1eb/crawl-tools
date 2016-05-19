#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;
vector<int>vec[300];
map<string, int>mpn, mpv;
char s1[200], s[10][20];
int vis[300];
string a, b;
bool dfs(int x, int y)
{
    vis[x]=1;
    if(x==y) return true;//æ²¡æç¹å¤ï¼ä¸å¼å§ææå®åå°forå¾ªç¯éé¢äºï¼ä¸ç´wa
    for(int i=0; i<vec[x].size(); i++)
    {
        int v = vec[x][i];
        if(!vis[v])
        {
            if(dfs(v, y)) return true;
        }
    }
    return false;
}
int main()
{
    int t, cas=1;
    scanf("%d", &t);
    gets(s1);
    while(t--)
    {
        for(int i=0;i<250; i++) vec[i].clear();
        mpn.clear();
        mpv.clear();
        printf("Case #%d:\n", cas++);
        int id=0;
        while(gets(s1))
        {
            int len = strlen(s1);
            if(s1[len-1]=='!') break;
            memset(s, '\0', sizeof(s));
            if(sscanf(s1, "%s%s%s%s%s%s", s[0],s[1],s[2],s[3],s[4],s[5])!=6)
            {
                if(s1[len-1]=='?')
                {
                    s1[len-1]='\0';
                    sscanf(s1, "%s%s%s", s[0], s[1], s[2]);
                    a = s[1], b = s[2];
                    memset(vis, 0, sizeof(vis));
                    bool f;
                    if(mpn.find(a)==mpn.end()) mpn[a] = id++;
                    if(strcmp(s[0], "can")==0)
                    {
                        if(mpv.find(b)==mpv.end()) mpv[b] = id++;
                        f = dfs(mpn[a], mpv[b]);
                    }
                    else
                    {
                        if(mpn.find(b)==mpn.end()) mpn[b] = id++;
                        f = dfs(mpn[a], mpn[b]);
                    }
                    if(f) printf("Y");
                    else printf("M");
                }
                else
                {
                    s1[len-1]='\0';
                    sscanf(s1, "%s%s%s", s[0], s[1], s[2]);
                    a=s[0], b=s[2];
                    if(mpn.find(a)==mpn.end()) mpn[a] = id++;
                    if(strcmp(s[1], "can")==0)
                    {
                        if(mpv.find(b)==mpv.end()) mpv[b] = id++;
                        vec[mpn[a]].push_back(mpv[b]);
                    }
                    else
                    {
                        if(mpn.find(b)==mpn.end()) mpn[b] = id++;
                        vec[mpn[a]].push_back(mpn[b]);
                    }
                } 
            }
            else
            {
                if(s1[len-1]=='?')
                {
                    s1[len-1]='\0';
                    sscanf(s1,"%s%s%s%s%s%s",s[0],s[1],s[2],s[3],s[4],s[5]);
                    memset(vis, 0, sizeof(vis));
                    bool f;
                    a=s[4], b=s[5];
                    if(mpv.find(a)==mpv.end()) mpv[a] = id++;
                    if(strcmp(s[0], "can")==0)
                    {
                        if(mpv.find(b)==mpv.end()) mpv[b] = id++;
                        f = dfs(mpv[a], mpv[b]);
                    }
                    else
                    {
                        if(mpn.find(b)==mpn.end()) mpn[b] = id++;
                        f = dfs(mpv[a], mpn[b]);
                    }
                    if(f) printf("Y");
                    else printf("M");
                }
                else
                {
                    s1[len-1]='\0';
                    sscanf(s1,"%s%s%s%s%s%s",s[0],s[1],s[2],s[3],s[4],s[5]);
                    a=s[3], b=s[5];
                    if(mpv.find(a)==mpv.end()) mpv[a] = id++;
                    if(strcmp(s[4],"can")==0)
                    {
                        if(mpv.find(b)==mpv.end()) mpv[b] = id++;
                        vec[mpv[a]].push_back(mpv[b]);
                    }
                    else
                    {
                        if(mpn.find(b)==mpn.end()) mpn[b] = id++;
                        vec[mpv[a]].push_back(mpn[b]);
                    }
                }
            }
        }
        putchar(10);
    }
    return 0;
}