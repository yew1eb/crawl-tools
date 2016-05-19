import java.util.*;
import java.math.*;
import java.lang.*;

public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner cin = new Scanner(System.in);
        BigDecimal a, b;
        while(cin.hasNext()){
            a = cin.nextBigDecimal();
            b = cin.nextBigDecimal();
            a = a.stripTrailingZeros();
            b = b.stripTrailingZeros();
            if(a.equals(b)) System.out.println("YES");
            else System.out.println("NO");
        }

        
    }

}
