import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		BigInteger[] r = new BigInteger[300];
		BigInteger one = BigInteger.ONE, zero = BigInteger.ZERO;
		for (int i = 'A'; i <= 'J'; i++) {
        	r[i] = one;
        }
		Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
        	char s[] = cin.next().toCharArray();
        	if (s.length == 3)  {
    			r[s[0]] = r[s[2]];
    		} else {
    			if (s[1] == '+') {
    				r[s[0]] = r[s[0]].add(r[s[3]]);
    			} else r[s[0]] = r[s[0]].multiply(r[s[3]]);
    		}
        }
        for (int i = 'A'; i <= 'J'; i++) {
        	System.out.println(r[i]);
        }		
	}

}