#include <stdio.h>

int main()
{
    char input[1024], *p;
    int stu, flag;
    double gpa;
    while (scanf("%[^\n]%*c", input) != EOF)
    {
        stu = 0;
        gpa = 0.0;
        for (p = input, flag = 1; flag && *p != '\0'; ++p)
        {
            switch (*p)
            {
            case 'A': ++stu; gpa += 4; break;
            case 'B': ++stu; gpa += 3; break;
            case 'C': ++stu; gpa += 2; break;
            case 'D': ++stu; ++gpa; break;
            case 'F': ++stu; break;
            case ' ': break;
            default: flag = 0;
            }
        }
        if (flag)
            printf("%.2lf\n", gpa / stu);
        else
            printf("Unknown letter grade in input\n");
    }
    return 0;
}