import java.util.Scanner;
public class Main{	
	static int a[]=new int[21];
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int N=input.nextInt();
		while(N-->0){
			int n=input.nextInt();
			int a=n/2;
			int b=(n-a)*2/3;
			n=n-a-b;
			int sum=a/10+b/10+n/10;
			if(a%10!=0)
				sum++;
			if(b%10!=0)
				sum++;
			if(n%10!=0)
				sum++;
			System.out.println(sum);
		}
	}
}