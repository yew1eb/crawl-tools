import java.util.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(new BufferedInputStream(System.in));
		int n=sc.nextInt();
		for(int i=0;i<n;i++){
			BigInteger a=sc.nextBigInteger();
			BigInteger b=sc.nextBigInteger();
			if(b.compareTo(BigInteger.ZERO)!=0){
			BigDecimal bd=BigDecimal.valueOf(a.mod(b).doubleValue());
			if(bd.compareTo(BigDecimal.ZERO)==0)
				System.out.println("YES");
			else
				System.out.println("NO");
				
		}
		}
	}

}