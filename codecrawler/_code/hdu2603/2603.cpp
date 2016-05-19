# include <stdio.h>
 # include <math.h>
 
 
 double pi = acos(-1.0), g = 9.87 ;
 
 
 int main ()
 {
     double v, m, a, vx, t, t1, t2 ;
     while (~scanf ("%lf%lf%lf", &v, &m, &a))
     {
         a = a/180*pi ;
         vx = v*cos(a), v = v*sin(a) ;
         if (v <= sqrt(g)) //will not touch the ceiling
             t = (v+sqrt(v*v+6*g))/g ;
         else
         {
             t1 = 2*(v-sqrt(v*v-g))/g ;
             t2 = (sqrt(v*v+6*g)-v) / g ;
             t = t1 + t2 ;
         }
         printf ("%.3lf\n", vx * t) ;
     }
     return 0 ;
 }