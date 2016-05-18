#include <stdio.h>
int main()
{
    int t,n,m,i,j,temp,bs1,ys1,bs2,ys2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n<=1)
            return 0;
        if(n==2)
            printf("1 1\n");
        else if(n==3)
            printf("7 7\n");
        else if(n==4)
            printf("4 11\n");
        else if(n==5)
            printf("2 71\n");
        else if(n==6)
            printf("6 111\n");
        else if(n==7)
            printf("8 711\n");
        else if(n==8)
            printf("10 1111\n");
        else if(n==9)
            printf("18 7111\n");
        else if(n==10)
            printf("22 11111\n");
        else if(n==11)
            printf("20 71111\n");
        else if(n==12)
            printf("28 111111\n");
        else if(n==13)
            printf("68 711111\n");
        else if(n==14)
            printf("88 1111111\n");
        else
        {
            bs1=(n-15)/7;   //最大数的周期数
            ys1=(n-14)%7;   //最大数的周期中第几个元素
            if(ys1==1)
                printf("108");
            else if(ys1==2)
                printf("188");
            else if(ys1==3)
                printf("200");
            else if(ys1==4)
                printf("208");
            else if(ys1==5)
                printf("288");
            else if(ys1==6)
                printf("688");
            else if(ys1==0)
                printf("888");
            if(bs1!=0)
            while(bs1--)     //每加一个周期数多一个8
                printf("8");
            bs2=(n-2)/2;    //最小数的周期数
            ys2=n%2;        //最小数的周期中第几个元素
            printf(" ");
            if(ys2==0)
                printf("1");
            else
                printf("7");
            while(bs2--)     //梅加一个周期数多一个1
                printf("1");
            printf("\n");
        }
    }
    return 0;
}