/*
  SER 2008.  Problem C: Lawrence of Arabia
  Author: Ryan Stansifer
*/

#include <cstdio>

#define NDEBUG
#include <cassert>

int main (void) {
   int ds, i, j, k, x;
   int n, m;
      
   input: for (ds=1; /**/; ds++) {
      scanf ("%d", &n);   
      if (n==0) break;
      assert (1<=n && n<=500);
      scanf ("%d", &m);   
      assert (0<=m && m<n);

      int depot[n]; // strategic value associated with each depot
      for (i=0; i<n; i++) scanf ("%d", &depot[i]);

      /*
        We want to pre-compute the stragetic value of the portion of the
        railroad from depot i to depot j.
      */

      /*
        First compute all partial sums for 0<=i<=n:
           partial[i] = sum {depot[k] | k<-[0..i-1]}
        So partial[j]-partial[i] = sum{depot[k] | k<-[i..j-1]}
        And sum {depot[k] | k<-[i..j]} = partial[j+1]-partial[i]
      */
      int partial[n+1];
      partial[0]=0;
      for (i=0; i<n; i++) {
         partial[i+1]=partial[i]+depot[i];
      }

      /*
        Now compute the stragetic value of railroad from depot i to depot j.
      */
      int value[n][n];
      for (i=0; i<n; i++) {
         value[i][i] = 0;
         for (j=i+1; j<n; j++) value[i][j] = value[i][j-1] + depot[j]*(partial[j]-partial[i]);
      }
      
         /*
           Compute remain_k[j], 0<=j<n, the minimum strategic value remaining after
           k attacks on the portion of the railroad from depot 0 to depot j.
         */
         int remain[n];

         // For k=0 attacks: remain_k[j] = value[k][j] for 0<=j<n
         for (j=0; j<n; j++) remain[j] = value[0][j];

         for (k=1; k<=m; k++) {
            /*
              Compute remain_(k+1)[j] from remain_k[j[, 0<=j<n, the
              minimum strategic value remaining after an additional
              attack (the k+1 attack) on the portion of the railroad
              from depot 0 to depot j.
            */
            for (j=n-1; j>=0; j--) {
               /*
                 See if attacking between depot x and x+1 will result
                 in lower remaining strategic value.
               */
               for (x=k-1; x<j; x++) {
                  // x<j means remain[x] is the old, remain_(k-1)[x] value
                  // x<j means remain[j] is the new, remain_k[j] value
                  int s=remain[x]+value[x+1][j];
                  if (remain[j]>s) remain[j] = s;
               }
            }
         }

         printf ("%d\n", remain[n-1]);
      }
   return 0;
}