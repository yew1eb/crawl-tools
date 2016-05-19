#include <cstdio>
using namespace std;
int st[5][5]={
    {0,0,0,0,0},
    {0,0,1,0,0},
    {0,0,0,1,0},
    {0,0,0,0,1},
    {0,1,1,0,1},    
};
struct jz{
    int a[5][5];    
    //ä¸¤ç§æé æ¹æ³,ä¸ç§æ¸0,ä¸ç§æ¯ç¸ä¹çç©éµ 
    jz(int k){
        if(k==0)for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)a[i][j]=0;
        if(k==1)for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)a[i][j]=st[i][j];    
    }
    //ç©éµç¸ä¹,ä¹æ³è¿ç¨ä¸­æ¨¡m 
    jz mult(jz jz2,int m){
        jz ans(0);
        for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        for(int k=1;k<=4;k++)
            ans.a[i][j]=(ans.a[i][j]+a[i][k]*jz2.a[k][j])%m;    
        return ans;
    }
    //å¾å°ç»æ 
    int getr(){
        return a[4][1]*2+a[4][2]*4+a[4][3]*6+a[4][4]*9;
    }
};
jz dfs(int k,int m){
    if(k==1)return jz(1);
    //äºå 
    jz rs=dfs(k/2,m);
    jz ans=rs.mult(rs,m);
    //å¤çä¸ºå¥æ°çæåµ 
    if(k%2==1){
        jz t2=jz(1);
        jz tmp=ans.mult(t2,m);    
        ans=tmp;
    }
    return ans;
} 

int main(){
    int l,k;
    int a[5]={1,2,4,6,9};
    while(scanf("%d%d",&l,&k)!=EOF){
        if(l<=4)printf("%d\n",a[l]%k);
        else{
            jz ans=dfs(l-4,k);
            printf("%d\n",ans.getr()%k);    
        }    
    }    
}
