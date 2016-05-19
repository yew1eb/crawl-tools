import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

        public static void main(String[] argv) throws IOException
        {
              Scanner in = new Scanner(new InputStreamReader(System.in));
              
              BigInteger[] ans = new BigInteger[105];
              
              ans[0] = ans[1] = new BigInteger("1");
              
              BigInteger cheng,chu;
              
              for(int i = 2 ; i < 105 ; i++)
              {
            	  cheng = new BigInteger(Integer.toString(4*i-2));
            	  chu = new BigInteger(Integer.toString(i+1));
            	  
            	  ans[i] = (ans[i-1].multiply(cheng)).divide(chu);
              }
              
             
              while(in.hasNext())
              {
            	  int n = in.nextInt();
            	  
            	  System.out.println(ans[n]);
              }

        }
}