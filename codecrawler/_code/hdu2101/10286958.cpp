#include <stdio.h>
main() { int a, b; while(~scanf("%d%d",&a,&b) ) { if( (a+b) % 86 == 0) printf("yes\n");
else printf("no\n"); }
}