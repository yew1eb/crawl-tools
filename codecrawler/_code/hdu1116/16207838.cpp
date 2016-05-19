 #include<stdio.h>   
 #include<string.h>   
 #include<math.h>   
 #define N 30   
 int father[N],vis[N];  
 //father[i] è¡¨ç¤ºèç¹ i ç BOSS ï¼ vis[i]è¡¨ç¤ºèç¹ i åºç°è¿ 
 int findx(int x)  
 {  //æ¾èç¹  x ç BOSS ï¼ 
     if(father[x]!=x)  
         father[x]=findx(father[x]);  
     return father[x];  
 }  
 void merge(int a,int b)  
 {  // åå¹¶ èç¹ a åèç¹ b
     int x,y;  
     x=findx(a);  
     y=findx(b);  
     if(x!=y) father[x]=y;  
 }  
 int main()  
 {  
     int text,cnt,i,j,n,out[N],in[N],p[30],a,b;  
     char str[1001];  
     scanf("%d",&text);  
     while(text--)  
     {  
         scanf("%d",&n);  
         memset(out,0,sizeof(out));  
         memset(in,0,sizeof(in));  
         memset(vis,0,sizeof(vis));  
         for(i=0;i<26;i++)  
             father[i]=i;  //åå§åæ°ç» 
         while(n--)  
         {  // å¤çæç»ä¿¡æ¯ ï¼ 
             scanf("%s",str);  
             a=str[0]-'a';  
             b=str[strlen(str)-1]-'a';  
             merge(a,b);  
             out[a]++;  
             in[b]++;  // è®°å½èç¹ a å bçå¥åº¦ååºåº¦ 
             vis[a]=1;  
             vis[b]=1; //æ è®°èç¹ a å bçåºç° 
         }  
         for(i=0;i<26;i++)  
             father[i]=findx(i);  //æ¾åºæ¯ä¸ªèç¹ç BOSS  
         for(cnt=0,i=0;i<26;i++)  
             if(vis[i] && father[i]==i)  
                 cnt++;  // ç»è®¡æç» BOSS å³æ ¹èç¹çä¸ªæ° ã 
         if(cnt>1)  //å¾ä¸è¿é   
         {  
             printf("The door cannot be opened.\n");  
             continue;  
         }  
           
         for(j=0,i=0;i<26;i++)  
             if(vis[i] && out[i]!=in[i])  
                 p[j++]=i;  //ç»è®¡å¥åº¦ååºåº¦ä¸ç¸ç­çç¹çä¿¡æ¯ 
         if(j==0)   
         {//æ¬§æåè·¯ï¼å³ç¯   
             printf("Ordering is possible.\n");  
             continue;  
         }  
         if(j==2 && ( out[p[0]]-in[p[0]]==1 && in[p[1]]-out[p[1]]==1  
             || out[p[1]]-in[p[1]]==1 && in[p[0]]-out[p[0]]==1 ) )  
         {//æ¬§æéè·¯   
             printf("Ordering is possible.\n");  
             continue;  
         }  
         printf("The door cannot be opened.\n");  
     }  
     return 0;  
 }  