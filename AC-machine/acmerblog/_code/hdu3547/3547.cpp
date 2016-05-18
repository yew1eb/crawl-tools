import java.util.*;
import java.math.BigInteger;
public class Main {
	/*
	public static BigInteger pow(int x){
		BigInteger a;
		a=a.pow(12)
	}*/
	public static void main(String[] args){
		int numcase;
		Scanner cin = new Scanner(System.in);
		numcase = cin.nextInt();
		for(int i = 1;i <= numcase;++i){
			BigInteger color,pow8,pow4,pow2;
			color = cin.nextBigInteger();
			pow8 = color.pow(8);
			//System.out.println(pow8);
			pow4 = color.pow(4);
			BigInteger x = new BigInteger("17");
			pow4 = pow4.multiply(x);
			BigInteger y = new BigInteger("6");
			pow2 = color.pow(2);
			pow2 = pow2.multiply(y);
			BigInteger sum = new BigInteger("0");
			sum = sum.add(pow8);
			sum = sum.add(pow4);
			sum = sum.add(pow2);
			BigInteger z = new BigInteger("24");
			sum = sum.divide(z);
		//	System.out.println("sum = "+sum);
			BigInteger p = new BigInteger("10");
			p = p.pow(15);
			System.out.print("Case "+i+": ");
			if(sum.compareTo(p) < 0){
				System.out.println(sum);
			}
			else{
				BigInteger q = sum.mod(p);
				String ss = q.toString();
				int len = ss.length();
				if(len < 15){
					int xx = 15 - len;
					for(int j = 0; j < xx; ++j)
						System.out.print(0);
				}
				System.out.println(q);
			}
		}
	}
}