#include<iostream>
using namespace std;

int a2,a3,a5,a7;  //è®°å½è´¨å æ°ä¸ªæ° 

void divide(__int64 n)  //æåºæ¯ä¸ªè´¨å æ°çä¸ªæ° 
{
     a2=a3=a5=a7=0;
         
     while(n!=1)
     {
         if(n%2==0)
         {
             a2++;
             n/=2;
         }
         if(n%3==0)
         {
             a3++;
             n/=3;
         }
         if(n%5==0)
         {
             a5++;
             n/=5;
         }
         if(n%7==0)
         {
             a7++;
             n/=7;
         }
     }  
}   

void count()    //æ´åæä¸¾æ¯ç§ç»å 
{
     int cou=0;
     for(int i=0;i<=a2;i++)
     {
          for(int j=0;j<=a3;j++)
          {
                  for(int k=0;k<=a5;k++)
                  {
                          for(int p=0;p<=a7;p++)
                          {
                                  cou++;
                          }
                  }
          }
     }
     
     cout<<cou<<endl;
}
                                     
int main()
{
    __int64 n;
    
    while(cin>>n,n)
    {
        divide(n);
        
        count();
    }
    
    return 0;
}