package com.njupt.acm;

import java.math.BigInteger;
import java.util.Scanner;

public class HDU_1134 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		BigInteger one = new BigInteger("1");
		BigInteger two = new BigInteger("2");
		BigInteger four = new BigInteger("4");

		while(scanner.hasNextInt()){
			int n = scanner.nextInt();
			BigInteger catalan = one;
			BigInteger N;
			if(n == -1){
				break;
			}
			if( n == 1 ){
				System.out.println("1");
				continue;
			}

			for(int i = 1 ; i <= n ; ++i){
				N = new BigInteger(String.valueOf(i));
				catalan = catalan.multiply(four.multiply(N).subtract(two)).divide(N.add(one));
			}

			System.out.println(catalan);
		}
	}
}