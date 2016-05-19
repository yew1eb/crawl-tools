#include<stdio.h>
int sum(int a,int b)
{
    int num=0;
    while(a)
    {
        num+=a%b;
        a=a/b;
    }
    return num;
}
int main()
{
    int a,i,first=1;
    for(i=2992;i<10000;i++) if(sum(i,10)==sum(i,16)&&sum(i,16)==sum(i,12))   printf("%d\n",i);
    return 0;
}