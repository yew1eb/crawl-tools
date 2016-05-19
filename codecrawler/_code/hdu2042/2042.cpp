import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(new BufferedInputStream(System.in));
		int k=sc.nextInt();
		for(int i=1;i<=k;i++){
			BigInteger x=BigInteger.valueOf(3);
			int m=sc.nextInt();
			for(int j=1;j<=m;j++){
				 x=(x.subtract(BigInteger.valueOf(1)).multiply(BigInteger.valueOf(2)));
			}
			System.out.println(x);
		}
	}

}