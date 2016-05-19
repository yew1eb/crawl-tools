#include<cstdio>
#include<cstring>
using namespace std;

char s[200000];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int w=0,y=0,h=0;
        int len=strlen(s);
        for(int i=0; i<len; i++)
        {
            if(w==0&&s[i]=='w')
            {
                w=1;
                continue;
            }
            if(w==0&&i>=1&&s[i]=='v'&&s[i-1]=='v')
            {
                w=1;
                s[i]=s[i-1]='a';
                continue;
            }
            if(w==1&&y==0&&s[i]=='y')
            {
                y=1;
                continue;
            }
            if(w==1&&y==1&&h==0&&s[i]=='h')
            {
                h=1;
                break;
            }
        }
        if(w==1&&y==1&&h==1)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
