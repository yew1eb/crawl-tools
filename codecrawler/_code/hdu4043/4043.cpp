import java.util.*;
import java.math.*;

public class Main{//这个是类
	public static void main(String args[]){//这个是主函数
		Scanner cin = new Scanner(System.in);
		BigInteger[] ans1 = new BigInteger[505];
		BigInteger[] ans2 = new BigInteger[505];
		BigInteger tmp;
		ans1[1] = BigInteger.ONE;
		ans2[1] = BigInteger.valueOf(2);
		for(int i = 2; i <= 500; i ++){
			ans1[i] = ans1[i - 1].multiply(BigInteger.valueOf(2 * i - 1));
			ans2[i] = ans2[i - 1].multiply(BigInteger.valueOf(2 * i));
			tmp = ans1[i].gcd(ans2[i]);
			ans1[i] = ans1[i].divide(tmp);
			ans2[i] = ans2[i].divide(tmp);
		}
		int t,n;
		t = cin.nextInt();
		for(int i = 0; i < t; i ++){
			n = cin.nextInt();
			System.out.print(ans1[n]);
			System.out.print('/');
			System.out.println(ans2[n]);
		}
	}
}