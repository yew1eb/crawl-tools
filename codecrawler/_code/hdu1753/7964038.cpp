import java.math.BigDecimal;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        BigDecimal a, b, c;
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext()){
            a = cin.nextBigDecimal();
            b = cin.nextBigDecimal();
            c = a.add(b);
            if(c.compareTo(BigDecimal.ZERO)== 0)
                System.out.println("0");
            else
                System.out.println(c.stripTrailingZeros().toPlainString());
        }
    }

}