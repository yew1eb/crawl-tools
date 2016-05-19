#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <deque>
#include <set>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <map>
typedef long long LL;
const int INF = 1<<10;
const LL mod = 95041567; 

//æå°è¡¨ç¤ºæ³
int len;
int get_mstring(char *s)
{
    int len=strlen(s);
    int i=0,j=1,k=0;
    while(i<len&&j<len&&k<len)
    {
        int t=s[(i+k)%len]-s[(j+k)%len];
        if(t==0)
            k++;
        else
        {
            if(t>0)
                j+=k+1;
            else i+=k+1;
            if(i==j) j++;
            k=0;
        }
    }
    return min(i,j);
}
char s[21000],revs[21000];
char now1[21000],now2[21000];




//KMP
#define N 20010   //å­é¾é¿åº¦
#define M 40010 //æ¯é¾é¿åº¦
char a[M], b[N];
int Next[N];



void getNext(char s[], int len)
{
    int i, j;
    i = 0; j = -1;
    Next[0] = -1;
    while (i < len)
    {
        if (j == -1 || s[i] == s[j])
            ++i, ++j, Next[i] = j;
        else
            j = Next[j];
    }
} 
 
int ans;
int KMP(const char a[], const char b[], int pos, int next[], int la, int lb) 
{
    int i, j;
    i = pos, j = 0;
    next[0] = -1; 
    while (i < la)
    {
        if (j == -1 || a[i] == b[j])
            ++i, ++j;
        else
            j = next[j];
        if (j >= lb) 
        {
            if(i<2*len)  //è¿è¾¹ä¸è½ æ -1
            {
                ans=min(ans,    len-(  i+1-len) +1); 
            } 
            j=next[j]; //å¦æä¸è½å­é¾éå è¿è¾¹è¦æ¹æj=0;
        }
    }
    return ans;
} 
 

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&len);
        scanf("%s",s);


        for(int i=0;i<len;i++)
            revs[i]=s[len-1-i];
        revs[len]=0;


    //    cout<<"fan"<<revs<<endl;
        int l0=get_mstring(s);//ä¸æ 
        for(int i=0;i<len;i++)
            now1[i]=s[(i+l0)%len];
        now1[len]=0;


        //cout<<"zheng zuixiao   "<<l0<<endl;
        
         
        for(int i=0;i<len;i++)
            a[i]=a[len+i]=revs[i];
        a[2*len]=0;

        int l2=get_mstring(revs);
        for(int i=0;i<len;i++)
            now2[i]=revs[(i+l2)%len];
        now2[len]=0;  
        


        l0++;
        l2=ans=len-(l2+1)+1;

        int dx=strcmp(now1,now2);
        if(dx<0)
        {
            getNext(now2,len); 
            KMP(a, now2, 0, Next, 2*len, len); 
             
            printf("%d 1\n",ans); 

        }
        else if(dx>0)
        {
            printf("%d 0\n",l0);
        }
        else //liang zhe xiangtong  kan xia biaol   yong kmp  chuli chu a de xiabiao
        {
            getNext(now2,len); 
            KMP(a, now2, 0, Next, 2*len, len); 

            if(ans<l0)
                printf("%d 1\n",ans);
            else
                printf("%d 0\n",l0); 
        }  
    }
    return 0;
}
/*
44
4
abcd
5
aabbaa

7
abcdcba

1
a

2
aa

*/
