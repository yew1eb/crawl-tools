#include<stdio.h>
int main()
{
    int year,mouth,day,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&year,&mouth,&day);
        if((mouth+day)%2==0 || (day == 30 &&(mouth == 11 || mouth == 9)))
            puts("YES");
        else puts("NO");
    }
    return 0;
}