package ttt;

import java.util.Scanner;

public class HDU_2099 {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner (System.in);
		
		while(scanner.hasNext()){
			int a = scanner.nextInt();
			int b = scanner.nextInt();
			
			
			if(a == 0 && b == 0){
				break;
			}
			
			
			a *= 100;
			int i;
			int sum = 0;
			for(i = 0 ; i < 100 ; ++i){
 				if((a+i) % b == 0){
					sum++;
					if(sum > 1){
						System.out.printf(" %02d",i);
					}else{
						System.out.printf("%02d",i);
					}
				}
				
				
			}
			
			
			System.out.println();
					
		}
	}
}