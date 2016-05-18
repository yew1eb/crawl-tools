#include"stdio.h"
int main()
{
    int score;
    while(scanf("%d",&score)!=EOF)
    {
        if(score<80 && score>=70)         printf("C\n");  //顺序不同可以提高效率
        else if(score<70 && score>=60)  printf("D\n");
        else if(score<90 && score>=80)  printf("B\n");
        else if(score>=90 && score<=100)printf("A\n");
        else if(score>=0 && score<60)    printf("E\n");
        else printf("Score is error!\n");
    }
    return 0;
}