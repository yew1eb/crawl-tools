import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		while(input.hasNext()){
			int k=input.nextInt();
			int i=0;
			for(i=1;i<65;i++){
				if((18+k*i)%65==0){
					System.out.println(i);
					break;
				}
			}
			if(i>=65)
				System.out.println("no");
		}
	}
}