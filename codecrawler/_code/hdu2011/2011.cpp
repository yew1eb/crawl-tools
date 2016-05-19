import java.util.Scanner;
public class Main {
    public static void main(String[]args)
    {
    int n,b,k;
  double sum;
    Scanner cin=new Scanner(System.in);
    n=cin.nextInt();
    while(n!=0)
    {
        n--;
        sum=0;
        b=cin.nextInt();
        for(int i=1;i<=b;i++)
        {
            if(i%2==0)
                sum-=1.0/i;
            else sum+=1.0/i;
        }
        System.out.format("%.2f",sum);
        System.out.println();
        //System.out.println("sad");
         
    }
    }
}