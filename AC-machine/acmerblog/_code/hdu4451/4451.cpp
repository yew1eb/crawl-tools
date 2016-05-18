#include"stdio.h"
#include"string.h"
int main()
{
    int n1,n2,n3;
    int ans;
    int count1[1111],count2[1111];
    int i,l;
    int m;
    char str1[111],str2[111];
    int a,b;
    while(scanf("%d%d%d",&n1,&n2,&n3),n1,n2,n3)
    {
        scanf("%d",&m);
        memset(count1,0,sizeof(count1));
        memset(count2,0,sizeof(count2));
        while(m--)
        {
            scanf("%s%d%s%d",str1,&a,str2,&b);
            if(strcmp(str1,"clothes")==0)   count1[b]++;
            else                            count2[a]++;
        }
        ans=0;
        for(i=1;i<=n2;i++)   ans+=(n1-count1[i])*(n3-count2[i]);
        printf("%d\n",ans);
    }
    return 0;
}