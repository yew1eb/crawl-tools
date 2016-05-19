#include<stdio.h>
#include<set>
using namespace std;
int main()
{
    int i,n,m,j;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        set<int>s;
            for(i=1;i<=n;i++)
            {
                scanf("%d",&j);
                s.insert(j);
            }
            for(i=1;i<=m;i++)
            {
                scanf("%d",&j);
                s.insert(j);
            }
            set<int>::iterator it;
            set<int>::iterator it1;
            it1=s.end();
            it1--;
            for(it=s.begin();it!=it1;it++)
            {
                printf("%d ",*it);
            }
            printf("%d\n",*it);
    }
    return 0;
}
