 import java.util.*;
 import java.io.*;
 import java.math.BigInteger;
 import java.util.Scanner;
 
 public class Main {
     static final int MAX = 1000;
     static BigInteger[] Ans = new BigInteger[MAX];
     public static void getAns()
     {
         boolean[] flag = new boolean[MAX];
         int primeNumber = 0;
         for(int i = 0; i < MAX; ++i)
             flag[i] = true;
         Ans[0] = BigInteger.ONE;
         for(int i = 2; i < MAX; ++i)
         {
             if(flag[i])
             {
                 ++primeNumber;
                 Ans[primeNumber] = Ans[primeNumber - 1].multiply(BigInteger.valueOf(i));;
                 for(int j = i + i; j < MAX; j += i)
                 {
                     flag[j] = false; 
                 }
             }
         }
     }
 
     public static BigInteger findAns(BigInteger n)
     {
         int left = 1, right = 100, mid;
         while(left + 1 < right)
         {
             mid = (left + right) >> 1;
             if(Ans[mid].compareTo(n) > 0)
                 right = mid - 1;
             else
                 left = mid;
         }
         return Ans[right].compareTo(n) <= 0 ? Ans[right] : Ans[left];
     }
     public static void main(String[] args) throws IOException {
         //FileInputStream ios = new FileInputStream("in.txt");
         //System.setIn(ios);
         Scanner cin = new Scanner(System.in);
         getAns();
         int t = cin.nextInt();
         while(t-- > 0)
         {
             String n = new String();
             n = cin.next();
             BigInteger bn = new BigInteger(n);
             System.out.println(findAns(bn).toString());
         }
     }
 }
