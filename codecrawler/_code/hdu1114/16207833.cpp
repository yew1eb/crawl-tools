#include<iostream>
using namespace std;

#define INF 0x7fffffff

int empty,full,n_case;
int record[10000];

struct node
{
    unsigned int value;
    int weight;
}a[500];

int main()
{
    int t_case,volume,i,j;

    cin>>t_case;

    while(t_case--)
    {
        cin>>empty>>full>>n_case;

        for(i=0;i<n_case;i++)
            cin>>a[i].value>>a[i].weight;

        volume=full-empty;
        record[0]=0;
        for(i=1;i<=volume;i++)
            record[i]=INF;
        for(i=0;i<n_case;i++)
        {
            for(j=a[i].weight;j<=volume;j++)
            {
                if(record[j-a[i].weight]+a[i].value <record[j])
                    record[j]=record[j-a[i].weight]+a[i].value;
            }
        }
        
        if(record[volume]<INF)
            cout<<"The minimum amount of money in the piggy-bank is "<<record[volume]<<"."<<endl;
        else
            cout<<"This is impossible."<<endl;
    }

    return 0;}