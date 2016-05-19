#include <stdio.h>

int main()
{
    int M1,M2,R1,R2,R3, i;
    char s[205];
    while(~scanf("%d%d",&M1,&M2))
    {
        R1 = R2 = R3 = 0;
        scanf("%s",s);
        for(i=0;s[i]; i++)
        {
            if(s[i] =='A') R1= M1;
            if(s[i] =='B') R2=M2;
            if(s[i] =='C') M1 = R3;
            if(s[i] =='D') M2 = R3;
            if(s[i] =='E') R3 = R1 + R2;
            if(s[i] =='F') R3 = R1-R2;
        }
        printf("%d,%d\n",M1,M2);
    }
    return 0;
}
