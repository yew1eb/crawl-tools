#include<stdio.h>
int main()
{
    int n,w,x,y;
    while(scanf("%d%d%d%d",&x,&y,&w,&n)>0)
    {
        int t= 0 , tt =0;
        n--;
        while(n>0)
        {
            tt += w ;
            if(tt<x)
            {
                t += w ; n--;
            }
            else if(tt==x)
            {
                t += w ; n--;
                if(n){
                    t += y ; n--; tt = 0;
                }
            }
            else {
                if(tt!=w)
                    t += x-tt+w +y , n-- , tt = 0;
                else t += x+y , n-- , tt = 0;
            }
        }
        printf("%d\n",t);
    }
}
