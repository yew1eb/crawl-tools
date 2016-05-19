import java.io.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		while(cin.hasNextBigDecimal()){
			BigDecimal num = cin.nextBigDecimal();
			int n = cin.nextInt();
			num = num.pow(n);
			String r = num.stripTrailingZeros().toPlainString();    
			if(r.startsWith("0.")){
				r = r.substring(1);
			}
			System.out.println(r);
		}
	}
}