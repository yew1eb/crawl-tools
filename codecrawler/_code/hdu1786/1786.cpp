#include<iostream>
int N,M,W[10];
int cmp(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}
int f_min(int x,int y){
if(x==-1)return y;
return x<y?x:y;
}
void get_W(){
    int i;
    for(i=0;i<N;i++)
        scanf("%d",&W[i]);
    qsort(W,N,sizeof(int),cmp);
}
int ans(int bag,int s){
    int w=W[s],up;
    if(bag%w==0)return bag/w;
    if(s==N-1)return -1;
    up=bag/w;
    int lim=f_min(up,W[s+1]-1),i,min=-1,temp;
    for(i=0;i<=lim;i++){
        temp=ans(bag%w+i*w,s+1);
        if(temp==-1)continue;
        min=f_min(min,up-i+temp);
    }
    return min;
}
int main(){
    while(scanf("%d%d",&N,&M)&&(N||M)){
        get_W();
        printf("%d/n",3*ans(M,0));
    }
    return 0;
}