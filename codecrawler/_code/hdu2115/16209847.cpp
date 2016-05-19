#include<iostream>
#include<cstring>
using namespace std;
struct node
{
    char name[20];
    char time[20];
    int s;
} f[20];

int cmp(const void *a,const void *b)
{
    node *c=(node *)a;  node *d=(node *)b;

    if(strcmp(c->time,d->time)>0)
        return 1;
    if(strcmp(c->time,d->time)<0)
        return -1;


    if(strcmp(c->time,d->time)==0)

    return c->name >d->name?-1:1;
    
}

int main()
{
    int n;
    int i;
    int flag=0;
    int k;
    int t=1;
    while(cin>>n&&n)
    {

        if(flag)
            printf("\n");

        for(i=0;i<n;i++)
            cin>>f[i].name>>f[i].time;

        qsort(f,n,sizeof(f[0]),cmp);

        k=1;

        printf("Case #%d\n",t++);

        cout<<f[0].name<<" "<<k<<endl;
        f[0].s=1;

        k++;

        for(i=1;i<n;i++)
        {
            cout<<f[i].name<<" ";

            if(strcmp(f[i].time,f[i-1].time)==0)
            {
                printf("%d\n",f[i-1].s);
                f[i].s=f[i-1].s;
            }
            else
            {

            printf("%d\n",k);
            f[i].s=k;
            }

            k++;
        }
            flag=1;
    }
    return 0;
}