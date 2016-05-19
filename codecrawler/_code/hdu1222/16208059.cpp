#include <stdio.h>
int Ecluid(int a,int b){
    if(a%b == 0){
        return b;
    }else{
        Ecluid(b,a%b);
    }
}

int main(int argc, char *argv[])
{
    //FILE *fp;    
    //fp = freopen("in.txt","r",stdin);
    int test_case,m,n;
    scanf("%d",&test_case);
    while(test_case --){ 
        scanf("%d%d",&m,&n);
        if(Ecluid(m,n)==1){
               printf("NO\n");                  
        }else{
            printf("YES\n");
        }
    }  
    return 0;
}