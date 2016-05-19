#include<iostream>
using namespace std;
int a[200005];
int l[200005];
int r[200005];
int main()
{
    int m;
    int i;
    int t;
    while(cin>>m&&m)
    {
        
        for(i=1;i<=m;i++)
            cin>>a[i];
        t=a[1];

        for(i=2;i<=m;i++)
            t=t^a[i];

        if(t)
        {
            int temp;
            printf("Yes\n");

            l[1]=0;
            l[2]=a[1];
            for(i=3;i<=m+1;i++)
                l[i]=l[i-1]^a[i-1];

            r[m]=0;
            r[m-1]=a[m];

            for(i=m-2;i>=0;i--)
                r[i]=r[i+1]^a[i+1];

            for(i=1;i<=m;i++)
            {
                int k=a[i];
                if(i==1)
                    temp=r[1];
                else if(i==m)
                    temp=l[m];
                else
                {
                    temp=l[i]^r[i];
                }

                if(k>temp)
                    printf("%d %d\n",k,temp);
            }



        

        }
        else
            printf("No\n");

    }
    return 0;
}