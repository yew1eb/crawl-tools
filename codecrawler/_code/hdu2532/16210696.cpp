#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define le 252
#define lne 1002
#define el 22
#define eel 12
struct haha
{
    char word[eel][el],out[le];
    int id,count,len;//lenæ¯åè¯çä¸ªæ°  countæ¯è®ºæå¼ç¨çæ¬¡æ° idæ¯è¾å¥ç¼å·
}a[1111];
int cmp(const void *s1,const void *s2)
{
  return strcmp((char *)s1,(char *)s2);
}
int ccmp(const void *a,const void *b)
{
         if((*(struct haha *)a).count==(*(struct haha *)b).count)
             return (*(struct haha *)a).id>(*(struct haha *)b).id?1:-1;
         else return (*(struct haha *)a).count<(*(struct haha *)b).count?1:-1;
}
int solve(char *str,int pos)
{
    int i,j,t,len=strlen(str);
    j=t=0;
    int flag=0;
    char ss[100];
    for(i=0;i<=len;i++)
    {
        if(isalpha(str[i]))
        {
              if(str[i]>='A'&&str[i]<='Z')
              {
                      ss[j++]=str[i]+32;
              }
              else ss[j++]=str[i];
              flag=1;
        }
        else  if(flag)//æ³¨æè¿éå¾éè¦  å ä¸ºé²æ­¢ç©ºå­ç¬¦ä¸²å å¥å°wordä¸­ è¿æ ·å¯è½ä¼è¶è¿è½ä¿å­çä¸ªæ°å³12ä¸ª
        {//ä¸è¦è®©ç©ºæ ¼ä»¥åç©ºå­ç¬¦ä¸²ä¿å­è¿æ¥ 
            ss[j]='\0';
            j=0;
            flag=0;
            strcpy(a[pos].word[t++],ss);
        }
    }
    return t;
}
int find(int pos)
{
    int i,j,c2,c1,flag=0;
    c1=a[1100].len;
    c2=a[pos].len;
    if(c1>c2) return 0;
    for(i=0;i<c1;i++)
    {
        flag=0;
        for(j=0;j<c2;j++)
        {
              if(strcmp(a[1100].word[i],a[pos].word[j])==0)
                 {flag=1; break;}
        }
        if(flag==0)
            return 0;
    }
    return 1;

}
int main()
{
    int n,i,m;
    while(scanf("%d",&n)!=EOF)
    {
        if(!n) break;
        for(i=0;i<n;i++)
        {
            getchar();
            gets(a[i].out);
            scanf("%d",&a[i].count);
           int t=solve(a[i].out,i);
          a[i].len = t;
          a[i].id=i;
           qsort (a[i].word,t,sizeof(a[i].word[0]),cmp); 
        }
        scanf("%d",&m);
        qsort(a,n,sizeof(a[0]),ccmp); 
        getchar();
        while(m--)
        {
            gets(a[1100].out);
             int t=solve(a[1100].out,1100);//ç¨a[1100]ä¿å­æä»¬è¦æ¥æ¾çæ°æ®
            a[1100].len=t;
            for(i=0;i<n;i++)
            {
                if(find(i))
                {
                    printf("%s\n",a[i].out);
                }
            }
            printf("***\n");
        }
        printf("---\n");
    }
    return 0;
}