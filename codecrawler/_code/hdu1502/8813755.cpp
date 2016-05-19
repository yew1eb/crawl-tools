import java.math.*;
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger dp[][][] = new BigInteger[65][65][65];
        int i, j, k, n;
        dp[0][0][0] = dp[1][0][0] = dp[1][1][0] = BigInteger.ONE;
        dp[0][1][0] = dp[0][0][1] = dp[0][1][1] = dp[1][0][1] = BigInteger.ZERO;
        for(i=1; i<=60; i++)
        for(j=0; j<=i; j++)
        for(k=0; k<=j; k++){
            BigInteger  rec = BigInteger.ZERO;
            if(i>=j&&j>=k){
                if(i>j)  rec = rec.add(dp[i-1][j][k]);
                if(j>k)  rec = rec.add(dp[i][j-1][k]);
                if(k>0)  rec = rec.add(dp[i][j][k-1]);
            }
            dp[i][j][k]= rec; 
        }
        while(cin.hasNext()){
            n = cin.nextInt();
            System.out.println(dp[n][n][n]);
            System.out.println();
        }
    }
}
