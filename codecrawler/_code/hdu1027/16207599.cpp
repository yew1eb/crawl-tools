#include"stdio.h"
#include"string.h"
int main()
{
    int n,m;
    int key,ans[1011];
    int jie[10];
    int i,l;
    int temp,up;
    int base,base_t;
    int hash[10];
    ///jie
    jie[0]=1;
    jie[1]=1;
    for(i=2;i<10;i++)    jie[i]=i*jie[i-1];


    while(scanf("%d%d",&n,&m)!=-1)
    {
        memset(hash,0,sizeof(hash));            //æ³¨æï¼hashä»0å¼å§ç¨ï¼baseåå¶ç§åº
        base=1;
        key=0;
        ///ç­
        /*****/
        if(n>=9)
        {
            i=1;
            while(n-key>=9)
                ans[key++]=i++;
            base=i;
        }
        /*****/


        up=n-key;
        base_t=0;                               //è¿ä¸ªbase_tåmç§åº
        while(key<n)
        {
            for(temp=1;temp*jie[n-key-1]+base_t<m;temp++);
            for(i=0,l=1;i<up;i++,l++)
            {
                if(hash[i])    l--;
                if(l==temp)    break;
            }
            base_t+=(temp-1)*jie[n-key-1];
            ans[key++]=i+base;
            hash[i]=1;
        }


        for(i=0;i<n-1;i++)    printf("%d ",ans[i]);
        printf("%d\n",ans[i]);
    }
    return 0;
}