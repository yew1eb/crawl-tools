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
        BigInteger f[]= new  BigInteger[1005];
        f[1] = BigInteger.ZERO;
        f[2] =f[3]= BigInteger.ONE;
        int i;
        for(i=4; i<=1000; i++) {
            f[i] = f[i-1].add(f[i-1]);
            if(i%2==1)
                f[i]=f[i].subtract(BigInteger.ONE);
            else 
                f[i]=f[i].add(BigInteger.ONE);
        }
        while(cin.hasNext()){
            System.out.println(f[cin.nextInt()]);
        }
                
        
    }

}
