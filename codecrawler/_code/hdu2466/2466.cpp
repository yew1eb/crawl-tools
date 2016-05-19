import java.math.BigInteger;
import java.util.*;
public class Main{
    public static BigInteger sqrt(BigInteger n)
    {
        BigInteger l=BigInteger.ZERO,r=n,mid,tmp;
        while(l.compareTo(r)<0)
        {
            mid=(l.add(r)).divide(BigInteger.valueOf(2));
            tmp=mid.multiply(mid);
            if(tmp.compareTo(n)>0)
                r=mid.subtract(BigInteger.ONE);
            else if(tmp.compareTo(n)<0)
                l=mid.add(BigInteger.ONE);
            else
                return mid;
        }
        return l;
    }

    public static boolean can_sqrt(BigInteger n) {
        BigInteger tmp=sqrt(n);
        tmp=tmp.multiply(tmp);
        if(tmp.compareTo(n)==0)
            return true;
        return false;
    }

    public static void main(String args[])
    {
        int cas=0;
        Scanner cin=new Scanner(System.in);
        BigInteger n,d,e;
        while(cin.hasNext())
        {
            n=cin.nextBigInteger();
            d=cin.nextBigInteger();
            e=cin.nextBigInteger();
            if(n.compareTo(BigInteger.ZERO)==0 && e.compareTo(BigInteger.ZERO)==0 && d.compareTo(BigInteger.ZERO)==0)
            {
                break;
            }
            d=d.multiply(e);
            d=d.subtract(BigInteger.ONE);
            int i=0;
            while(true)
            {
                i++;
                //  pq  = n
                // de-1 = k*(p-1)*(q-1)      枚举(p-1)(q-1)=tmp
                BigInteger tmp=d.mod(BigInteger.valueOf(i));
                if(tmp.compareTo(BigInteger.ZERO)>0)
                    continue;
                tmp=d.divide(BigInteger.valueOf(i));
                BigInteger delta=((n.subtract(tmp.add(BigInteger.ONE))).pow(2)).subtract(tmp.multiply(BigInteger.valueOf(4)));
                if(can_sqrt(delta)==true)
                {
                    delta=sqrt(delta);
                    BigInteger p,q;
                    p=((n.subtract(tmp.subtract(BigInteger.ONE))).subtract(delta)).divide(BigInteger.valueOf(2));
                    q=((n.subtract(tmp.subtract(BigInteger.ONE))).add(delta)).divide(BigInteger.valueOf(2));
                    if(p.compareTo(q)>0)
                    {
                        BigInteger cnt=p;
                        p=q;
                        q=cnt;
                    }
                    System.out.println("Case #"+ ++cas +": "+p+" "+q);
                    break;

                }

            }
        }
    }
}