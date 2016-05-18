import java.util.Scanner;
public class Hd
{
	public static void main(String args[])
	{
		int m,n,a,b;
		Scanner reader=new Scanner(System.in);
                while(reader.hasNext()){
		m=reader.nextInt();
		n=reader.nextInt();
		System.out.println(zbs(m,n));
	}
}
	public static int zbs(int m,int n){
	 int t=0,r,a=m,b=n;
	 if(m<n){
	  t=m;
	  m=n;
	  n=t;
	 }
	 r=m%n;
         while(r!=0){
           m=n;
           n=r;
           r=m%n;

       }
       return a*b/n;
	}
}