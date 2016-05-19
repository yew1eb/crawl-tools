#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;
int arr[1024][3]={{0}};

int cmp(const void *a, const void *b){
    return ((int *)a)[1]-((int *)b)[1];
}

int main(){
    int k;
    int money,kinds;
    scanf("%d", &k);
    while(k--){
        scanf("%d %d", &money, &kinds);
        for(int i=1; i<=kinds; i++)
            scanf("%d %d", &arr[i][1], &arr[i][2]);

        qsort(arr+1, kinds, sizeof(int)*3, cmp);

        int m = money;
        double sum = 0;
        for(int i=1; i<=kinds; i++){
            if( m>0 ){
                int d = arr[i][1], w = arr[i][2];
                while( w!=0 && m>0){
                    if( m>d){
                        w--;
                        sum += 1;
                        m   -= d;
                    }else{
                        sum += ( m*1.0/d ) ;
                        m    = 0;
                    }
                }
            }else{
                break;
            }
        }
        printf("%.2lf\n", sum);
    }
    return 0;
}
