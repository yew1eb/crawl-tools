#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define M 105

char a[M+2], b[M+2];

char book[1000][M+2];

int cmp(char *s1, char *s2) {
    for(int i = 0; i <= M; i++) {
        if(i == M) {
            return s1[i] - s2[i];
        }
        if(s1[i] == s2[i])
            continue;
        else
            return s1[i] - s2[i];
    }
}

int find1(int i, char *x) {
    int low = 0, high = i, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        int t = cmp(book[mid], x);
        if(t > 0) 
            high = mid - 1;
        else if(t == 0)
            return mid - 1;
        else 
            low = mid + 1;
    }
    return high;
}

int find2(int i,char *x) {
    int low = 0, high = i, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        int t = cmp(book[mid], x);
        if(t > 0) 
            high = mid - 1;
        else if(t == 0)
            return mid + 1;
        else 
            low = mid + 1;
    }
    return low;
}

int main()
{
    int p=M,i=2;  //pç¨äºæ è®°æé«ä½çä½ç½® 
    book[0][M]=1,book[1][M]=2;
    while(book[i-1][M-100]<=1)
    {
        for(int j=M;j>=p;--j)
            book[i][j]=book[i-1][j]+book[i-2][j];
        for(int j=M;j>=p;--j)
        {
            int c=book[i][j]/10;
            book[i][j]%=10;
            book[i][j-1]+=c;
        }     //å³æ¶è¿ä½æä½ 
        if(book[i][p-1]>0) //å¤æ­æ¯å¦æé«ä½åçåå 
            --p;//å¦æå½åçæé«ä½çä¸ä¸ä½ä¸ä¸ºé¶,åæéåä¸ 
        ++i; 
    }    
    while(scanf("%s%s",a,b),a[0]-'0'||b[0]-'0')
    {
        int cnt=0,p;
        int last1=strlen(a)-1;
        int last2=strlen(b)-1;
        for(int j=last1,k=M;j>=0;--j,--k) //å¯¹é½
        {
            a[k]=a[j]-'0';
            a[j]=0;          //æ¶é¤å¹²æ°æ¯è¾çå ç´ ,ç½®é¶æä½ 
        } 
        for(int j=last2,k=M;j>=0;--j,--k)
        {   
            b[k]=b[j]-'0';
            b[j]=0; 
        } 
        int l=find1(i-1,a); 
        int r=find2(i-1,b); 
        printf("%d\n",r-l-1);
        memset(a,0,sizeof(a));  //æ¸é¤ä¸ä¸æ¬¡æä½çæ°æ®éç 
        memset(b,0,sizeof(b)); 
    } 
    return 0;
}