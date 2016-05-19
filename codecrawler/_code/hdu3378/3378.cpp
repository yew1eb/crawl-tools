#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;
int n ;
typedef struct L{
    char js[5] ;
    int al ;
    int esc ;
    int sc ;
}L ;
L kk[101] ;
int pk ;
int bjnj,wnj ;
int ok()
{
    int f=0 ;
    int cntfz=0 ;
    int cntnj=0 ;
    int cntzc=0 ;
    for(int i=0 ;i<n ;i++)
    {
        if(!strcmp(kk[i].js,"ZG"))
        {
            if(kk[i].al)
                f=1 ;
        }
        if(!strcmp(kk[i].js,"FZ"))
        {
            if(kk[i].al)
                cntfz++ ;
        }
        if(!strcmp(kk[i].js,"NJ"))
        {
            if(kk[i].al)
            {
                bjnj=i ;
                cntnj++ ;
            }
        }
        if(!strcmp(kk[i].js,"ZC"))
        {
            if(kk[i].al)
                cntzc++ ;
        }
    }
    if(!(cntzc+cntfz) && cntnj==1 && f)
    {
        pk=1 ;
        wnj=bjnj ;
    }
    if(!(cntfz+cntnj))
    {
        if(pk)
        {
            kk[wnj].sc=n ;
        }
        for(int i=0 ;i<n ;i++)
        {
            if(!strcmp(kk[i].js,"ZG"))
                kk[i].sc=4+cntzc*2+kk[i].esc ;
            if(!strcmp(kk[i].js,"ZC"))
                kk[i].sc=5+cntzc+kk[i].esc ;
        }
        return 1 ;
    }
    if(!f)
    {
        if(cntnj==1 && cntfz==0 && cntzc==0)
        {
            for(int i=0 ;i<n ;i++)
            if(!strcmp(kk[i].js,"ZG"))
                kk[i].sc=1 ;
            kk[wnj].sc=4+n*2 ;
            return 1 ;
        }
        for(int i=0 ;i<n ;i++)
        {
            if(!strcmp(kk[i].js,"NJ"))
                if(kk[i].al)
                    kk[i].sc=1 ;
            if(!strcmp(kk[i].js,"FZ"))
                kk[i].sc=cntfz*3+kk[i].esc ;
        }
        return 1 ;
    }
    return 0 ;
}
int main()
{
    int t ;
    scanf("%d",&t) ;
    while(t--)
    {
        int m ;
        scanf("%d%d",&n,&m) ;
        for(int i=0 ;i<n ;i++)
        {
            scanf("%s",kk[i].js) ;
            kk[i].al=1 ;
            kk[i].esc=0 ;
            kk[i].sc=0 ;
        }
        pk=0 ;
        for(int i=0 ;i<m ;i++)
        {
            int a,b ;
            scanf("%d%d",&a,&b) ;
            if(ok())
                continue ;
            kk[b].al=0 ;
            if(!strcmp(kk[a].js,"FZ") && (!strcmp(kk[b].js,"ZG")))
            {
                kk[a].esc+=2 ;
            }
            if(!strcmp(kk[a].js,"FZ") && (!strcmp(kk[b].js,"ZC")))
            {
                kk[a].esc++ ;
            }
            if(!strcmp(kk[a].js,"FZ") && (!strcmp(kk[b].js,"NJ")))
            {
                kk[a].esc++ ;
            }
            if(!strcmp(kk[a].js,"ZG") && (!strcmp(kk[b].js,"FZ")))
            {
                kk[a].esc++ ;
            }
            if(!strcmp(kk[a].js,"ZG") && (!strcmp(kk[b].js,"NJ")))
            {
                kk[a].esc++ ;    
            }
            if(!strcmp(kk[a].js,"ZC") && (!strcmp(kk[b].js,"FZ")))
            {
                kk[a].esc++ ;    
            }
            if(!strcmp(kk[a].js,"ZC") && (!strcmp(kk[b].js,"NJ")))
            {
                kk[a].esc++ ;    
            }
        }
        ok() ;
        for(int i=0 ;i<n ;i++)
        {
            if(!i)
                printf("%d",kk[i].sc) ;
            else
                printf(" %d",kk[i].sc) ;
        }
        putchar('\n') ;
    }
    return 0 ;
}