#include<stdio.h>
#include<string.h>
int main()
{
    char str[201];
    int i,x,y,dir,t;
    while(~scanf("%s",str))
    {
        x=310,y=420,dir=1,t;
        puts("300 420 moveto");
        puts("310 420 lineto");
        for (i=0;i<strlen(str);i++)
        {
            t=str[i]>'A'?1:-1;
            switch(dir)
            {
                case 0:x-=t*10;break;
                case 1:y+=t*10;break;
                case 2:x+=t*10;break;
                case 3:y-=t*10;
            }
            dir=(dir-t)%4;
            dir=dir>=0?dir:dir+4;
            printf("%d %d lineto\n",x,y);
        }
        puts("stroke\nshowpage");
    }
    return 0;
}