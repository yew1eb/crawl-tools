#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
bool map[27][27];
bool bfs()
{
    queue<int> Q;
    int now, i;
    Q.push(1); //push 'b'
    while(!Q.empty())
    {
        now = Q.front(); Q.pop();
        for(i=0; i<26; i++)
            if(map[now][i])
            {
                if(i==12) // found 'm'
                {
                    return true;
                }
                map[now][i] = false;
                Q.push(i);
            }
    }
    return false;
}
int main()
{
    int i;
    int a, b;
    char word[101];
    while(scanf("%s",word)!=EOF)
    {
        memset(map,false,sizeof(map));
        a = word[0]-'a';
        b = word[strlen(word) -1 ] - 'a';
        map[a][b] = true;
        while(scanf("%s",word))
        {
            if(word[0]=='0') break;
            a = word[0]-'a';
            b = word[strlen(word) -1 ] - 'a';
            map[a][b] = true;
        }
        if( bfs() ) printf("Yes.\n");
        else printf("No.\n");
    }
}
