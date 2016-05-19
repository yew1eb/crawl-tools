#include <iostream>

using namespace std;

int main()
{
    int n,a[100],cas=1;
    while((cin>>n)&&n)
    {
        int sum=0,d,cur=0;
        for(int i=0;i<n;i++)
           {
               cin>>a[i];
               sum+=a[i];
           }
        d=sum/n;
        for(int i=0;i<n;i++)
            if(a[i]>d)
            cur+=a[i]-d;
        cout<<"Set #"<<cas++<<endl<<"The minimum number of moves is "<<cur<<"."<<endl<<endl;
    }
    return 0;
}