#include <stdio.h>
#include <string.h>

long pows(int a,int b)
{
    int i;
    long sum = 1;
    for (i=0;i<b;i++)
    {
        sum=sum*a;
    }
    return sum;
}

int main()
{
    int D;
    char Num[50];
    int NumOfTest;
    char strings[50];
    int i,j,k,len,t,g;
    long sum;
    /*freopen("e://1.txt","r",stdin);*/
    while (scanf("%d",&NumOfTest)!=EOF)
    {
        sum = 0;
        for (i=0;i<NumOfTest;i++)
        {
            scanf("%s",strings);
            j=0;
            k=0;
            D = 0;
            while (strings[j]!='(')
            {
                Num[k] = strings[j];
                k++;
                j++;
            }
            Num[k] = '/0';
            j++;
            while (strings[j]!=')')
            {
                D = D*10+(strings[j]-'0');
                j++;
            }
            len =strlen(Num);
            k = len-1;
            for (j=0;j<len;j++)
            {
                g=Num[j]-'0';
                t = pows(D,k);
                sum+=(g*t);
                k--;
            }
        }
        printf("%ld/n",sum);
    }
    return 0;
}