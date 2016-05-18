import java.util.Scanner;
/**
 * @copyright www.acmerblog.com
 * @author coder
 *
 */
public class Hdu2198 {

	
	public static void findMinimumCuts(int arr[])
	{
		
		int size = arr.length;
		int lis[] = new int[size];
		int lds[] = new int[size];
		// Longest Increasing sequence
		   for(int i = 0; i < size; ++i)
		   {
		       for(int j = 0; j < i; ++j)
		       {
		           if(arr[j] < arr[i])
		           {
		               lis[i] = Math.max(lis[j] + 1, lis[i]);
		           }
		       }
		   }
		   
		   // Longest decreasing sequence
		   for(int i = size - 1; i >= 0; --i)
		   {
		      for(int j = size - 1; j > i; --j)
		      {
		          if(arr[j] < arr[i])
		          {
		             lds[i] = Math.max(lds[j] + 1, lds[i]);
		          }
		      }
		   }
		   
		   int best = 0;
		   for(int i = 0; i < size; ++i)
		   {
		      best = Math.max(best, lds[i] + lis[i]);
		   }
		  // System.out.println("Best"+best);
		   //System.out.println("Number to be removed : " + (size - best - 1));
		System.out.println(size - best - 1);
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n;
		while(true){
			n = scan.nextInt();
			if(n == 0) break;
			int a[] = new int[n];
			for(int i=0; i<n; i++) a[i] = scan.nextInt();
			findMinimumCuts(a);
		}
//		int a[] = {1, 2, 1, 2, 3, 2, 1, 2, 1};
//		int b[] = {4,5,65,34,786,45678,987,543,2,6,98,580,4326,754,54,2,1,3,5,6,8,765,43,3,54};
//		findMinimumCuts(a);
//		findMinimumCuts(b);
	}

}