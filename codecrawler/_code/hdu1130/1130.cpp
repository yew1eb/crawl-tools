package com.njupt.bigInteger;

import java.math.BigInteger;
import java.util.Scanner;

public class HDU_1130_1 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		BigInteger one = new BigInteger("1");
		//BigInteger one1 =BigInteger.ONE;等价于上面的那一种写法
		BigInteger two = new BigInteger("2");
		BigInteger four = new BigInteger("4");

		BigInteger N ;

		while(scanner.hasNextInt()){
			int n = scanner.nextInt();
			BigInteger catalan = one;
			for(int i = 1 ; i <= n ; ++i){
				N = new BigInteger(String.valueOf(i));
				catalan = catalan.multiply(four.multiply(N).subtract(two)).divide(N.add(one));

			}
			System.out.println(catalan);

		}
	}
}