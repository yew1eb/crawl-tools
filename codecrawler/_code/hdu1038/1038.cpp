import java.util.Scanner;
public class Main  
{  
    public static void main(String args[])
    {
        Scanner cin=new Scanner(System.in);
        int i=0;
        while(cin.hasNext())
        {
            i++;
            float d=cin.nextFloat();
            int r=cin.nextInt();
            float t=cin.nextFloat();
            if(r==0)return;
            float p=3.1415927f;
            float mi=1/63360f;
            float hs=1/3600f;
            float dis=p*d*r*mi;
            float hour=t*hs;
            System.out.printf("Trip #%d: %.2f %.2f\r\n",i,dis,dis/hour);//以前pe都是因为没有加上\r 
        }
    }
}