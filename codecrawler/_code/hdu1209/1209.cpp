# include <stdio.h>
 # include <stdlib.h>
 
 
 typedef struct TIME{
     int hh, mm ;
     int ang ;
 } TIME ;
 
 
 
 int cmp(const void *a, const void *b)
 {
     TIME *p = (TIME*)a, *q = (TIME*)b ;
     if (p->ang != q->ang)
     return p->ang - q->ang ;
     
     if (p->hh != q->hh) return p->hh - q->hh ;
     return p->mm - q->mm ;
 }
 
 
 int abs(int x){return x<0?-x:x;}
 
 
 int main ()
 {
     int i, T ;
     TIME time[5] ;
     scanf ("%d", &T) ;
     while (T--)
     {
         for(i = 0 ; i < 5 ; i++)
         {
             scanf ("%d:%d", &time[i].hh, &time[i].mm) ;
             time[i].ang = abs((time[i].hh%12)*60+time[i].mm - time[i].mm*12) ;
             if (time[i].ang > 360) time[i].ang = 720 - time[i].ang ;
         }
         qsort(time, 5, sizeof(time[0]), cmp) ;
         printf ("%02d:%02d\n", time[2].hh, time[2].mm) ;
     }
     return 0 ;
 }