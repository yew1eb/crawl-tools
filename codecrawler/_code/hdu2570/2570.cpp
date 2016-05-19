#include"iostream"
#include"algorithm"
using namespace std;
int main()
{
    int i,t;
    int n,v,w;
    double a[110];
    cin>>t;
    while(t--)
    {
        cin>>n>>v>>w;
        for(i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        double p=0.0;
        int k=0;
        
        for(i=0;i<n;i++)
        {
              if((p*i+a[i])/(i+1)<=w) //(sum*i*v+a[i]*v)/((i+1)*v)
              {
                  p=(p*i+a[i])/((i+1));
              }
              else break;
        }
        printf("%d %.2lf\n",i*v,p/100);
    }
    return 0;
}