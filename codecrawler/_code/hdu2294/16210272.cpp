#include<cstdio>
#include<string.h>
using namespace std;
int cas,n,k;
const int MOD=1234567891;
typedef long long LL;
struct mat{
    int a[31][31];
    mat(int type){
        memset(a,0,sizeof a);    
        if(type==1){
            for(int i=0;i<=k;i++){
                a[i][i]=i;
                if(i>0)a[i][i-1]=k-i+1;
            }    
        }
    }
    mat mult(mat b){//ç©éµå æ³
        mat c(0);
        for(int i=0;i<=k;i++)
            for(int j=0;j<=k;j++)
                for(int l=0;l<=k;l++)
                    c.a[i][j]=((LL)c.a[i][j]+(LL)a[i][l]*(LL)b.a[l][j])%MOD;
        return c;            
    }
    mat add(mat b){//ç©éµä¹æ³
        mat c(0);
        for(int i=0;i<=k;i++)
            for(int j=0;j<=k;j++)    
                c.a[i][j]=((LL)a[i][j]+(LL)b.a[i][j])%MOD;
        return c;
    }
};
//äºåè®¡ç®A^k
mat binMat(int k){
    if(k<=1)return mat(k);
    mat m=binMat(k/2);
    m=m.mult(m);
    if(k&1)m=m.mult(mat(1));
    return m;
}
//äºåè®¡ç®A^l+...A^r
mat cal(int l,int r){
    if(l==r)return binMat(l);
    int m=(l+r+1)/2;    
    mat t=cal(l,m-1);//ç®åä¸åçå
    mat t2=binMat(m-l);//ä¸­ä»çç©éµ
    t=t.add(t2.mult(t));
    if((r-l+1)&1)t=t.add(binMat(r));//å¦ææ¯å¥æ°ï¼åå ä¸æåä¸ä¸ª
    return t;
}

int main(){
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&n,&k);        
        printf("%d\n",cal(k,n).a[k][0]);
        
        
    }
    return 0;    
}
