package com.njupt.bigInteger;

import java.math.BigInteger;
import java.util.Scanner;

public class HDU_1212_1 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		BigInteger a,b,c;
		
		while(scanner.hasNextBigInteger()){
			a = scanner.nextBigInteger();
			b = scanner.nextBigInteger();
			c = a.mod(b);//返回a%b的结果,赋给c
			
			System.out.println(c);
		}
	}
}