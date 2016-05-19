#include<istream>
#include<string.h>
using namespace std;
int main()
{
    int t,al,i;
    char a[51];
    char c;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            getchar();
            scanf("%s",a);
            al=strlen(a);
            if(al%2!=0)continue;
            for(i=0;i<al;i+=2)
            {
                c=a[i+1];
                a[i+1]=a[i];
                a[i]=c;
                printf("%c%c",a[i],a[i+1]);
            }
            printf("\n");
        }
    }
    return 0;
}