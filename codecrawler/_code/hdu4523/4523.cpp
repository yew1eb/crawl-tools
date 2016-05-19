import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		while(input.hasNext()){
			BigInteger n=input.nextBigInteger();
			BigInteger m=input.nextBigInteger();
			BigInteger p=input.nextBigInteger();
			//m>=n&&m<=n+p||m>=3&&m<n
			if(m.compareTo(n)>-1&&m.compareTo(n.add(p))<1||m.compareTo(BigInteger.valueOf(3))>-1&&m.compareTo(n)<0&&p.compareTo(BigInteger.valueOf(1))>=0){
				System.out.println("YES");
			}
			else
				System.out.println("NO");
		}
	}
}
