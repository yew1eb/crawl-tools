#include"stdio.h"
#include"string.h"
int main()
{
    int hash[5555],k;
    char temp[5555];
    char str[5555];
    int i;
    int count;
    int a,b;
    int flag;


    while(scanf("%s",temp)!=-1)
    {
        k=0;
        memset(hash,0,sizeof(hash));
        hash[0]=1;
        str[0]=temp[0];
        ///åç¼©
        for(i=1;temp[i];i++)               //kè¡¨ç¤ºæåé¢çåç´ çä¸æ ã
        {
            if(temp[i]==temp[i-1])
            {
                hash[k]++;
            }
            else
            {
                k++;
                hash[k]=1;
                str[k]=temp[i];
            }
        }
        k++;                               //kè¡¨ç¤ºæ»åç´ æ°ã


        count=0;
        for(i=0;i<k;i++)
        {
            count+=(1+hash[i])*hash[i]/2;  //åå«èªèº«æææåµã
        }
        for(i=0;i<k;i++)
        {
            a=i-1;
            b=i+1;
            if(a<0||b>k-1)
                continue;
            flag=0;
            while(str[a]==str[b]&&hash[a]==hash[b])
            {
                count+=hash[a];
                a--;
                b++;
                if(a<0||b>k-1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0&&str[a]==str[b])
            {
                count+=hash[a]>hash[b]?hash[b]:hash[a];
            }
        }


        printf("%d\n",count);
    }
    return 0;
}