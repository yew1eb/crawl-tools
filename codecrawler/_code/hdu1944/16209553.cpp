#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
int  s[101];  
int sg[10001];  
   
int g(int temp , int k)  
{  
    int mex[101],i;  
    memset(mex,0,sizeof(mex));  
    if(sg[temp]!=-1) return sg[temp]; //éåSä¸è´ï¼åæ¯ä¸ªæ°éçmexä¸æ ·ï¼æä»¥å¯ä»¥éå¤å©ç¨
    if(temp-s[0]<0) return sg[temp]=0; //s[0]ä¸ºéåä¸­æå°å¼ï¼temp-s[0]<0,åtempä¸å¯è½å°è¾¾å¶ä»ç¶æï¼ä¸å®ä¸ºP     
    for(i=0;i<k && temp-s[i]>=0;i++)  //å¤æ­æ¡ä»¶ï¼å ä¸ºs[]æäºåºï¼å½temp-s[i]<0å°±åæ­¢å¾ªç¯ã 
    {   
        mex[g(temp-s[i] , k)]=1;  //tempçåç»§SGå½æ°ä¸­çæ²¡æåºç°çæå°éè´æ°     
    }  
    for(i=0;;i++) //éè¿tempçåç»§SGå½æ°åºç°çéè´æ°å¾tempçç»æ  
    if(!mex[i])  return sg[temp]=i;  
}  
 

int comp(const void *a,const void *b)
{
return *(int *)a-*(int *)b;
}

 
int main()  
{  
    int  k,i ;  
    int n, t ,temp, ans; 
//    freopen("in.txt","r",stdin);
    while(scanf("%d",&k)!=EOF && k)  
    {  
        memset(sg,-1,sizeof(sg));  
        sg[0]=0;  
        for(i=0;i<k;i++) 
            scanf("%d",&s[i]);  
        qsort(s,k,sizeof(int),comp);  
        scanf("%d",&t);   
        while(t--)  
        {  
            ans=0;  
            scanf("%d",&n);  
            for(i=0;i<n;i++)   
            {  
                scanf("%d",&temp);    
                ans^=g(temp , k);  
            }    
         
            if(!ans)  printf("L"); //å¼æsumï¼=0ï¼è¯´æè¯¥ç¹ä¸ºå¿è´¥ç¹ï¼åªè½å°è¾¾å¿èç¹ã     
            else printf("W");  
        }  
        printf("\n");  
    }  
    return 0;  
}   
