/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-09 20:59
 # Filename: ZOJ2229 POJ1922 HDU1445 Ride to School.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
//#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 10010
using namespace std;


int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

    int n;
    double speed,time;

    while(scanf("%d",&n)&&n)
    {
        double arrive_time=100000000.0;
        for(int i=0;i<n;++i)
        {
            scanf("%lf%lf",&speed,&time);
            if(time<0.0)
                continue;
            arrive_time=min(arrive_time,time+4.5/speed*3600);
        }
        printf("%d\n",static_cast<int>(ceil(arrive_time)));
    }

  return 0;
}
