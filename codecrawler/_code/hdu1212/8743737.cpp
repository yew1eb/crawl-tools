import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger a, b;
        while(cin.hasNext()){
            a = cin.nextBigInteger();
            b = cin.nextBigInteger();
            System.out.println(a.mod(b));
        }
    }

}
