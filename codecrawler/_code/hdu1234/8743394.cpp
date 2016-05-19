#include <stdio.h>
#include <string.h>
#define INF 0x7ffffff
int main()
{
    int t, n, i;
    char ID1[20],ID2[20],s1[20],s2[20],s3[20];
    int end, start, tmp;
    int h,m,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        end =-INF;
        start =INF;
        for(i=0; i<n; i++)
        {
            scanf("%s %s %s",s1,s2,s3);
            sscanf(s2,"%d:%d:%d",&h,&m,&s);
            tmp = h*3600+m*60+s;
            if(tmp<start)
            {
                start = tmp;
                strcpy(ID1,s1);
            }
            sscanf(s3,"%d:%d:%d",&h,&m,&s);
            tmp = h*3600+m*60+s;
            if(tmp>end)
            {
                end = tmp;
                strcpy(ID2,s1);
            }
        }
        printf("%s %s\n",ID1,ID2);
    }
    return 0;
}
