#include<stdio.h>
#include<stdlib.h>
typedef struct S{
    int p;//æ­£ç¡®è§£é¢æ°
    int t;//ç¨æçæ¶é´
    int g;//åæ°
    int n;//è¾å¥çåå§ç¼å·
}S;
S s[110];
int cmp(const void *a,const void *b){
    if((*(S*)a).p==(*(S*)b).p)
        return (*(S*)a).t-(*(S*)b).t;
    return (*(S*)b).p-(*(S*)a).p;
}
int cmp2(const void *a,const void *b){
    return (*(S*)a).n-(*(S*)b).n;
}
int main(){
    int n,i;
    int sum[6],tol[6];
    int a,b,c,d;
    while(scanf("%d",&n)&&(n>0)){
        for(i=0;i<6;i++)tol[i]=sum[i]=0;
        for(i=0;i<n;i++){
            scanf("%d%d:%d:%d",&a,&b,&c,&d);
            s[i].p=a;
            s[i].n=i;
            s[i].t=b*3600+c*60+d;
            sum[a]++;
        }
        for(i=4;i>0;i--)
            tol[i]=tol[i+1]+sum[i+1];
        qsort(s,n,sizeof(s[0]),cmp);
        for(i=0;i<n;i++){
            s[i].g=s[i].p*10+50;
            if(s[i].p==0||s[i].p==5)continue;
            if(i-tol[s[i].p]<sum[s[i].p]/2)
                s[i].g+=5;
        }
        qsort(s,n,sizeof(s[0]),cmp2);
        for(i=0;i<n;i++)
            printf("%d\n",s[i].g);
        printf("\n");
    }
    return 0;
}
