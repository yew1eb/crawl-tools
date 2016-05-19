import java.math.BigInteger;   
import java.util.Scanner;   

public class Main {   
  
    public static void main(String[] args) {   
        Scanner cin = new Scanner((System.in));   
        int  n;
        BigInteger[] f = new BigInteger[10000];
        f[1] = BigInteger.ONE;
        f[2] = BigInteger.ONE;
        f[3] = BigInteger.ONE;
        f[4] = BigInteger.ONE;
        for(int i=5; i<f.length;i++) 
            f[i] = f[i-1].add(f[i-2].add(f[i-3].add(f[i-4])));
        while(cin.hasNext()){
            n = cin.nextInt();
            System.out.println(f[n]);
        }
    }   
}   