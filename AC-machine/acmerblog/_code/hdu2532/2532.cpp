#include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 typedef struct record
 {
     int num;
     int count;
     int keyL;
     char name[300];
     char afname[300];
     char key[11][21];
 }Record;
 Record rec[1001];
 Record qy;
 int divide(char a[],char b[11][21],int n)
 {
     int cur=0,j=0;
     for(int i=0;i<n;i++)
     {
         if(a[i]==' ')
         {cur++;j=0;}
         else
             b[cur][j++]=a[i];
     }
     return cur+1;
 }
 int cmp(const void *a,const void *b)
 {
     Record c = *(Record *)a;
     Record d = *(Record *)b;
     if(c.count==d.count)
         return c.num - d.num;
     else return d.count - c.count;//优先按coun排序，大的在前
 }
 
 int match(char qry[11][21],char tar[11][21],int qn,int tn)
 {
     int num=0;
     for(int x=0;x<qn;x++)
     {
         for(int y=0;y<tn;y++)
             if(strcmp(qry[x],tar[y])==0)
             {
                 num++;
                 break;
             }
     }
     if(num==qn)
         return 1;
     else
         return 0;
 }
 
 void init(char a[],int n,char b[])
 {
     for(int ii=0;ii<n;ii++)
     {
         if(a[ii]<='Z'&&a[ii]>='A')
             {
              b[ii]=char(a[ii]+32);
             }
         else
             b[ii]=a[ii];
     }
 
 }
 int main()
 {
     int T,i;
     while(scanf("%d",&T))
     {
         if(T==0)break;
         memset(rec,0,sizeof(Record)*T);
         getchar();
         for(i=0;i<T;i++)
         {
             gets(rec[i].name);
             init(rec[i].name,strlen(rec[i].name),rec[i].afname);
             scanf("%d",&rec[i].count);
             getchar();
             rec[i].keyL=divide(rec[i].afname,rec[i].key,strlen(rec[i].name));
             rec[i].num=i+1;
         }
         qsort(rec,T,sizeof(Record),cmp);
         int k;
         scanf("%d",&k);getchar();
         for(i=0;i<k;i++)
         {
             memset(&qy,0,sizeof(Record));
             gets(qy.name);
             init(qy.name,strlen(qy.name),qy.afname);
             qy.keyL=divide(qy.afname,qy.key,strlen(qy.name));
             for(int j=0;j<T;j++)
             {
                 if(match(qy.key,rec[j].key,qy.keyL,rec[j].keyL))
                 {
                     puts(rec[j].name);
                 }
             }
             printf("***\n");
         }
         printf("---\n");
     }
     return 0;
 }