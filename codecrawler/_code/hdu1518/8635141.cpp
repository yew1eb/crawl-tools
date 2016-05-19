#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>
using namespace std;
int num[25],n;
bool visit[25];
int ave;

bool dfs(const int &rest,const int &sum,const int &cur) //rest´ú±íµ±Ç°±ßµÄÊ£Óà³¤¶È, sum´ú±íÊ£ÓàÄ¾¹÷µÄ×Ü³¤¶È, cur¼ÇÂ¼µ±Ç°µÄÄ¾¹÷
{
    if(sum==ave)    //µ½ÁËÕâÀï´ú±íÒÑ¾­ÕÒµ½ÈýÌõ±ßÁË£¬µÚËÄÌõ±ß²»ÓÃÕÒÁË
        return true;

    for(int i=cur;i<n;++i)
    {
        if (num[i]==num[i-1] && !visit[i-1])    //Èç¹ûÕâÌõ±ßºÍÉÏÒ»Ìõ±ßµÄ³¤¶ÈÒ»Ñù£¬ÇÒÉÏÒ»Ìõ±ßÃ»ÓÐÓÃÉÏ£¬ÄÇÕâÌõ±ß¼õµô
            continue;

        if(!visit[i] && num[i]<=rest)
        {
            visit[i]=true;
            if(rest==num[i])
            {
                //±ê¼Ç1£¬ÕÒµ½Ò»Ìõ±ßºó£¬½øÈëÏÂÒ»Ìõ±ß
                if(dfs(ave,sum-rest,0))
                    return true;
            }
            else if( dfs( rest-num[i], sum-num[i],i))
                return true;
            visit[i]=false;

            //Õâ¸ö¶ÔÓ¦´Ó±ê¼Ç1½øÈëµÄ×´Ì¬£¬´ÓÍ·(0)¿ªÊ¼ÕÒÒ»Ìõ×î³¤Ã»ÓÐÓÃ¹ýµÄ±ß£¬Èç¹ûÕâÌõ±ß¾­¹ýÉÏÃæ¼¸²½»¹ÊÇÎÞ·¨ÓÃµ½£¬Ôò´ú±íµ±³õ×´Ì¬²»¿ÉÈ¡
            if(rest==ave) return false;
        }
    }
    return false;
}

int main(void)
{
    int ncases;
    scanf("%d",&ncases);
    while(ncases--)
    {
        int sum=0;
        int maxlen=0;
        bool ans=false;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&num[i]);
            sum+=num[i];
            maxlen = max(num[i],maxlen);    //ÇóËùÓÐÄ¾¹÷ÖÐ×î³¤Ä¾¹÷
        }
        ave = sum/4;
        if(sum%4 || maxlen>ave)  //Èç¹û×ÜµÄ³¤¶È²»ÄÜ±»4Õû³ý£¬»òÕß×î³¤Ä¾¹÷´óÓÚ±ß³¤¶È£¬¼õµô
            goto end;

        memset(visit,false,sizeof(visit));
        sort(num,num+n,greater<int>());   //ËùÓÐÄ¾¹÷°´ÕÕ³¤¶ÈÅÅÐò
        ans=dfs(ave,sum,0);
end:
        if(ans)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
