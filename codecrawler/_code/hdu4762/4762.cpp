//package fuck;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static BigInteger gcd(BigInteger a,BigInteger b){
		if(!b.equals(BigInteger.ZERO)) return gcd(b,a.mod(b));
		return a;
	}
    public static void main(String args[]){  
        Scanner cin=new Scanner(System.in);  
        int t =  cin.nextInt();
        while(t>0){
        	int m = cin.nextInt();
        	int n = cin.nextInt();
        	BigInteger N = BigInteger.valueOf(n);
        	BigInteger M = BigInteger.valueOf(m).pow(n-1);
        	BigInteger tmp = gcd(N,M);
        	System.out.println(N.divide(tmp)+"/"+M.divide(tmp));
        	t--;
        }
    }  
}  
