import java.math.*;
import java.util.Scanner;
import java.io.*;

public class Main{
	
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		while(in.hasNext()){
		 String str=in.next();
	          int len=str.length();
		 BigInteger a=new BigInteger(str);
		 boolean flag=true;
		 for(int i=1;i<=len;i++)
		 {
			 BigInteger b=BigInteger.valueOf(i);
			 b=b.multiply(a);
			 String  str2=b.toString();
			 while(str2.length()<len)
			 {
				str2="0"+str2;
			}
			 str2=str2+str2;  //把两个字符串连在一起 判断是否是子串
			  if(str2.indexOf(str)<0)
			 { 
			
				 flag=false;
			 }
				  
			 if(flag==false) break;
			 
		 }
		 if(flag==false)
			 System.out.println(str+" is not cyclic");
		 else System.out.println(str+" is cyclic");
		 }	
	}
	
	
}