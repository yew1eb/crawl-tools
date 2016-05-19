 #include<cstdio>
 #include<cstring>
 const int maxn=1000000+5;
 char s[maxn];
 int next[maxn];
 int snext[maxn];
 void get_next(char *T,int len,int *next)
 {
     next[0]=-1;
     for(int i=1;i<=len;i++)
     {
         int j=next[i-1];
         while(T[i]!=T[j+1]&& j>=0)
         j=next[j];
         if(T[i]==T[j+1])next[i]=j+1;
         else next[i]=0;
      }
 }
 bool find(char *a,int n,char *b,int m,int *next)
 {
     get_next(b,m,next);
     int j=0;
     for(int i=0;i<n;i++)
     {
        while(j&&b[j]!=a[i]) j=next[j];
        if(b[j]==a[i]) j++;
        if(j==m) return true;
     }
     return false;
 }
 bool compare(char *a,char *b,int len)
 {
     for(int i=0;i<len;i++)
         if(a[i]!=b[i]) return false;
     return true;
 }
 int main()
 {
     int n;
     while(scanf("%d",&n)!=EOF)
     {
         while(n--)
         {
             getchar();
             scanf("%s",s);
             int len=strlen(s);
             get_next(s,len,snext);
             char *rear=s+len;
             int cur=snext[len-1];
             while(cur>len/3)
                 cur=snext[cur];
             int flag=0;
             for(int i=cur;i>=0;i=snext[i])
             {
                 int le=i+1;
                 if(!compare(s,rear-le,le)) continue;
                 if(find(s+le,len-2*le,rear-le,le,next)) {flag=1;printf("%d\n",le);break;}
             }
             if(!flag) printf("0\n");
         }
     }
     return 0;
 }
