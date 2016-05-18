import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        BigInteger zero = BigInteger.valueOf(0);
        BigInteger ten = BigInteger.valueOf(10);
        int i, j, ncase;
        BigInteger a, b, min;
        ncase = cin.nextInt();
        for(j=1;j<=ncase;j++)
        {
            min = new BigInteger("99999999999999999999999999");
            a = cin.nextBigInteger();
            b = cin.nextBigInteger();
            if (a.toString().indexOf(b.toString()) != -1)//a包含b
            {
                min = zero;
            }
            else
            {
                BigInteger tmp1, tmp2;
                for (i = b.toString().length(); i <= 105; i++)
                {
                    tmp1 = a.mod(ten.pow(i));//a的后几位
                    if(tmp1.compareTo(b)==0) 后几位和b相等
                    {
                        min=zero;
                        break;
                    }
                    else if(tmp1.compareTo(b)==-1)//小于b
                    {
                        tmp2 = b.subtract(tmp1);
                        if(tmp2.compareTo(min)==-1)
                        {
                            min=tmp2;
                        }
                    }
                    else //大于b，在b的前面加1
                    {
                        tmp2 = b.add(ten.pow(b.toString().length()));
                        tmp2 = tmp2.subtract(tmp1);
                        if (tmp2.compareTo(min) == -1&& tmp2.compareTo(zero) != -1)
                        {
                            min = tmp2;
                        }
                    }
                    b = b.multiply(ten);//b乘以10
                }
                
            }
            System.out.println("Case #" + j +": " + min);
        }
    }
}