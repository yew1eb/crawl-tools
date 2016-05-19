import java.math.BigInteger;
import java.util.Scanner;


public class Main 
{
	static Scanner cin=new Scanner(System.in);
	public static void main(String[] args)
	{
		int n,t;
		BigInteger c,sum,x,two=BigInteger.valueOf(2),four,eight;
		four=BigInteger.valueOf(4);
		eight=BigInteger.valueOf(8);
		while(cin.hasNext())
		{
			n=cin.nextInt();
			c=cin.nextBigInteger();
			sum=BigInteger.ZERO;
			if(n%2==0)//偶数
			{
				x=c.pow(n*n);
				sum=sum.add(x);
				x=two.multiply(c.pow(n*n/4));
				sum=sum.add(x);
				x=c.pow(n*n/2);
				sum=sum.add(x);
				x=two.multiply(c.pow((n*n-n)/2+n));
				sum=sum.add(x);
				x=two.multiply(c.pow(n*n/2));
				sum=sum.add(x);
				sum=sum.divide(eight);
			}
			else
			{
				x=c.pow(n*n);
				sum=sum.add(x);
				x=two.multiply(c.pow((n*n-1)/4+1));
				sum=sum.add(x);
				x=c.pow((n*n-1)/2+1);
				sum=sum.add(x);
				x=four.multiply(c.pow((n*n+n)/2));
				sum=sum.add(x);
				sum=sum.divide(eight);
			}
			System.out.println(sum);
		}

	}

}