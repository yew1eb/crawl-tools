#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define maxn 200050
struct node{
    int l,r,f;
}a[maxn];
int b1[2*maxn],b2[2*maxn],pos[2*maxn],caozuo[2*maxn];
int lowbit(int x){
    return x&(-x);
}

void update1(int pos,int num){
    while(pos<=2*maxn){
        b1[pos]+=num;pos+=lowbit(pos);
    }
}

int getsum1(int pos){
    int num=0;
    while(pos>0){
        num+=b1[pos];pos-=lowbit(pos);
    }
    return num;
}

void update2(int pos,int num){
    while(pos<=2*maxn){
        b2[pos]+=num;pos+=lowbit(pos);
    }
}

int getsum2(int pos){
    int num=0;
    while(pos>0){
        num+=b2[pos];pos-=lowbit(pos);
    }
    return num;
}

int main()
{
    int n,m,i,j,d,tot,s1,s2,t1,t2,num1=0,caozuo1;
    while(scanf("%d",&n)!=EOF)
    {
        tot=0;caozuo1=0;
        //memset(caozuo,0,sizeof(caozuo));
        //memset(pos,0,sizeof(pos));
        for(i=1;i<=n;i++){
            scanf("%d%d",&a[i].f,&d);
            if(a[i].f==0){
                caozuo1++;caozuo[caozuo1]=i;
                //caozuo++;a[i].idx=caozuo;
                a[i].l=d;a[i].r=d+caozuo1;
                tot++;pos[tot]=a[i].l;
                tot++;pos[tot]=a[i].r;
            }
            else if(a[i].f==1){
                d=caozuo[d];
                a[i].l=a[d].l;a[i].r=a[d].r;
            }
        }
        num1++;
        printf("Case #%d:\n",num1);
        memset(b1,0,sizeof(b1));
        memset(b2,0,sizeof(b2));
        sort(pos+1,pos+1+tot);
        m=1;
        for(i=2;i<=tot;i++){
            if(pos[i]!=pos[m]){
                m++;pos[m]=pos[i];
            }
        }
        for(i=1;i<=n;i++){
            if(a[i].f==0){
                t1=lower_bound(pos+1,pos+m+1,a[i].l)-pos;
                t2=lower_bound(pos+1,pos+m+1,a[i].r)-pos;
                s1=getsum1(t2)-getsum1(t1-1);
                s2=getsum2(t2);
                printf("%d\n",s1-s2);
                update1(t1,1);
                update2(t1,1);
                update2(t2,-1);
            }
            else if(a[i].f==1){
                t1=lower_bound(pos+1,pos+m+1,a[i].l)-pos;
                t2=lower_bound(pos+1,pos+m+1,a[i].r)-pos;
                update1(t1,-1);
                update2(t1,-1);
                update2(t2,1);
            }
        }    
    }
    return 0;
}
/*
5
0 3
0 4
0 1
0 4
0 -1
*/