/*
è¿éé¢ä¹åå°±çå°è¿äºï¼åªæ¯ä¸ç´ä¸ç¥éæä¹å»å¤æ­ä»ä¹ææ¯IPå°åï¼ç´å°ä»å¤©åè
äºå«äººçä»£ç æç¥éï¼IPå°ååºè¯¥æ»¡è¶³å¦ä¸æ¡ä»¶ï¼
1.  '.'æä¸åªè½æ3ä¸ª
2.  4ä¸ªæ¾æ°å­çä½ç½®ï¼é¿åº¦åºè¯¥å¨1~3ä¹é´(å«è¾¹ç)
3.  æ¯ä¸ªæ°å­åºè¯¥ï¼1~255(å«è¾¹ç)
4.  ä¸è½æç¹æ®å­ç¬¦
*/

#include"stdio.h"
#include"string.h"
int main()
{
    int flag;
    char str[111];
    int temp;
    int i,l;
    int place[10],k;
    while(gets(str)!=0)
    {
        //'.'æä¸åªè½æ3ä¸ª
        place[0]=-1;
        k=1;
        temp=0;
        for(i=0;str[i];i++)    if(str[i]=='.')    {temp++;place[k]=i;k++;}
        if(temp!=3)
        {
            printf("NO\n");
            continue;
        }
        place[k]=i;
        k++;


        //ä¸è½æç¹æ®å­ç¬¦
        flag=0;
        for(i=0;str[i];i++)
        {
            if(!((str[i]=='.')||('0'<=str[i]&&str[i]<='9')))
            {
                printf("NO\n");
                flag=1;
                break;
            }
        }
        if(flag==1)    continue;


        //4ä¸ªæ¾æ°å­çä½ç½®ï¼é¿åº¦åºè¯¥å¨1~3ä¹é´(å«è¾¹ç)
        flag=0;
        for(i=1;i<k;i++)
        {
            if(place[i]-place[i-1]==1||place[i]-place[i-1]>4)
            {
                printf("NO\n");
                flag=1;
                break;
            }
        }
        if(flag==1)    continue;


        //æ¯ä¸ªæ°å­åºè¯¥ï¼1~255(å«è¾¹ç)
        flag=0;
        for(i=1;i<k;i++)
        {
            temp=0;
            for(l=place[i-1]+1;l<place[i];l++)
            {
                temp*=10;
                temp+=str[l]-'0';
            }
            if(temp>=256)
            {
                printf("NO\n");
                flag=1;
                break;
            }
        }
        if(flag==1)    continue;


        printf("YES\n");
    }
    return 0;
}
