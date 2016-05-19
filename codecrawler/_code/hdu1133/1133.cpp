import java.util.*;
import java.math.*;
public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner cin = new Scanner(System.in);
        BigInteger dp[][] = new BigInteger[109][109] ;
        
        int a,b;
        int T = 1;
        while(true){
            a = cin.nextInt();b=cin.nextInt();
            int ta =a,tb = b;
            if(a==0&&b==0) break;
            for(int i=0;i<109;i++)
                for(int j=0;j<109;j++) dp[i][j] = BigInteger.ZERO;
            System.out.println("Test #"+T+":");T++;
            if(a<b){
                System.out.println("0");
                continue;
            }
            dp[0][0] = BigInteger.ONE;
            for(int j=1;j<=a;j++)
                {dp[0][j] = dp[0][j-1].multiply(BigInteger.valueOf(ta));ta--;}
            for(int i=1;i<=b;i++){
                for(int j=i;j<=a;j++){
                    dp[i][j]=dp[i-1][j].multiply(BigInteger.valueOf(b+1-i));
                    dp[i][j]=dp[i][j].add(dp[i][j-1].multiply(BigInteger.valueOf(a+1-j)));
                }
            } 
            System.out.println(dp[b][a]);
        }
    }

}