#include"stdio.h"
#include"string.h"
int main()
{
    int n;
    int sum;
    int a[30];
    int t,len;
    int i,j,k;
    int carry;
    int num[155];
    while(scanf("%d",&n)!=-1,n)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }

        memset(num,0,sizeof(num));
        num[0]=1;
        len=1;
        for(i=2;i<=sum;i++)
        {
            carry=0;
            for(j=0;j<len;j++)
            {
                num[j]*=i;
                num[j]+=carry;
                if(num[j]>=100000)
                {
                    carry=num[j]/100000;
                    num[j]%=100000;
                }
                else carry=0;
            }
            if(carry!=0)num[len]=carry;
            while(num[len]!=0)len++;
        }
        for(i=0;i<n;i++)
        {
            for(j=2;j<=a[i];j++)
            {
                t=0;
                carry=0;
                for(k=len-1;k>=0;k--)
                {
                    carry=t;
                    t=(num[k]+t*100000)%j;
                    num[k]=(num[k]+carry*100000)/j;
                }
                while(num[len-1]==0)len--;
            }
        }
        for(i=len;i>=0;i--)
            if(num[i]!=0)
            {
                printf("%d",num[i]);break;
            }
        for(i--;i>=0;i--)
        {
            printf("%05d",num[i]);
        }
        printf("\n");
    }
    return 0;
}