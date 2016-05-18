#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 100005;
const int MAXC = 52;
//int id[MAXC];
int chd[MAX][MAXC];
int sz;
void clear()
{
    memset(chd,0,sizeof(chd));
    sz = 0;
}
int change(char c)
{
    if(c=='S') return 0;
    if(c=='H') return 13;
    if(c=='D') return 13*2;
    if(c=='C') return 13*3;
    if(c=='A') return 0;
    if(c>'1'&&c<='9') return c-'1';
    if(c=='J') return 10;
    if(c=='Q') return 11;
    return 12;
}
int GetID(char *s)
{
    if(s[1]=='0') return 9+change(s[2]);
    return change(s[0])+change(s[1]);
}
void insert(int *id,int len)
{
    int cur = 0;
    for(int i=len-1;i>=0;i--)
    {
        if(!chd[cur][id[i]])
            chd[cur][id[i]] = ++sz;
        cur = chd[cur][id[i]];
    }
}

int main()
{
    int hand,card;
    char s[4];
    int OneHand[MAX];
    while(scanf("%d",&hand))
    {
        if(!hand) break;
        clear();
        for(int i=0;i<hand;i++)
        {
            scanf("%d",&card);
            for(int j=0;j<card;j++)
            {
                scanf("%s",s);
                OneHand[j] = GetID(s);
            }
            insert(OneHand,card);
        }
        printf("%d\n",sz);
    }
    return 0;
}