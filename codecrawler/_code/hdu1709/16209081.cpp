#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"math.h"
int n,up;
int w[111];
int c1[10011],c2[10011];
int main()
{
    int i,l;
    int tot,ans;
    while(scanf("%d",&n)!=-1)
    {
        tot=0;
        for(i=0;i<n;i++)    {scanf("%d",&w[i]);tot+=w[i];}

        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        up=0;
        c1[0]=c2[0]=1;
        for(i=0;i<n;i++)
        {
            for(l=0;l<=up;l++)
            {
                if(!c1[l])    continue;
                if(!c2[l+w[i]])
                {
                    c2[l+w[i]]=1;
                    if(l+w[i]>up)        up=l+w[i];
                }
                if(!c2[abs(l-w[i])])
                {
                    c2[(abs(l-w[i]))]=1;
                    if(abs(l-w[i])>up)    up=abs(l-w[i]);
                }
            }
            for(l=0;l<=up;l++)    c1[l]=c2[l];
        }

        ans=0;
        for(l=1;l<=up;l++)    if(c1[l])    ans++;
        if(ans>=tot)    printf("0\n");
        else
        {
            printf("%d\n",tot-ans);
            for(l=1;l<=tot;l++)    if(!c1[l])    {printf("%d",l);break;}
            for(l++;l<=tot;l++)    if(!c1[l])    printf(" %d",l);
            printf("\n");
        }
    }
    return 0;
}