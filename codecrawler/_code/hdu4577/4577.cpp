import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args) {
		BigInteger s,n,tmp;int k;
		int cas;
		Scanner cin = new Scanner(System.in);
		cas = cin.nextInt();
		while(cas>0){ cas--;
			n = cin.nextBigInteger();
			k = cin.nextInt();
			s = BigInteger.ZERO;
			int cc = 1;
			for(int i=1;i<k;i++){
				cc*=2;
			}
			while(1==1){
				n = n.divide(BigInteger.valueOf(cc));
				tmp = n.subtract(n.divide(BigInteger.valueOf(2)));
				if(tmp.equals(BigInteger.ZERO)) break;
				s = s.add(tmp);
				n = n.divide(BigInteger.valueOf(2));
			}
			System.out.println(s);
		}
	}
}
