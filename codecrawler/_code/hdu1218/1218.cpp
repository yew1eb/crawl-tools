#include <cstdio>
#include <cstring>
int main()
{
    int r, c;
    char image[10][10], str[10];
    while(scanf("%s", str) && strcmp(str, "ENDOFINPUT"))
    {
        scanf("%d%d", &r, &c);
        int r1 = r-1, c1 = c-1;
        for(int i=0; i<r; i++)
            scanf("%s", image[i]);
        for(int i=0; i<r1; i++)
            for(int j=0; j<c1; j++)
                image[i][j] = (image[i][j]+image[i+1][j]+image[i][j+1]+image[i+1][j+1])/4;
        for(int i=0; i<r1; i++)
            image[i][c1] = 0;
        for(int i=0; i<r1; i++)
            printf("%s\n", image[i]);
        scanf("%s", str);//读取最后一个'END'
    }
    return 0;
}