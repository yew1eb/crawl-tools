#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,t;
struct cam
{ 
    char str[50]; //éå
    int score1; //å¾å
    int score2; //åèç
    int score3; //è¿ç
}list[50000];
int find(char ss[])  //æ¥æ¾å­ç¬¦ä¸²å¹¶è¿åä¸æ 
{
    int i;
    if(t==-1)
    {
        strcpy(list[0].str,ss);
        t=0;
        return t;
    }
    for(i=0;i<=t;i++)
    if(strcmp(list[i].str,ss)==0)
    return i;
    t++;
    strcpy(list[t].str,ss);
    return t;
}
int cmp(const void *a,const void *b)  //ä»å¤§å°å°æåº
{
    if((*(struct cam *)a).score1!=(*(struct cam *)b).score1)
    return (*(struct cam *)b).score1-(*(struct cam *)a).score1;
    if((*(struct cam *)a).score2!=(*(struct cam *)b).score2)
    return (*(struct cam *)b).score2-(*(struct cam *)a).score2;
    if((*(struct cam *)a).score3!=(*(struct cam *)b).score3)
    return (*(struct cam *)b).score3-(*(struct cam *)a).score3;
    return strcmp((*(struct cam *)a).str,(*(struct cam *)b).str);
}
int main()
{
    int i,k;
    char s1[50],s2[50],temp[10];
    int a,b;
    int p,q;
    while(scanf("%d",&n)!=EOF)
    {
        k=n*(n-1);
        t=-1;
        memset(list,0,sizeof(list));
        while(k--)
        {
            scanf("%s%s%s %d:%d",s1,temp,s2,&a,&b);
            p=find(s1);
            q=find(s2);
            if(a>b)    //å¾å
            list[p].score1+=3;
            else if(a==b)
            {
                list[p].score1+=1;
                list[q].score1+=1;
            }
            else
            list[q].score1+=3;
            list[p].score2+=(a-b);  //åèç
            list[q].score2+=(b-a);
            list[p].score3+=a;  //è¿ç
            list[q].score3+=b;
        }
        qsort(list,n,sizeof(struct cam),cmp);
        for(i=0;i<n;i++)
        printf("%s %d\n",list[i].str,list[i].score1);
        printf("\n");
    }
    return 0;
}



            


