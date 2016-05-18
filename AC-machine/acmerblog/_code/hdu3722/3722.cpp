 #include<iostream>
 #include<string.h>
 #include<stdio.h>
 int mark[1002],n;
 char ss[202][1020];
 int g[202][202],s[202],t[202],lx[202],ly[202],link[202],d[202];
 char temp[1002];
 
 int max(int x,int y)
 {
     return x<y?y:x;
 }
 
 int min(int x,int y)
 {
     return x<y?x:y;
 }
 
 void rev(int x,int len)
 {
     int i,j;
     for(i=0,j=len-1;i<len;i++,j--)
         temp[j]=ss[x][i];
 }
 
 void build()
 {
     int i,j,len,k,count;
     for(i=0;i<n;i++)
         for(j=0;j<n;j++)
         {
             if(i==j)
             {
                 g[i][j]=0;
                 continue ;
             }
             len=strlen(ss[i]);
             rev(i,len);
             count=0; int len2=strlen(ss[j]);
             for(k=0;temp[k]==ss[j][k]&&k<len&&k<len2;k++)
                 count++;
             g[i][j]=count;
         }
 }
 
 int dfs(int x)
 {
     s[x]=1;
     for(int i=0;i<n;i++)
     {
         
         if(t[i]==1)
             continue;int temp=lx[x]+ly[i]-g[x][i];
         if(temp==0)
         {
             t[i]=1;
             if(link[i]==-1||dfs(link[i]))
             {
                 link[i]=x;
                 return 1;
             }
         }
         else d[i]=temp<d[i]?temp:d[i];
     }
     return 0;
 }
 
 void update()
 {
     int i,j;
     int a=1<<30;
 //    for(i=0;i<n;i++)
     //    if(s[i])
             for(j=0;j<n;j++)
                 if(!t[j])
                     a=min(a,d[j]);
    for(i=0;i<n;i++)
    {
        if(s[i]) lx[i]-=a;
        if(t[i]) ly[i]+=a;
    }
 }
 
 
 
 void KM()
 {
     int i,j;
     for(i=0;i<n;i++)
     {
         lx[i]=ly[i]=g[i][0];
         for(j=0;j<n;j++)
             lx[i]=max(lx[i],g[i][j]);
     }
     memset(link,-1,sizeof(link));
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
             d[j]=1<<30;
         while(1)
         {
             memset(s,0,sizeof(s));
             memset(t,0,sizeof(t));
             if(dfs(i))
                 break;
             else update();
         }
     }
 }
 
 
 int main()
 {
     int i,j;
     while(scanf("%d",&n)!=EOF)
     {
         for(i=0;i<n;i++)
             scanf("%s",ss[i]);
         build();
         KM();
         for(i=0;i<n;i++)
             dfs(i);
         int ans=0;
         for(i=0;i<n;i++)
             ans+=g[link[i]][i];
         
         printf("%d\n",ans);
     }
     return 0;
 }
