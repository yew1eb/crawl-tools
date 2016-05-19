#include<stdio.h>
#include<string.h>
#define SWAP(x,y) x^=y;y^=x;x^=y;
char m_str[100],n_str[100];
int m_base=0,n_base=0;//base number
//m base convert into the n base
int m_to_n(int mb,char *ms,int nb,char *ns)
{
    int len_m=strlen(ms),len_n=0;
    int tens=0,i=0,j=0;
    for(i=0;i<=len_m-1;i++) tens=ms[i]<='9' ? tens*mb+ms[i]-'0' :tens*mb+ms[i]-'A'+10 ;//convert to the 10 base, low string bit map to high number bit
    while(tens>0) {ns[len_n++]=tens%nb>=10 ? tens%nb-10+'A' : tens%nb+'0';tens/=nb;}
    i=0;j=len_n-1;n_str[len_n]='\0';
    while(i<j){SWAP(n_str[i],n_str[j]);i++;j--;}
    return(0);
}
int main()
{
    while(scanf("%s%d%d",m_str,&m_base,&n_base)!=EOF)
    {
        m_to_n(m_base,m_str,n_base,n_str);
        if(strlen(n_str)<=7) printf("%7s\n",n_str);
        else printf("%7s\n","ERROR");
    }
    return(0);
}
