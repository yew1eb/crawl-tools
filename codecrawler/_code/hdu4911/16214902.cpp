#include<iostream>
#include<string.h>
using namespace std;
#define MAX 100010
int aux[MAX];
int a[MAX];
int n;
long long k;
long long ans=0;
void merge(int a[],int l,int mid,int h){
    int i=l;
    int j=mid+1;
    for(int k=l;k<=h;++k){
        aux[k]=a[k];
    }
    for(int k=l;k<=h;k++){
        if(i>mid)a[k]=aux[j++];
        else if(j>h)a[k]=aux[i++];
        else if(aux[i]<=aux[j])a[k]=aux[i++];
        else
        {
            a[k]=aux[j++];
            ans+=(mid-i+1);
        }
    }
}
void mergesort(int a[],int l,int h){
    if(h<=l)return ;
    int mid=l+(h-l)/2;
    mergesort(a,l,mid);
    mergesort(a,mid+1,h);
    merge(a,l,mid,h);
}
int main(int argc, char *argv[])
{
    //freopen("4911.in","r",stdin);
    while(scanf("%d %lld",&n,&k)!=EOF){
        ans=0;
        memset(aux,0,sizeof(aux));
        for(int k=0;k<n;++k)
            scanf("%d",&a[k]);
        mergesort(a,0,n-1);
        if(k<ans)printf("%lld\n",ans-k);
        else
            printf("0\n");
    }
    return 0;
}
