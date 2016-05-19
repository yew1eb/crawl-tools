import java.util.Scanner;
public class Main{	
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int N=input.nextInt();
		while(N-->0){
			int n=input.nextInt();
			for(int i=1;i<=n;i++){
				System.out.print(i);
				for(int j=2;j<=n;j++){
					System.out.print(" "+i*j);
				}
				System.out.println();
			}
		}
	}
}