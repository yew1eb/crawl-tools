#include <stdio.h>

#include <math.h>

void main() {

    unsigned int m,n,ai,aj,bi,bj,ak,bk;

    while (scanf("%d%d",&m,&n)!=EOF) {

        ai = sqrt(m-1)+1;

        bi = sqrt(n-1)+1;

        aj = (m-(ai-1)*(ai-1)-1)/2+1;

        bj = (n-(bi-1)*(bi-1)-1)/2+1;

        ak = (ai*ai-m)/2+1;

        bk = (bi*bi-n)/2+1;

        printf("%d/n",abs(ai-bi)+abs(aj-bj)+abs(ak-bk));

    }

}