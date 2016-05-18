#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
typedef double Matrix[105][105];

int mht(int i,int j,int m,int n){
    return abs(i-m)+abs(j-n);    
}

void gauss(Matrix A ,int n){
    int i,j,k,r;
    
    for(i = 0; i < n; i++){
        r = i;
        for(j = i+1; j < n; j++){
            if( fabs(A[j][i]) > fabs(A[r][i]) )  r = j;
        }
        if(r != i) for(j = 0; j <= n; j++) swap(A[r][j],A[i][j]); 
        
        
        for(k = i+1; k < n; k++){
            double f = A[k][i] / A[i][i];
            for(j = i; j <= n; j++)  A[k][j] -= f * A[i][j];
        }
        
        /*
        for(j = n; j >= i; j--){
            for(k = i+1; k < n; ++k)
                A[k][j] -= A[k][i]/A[i][i] * A[i][j];
        }
        */
    }
    for(i = n-1; i >= 0; --i ){
        for(j = i+1; j < n; ++j)
            A[i][n] -= A[j][n] * A[i][j];
        A[i][n] /= A[i][i];
    }
    
}

int main(){

//    freopen("in.txt","r",stdin); 

 //   freopen("out.txt","w",stdout); 
    Matrix g;
    double map[12][12];
    int pos[120][120];
    int r,c,d;
    bool is_first=true;
    while(scanf("%d%d%d",&c,&r,&d),r||c||d){
        if(!is_first)
            printf("\n");
        is_first=false;
        int i,j;
        int cnt=0;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                pos[i][j]=cnt++;
                scanf("%lf",&map[i][j]);
            }
        }
        memset(g,0,sizeof(g));
        int m,n;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                for(m=0;m<r;m++){
                    for(n=0;n<c;n++){
                        if( mht(i,j,m,n)<=d ){
                            g[ pos[i][j] ][ pos[m][n] ]=1;
                            g[ pos[i][j] ][cnt] += map[i][j];
                        }
                    }
                }
            }
        }
        

        gauss(g,cnt);
        
        for(i=0;i<cnt;i++){
            printf("%8.2lf",g[i][cnt]);
            if( (i+1)%c == 0 )
                putchar(10);
        }
    }
    return 0;
}