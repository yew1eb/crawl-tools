import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
public class Main {
	public static void main(String[] args) {
		Scanner scanner=new Scanner(System.in);
		while(scanner.hasNext())
		{
		   int n=scanner.nextInt();
		   int m=scanner.nextInt();
		   String string[]=new String[n+1];
		   for(int i=0;i<n;i++)
		   {
			   string[i]=scanner.next();
		   }
		   for(int i=0;i<m;i++)
		   {
			   String string2=scanner.next();
			   String ss="^";
			   string2=string2.replace("?", ".");
			   string2=string2.replace("*", ".*");//.*表示0个或多个字母，因为“.”就表示一个字符
			   ss+=string2;
			   ss+="$";
			   int count=0;
			   Pattern pattern=Pattern.compile(ss);
			   for(int j=0;j<n;j++)
			   {
				   Matcher matcher=pattern.matcher(string[j]);
				   if(matcher.find())count++;
			   }
			   if(count==0)System.out.println("Not match");
			   else System.out.println(count);
		   }
		}
	}
}