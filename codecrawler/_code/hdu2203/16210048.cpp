#include<stdio.h>
#include<string.h>
#include<cstring>
#define val 100005
int lens,lenp,next[val];
char s[val*2],p[val];
bool kmp();
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        scanf("%s",&p);
        lens=strlen(s);
        lenp=strlen(p);
        strncpy(s+lens,s,lens);
        lens*=2;
        if(kmp()) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
bool kmp()
{
    void set_next();
    int i,j;
    i=j=0;
    set_next();
    while(i<lens&&j<lenp)
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
        }
        else j=next[j];
    }
    if(j<lenp) return false;
    else return true;
}
void set_next()
{
    int j,k;
    j=0,k=-1;
    next[j]=k;
    while(j<lenp)
    {
        if(k==-1||p[j]==p[k])
        {
            k++;
            j++;
            next[j]=k;
        }
        else k=next[k];
    }
}
