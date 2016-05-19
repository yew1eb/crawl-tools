import java.util.*;

class result {
	StringBuffer s = new StringBuffer();

	public void setS(String s) {
		this.s.append(s);
	}

	public boolean getS() {
		String ssString = new String();
		if (s.length() < 8)
			return false;
		char c = s.charAt(s.length() - 8);
		if (c != ' ')
			return false;
		ssString = s.substring(s.length() - 7);
		return ssString.equals("no good");
	}
}

public class Main {
	public static void main(String[] args) {
		Scanner inScanner = new Scanner(System.in);
		int[][] a;
		a = new int[2][105];
		int T;
		while (inScanner.hasNextInt()) {
			T = inScanner.nextInt();
			String string = new String();
			string = inScanner.nextLine();
			if (T == 0)
				break;
			int temp = (T + 1) / 2;
			for (int i = 1; i <= temp; i++) {
				System.out.print(i + " ");
			}
			System.out.println("Score");
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j <= temp; j++)
					a[i][j] = -1;
			}
			result sss = new result();
			for (int i = 0; i < T; i++) {
				sss.setS(inScanner.nextLine());
				if (sss.getS() == true) {
					if (i % 2 == 1)
						a[1][i / 2] = 0;
					else
						a[0][i / 2] = 0;
				} else {
					if (i % 2 == 1)
						a[1][i / 2] = 1;
					else
						a[0][i / 2] = 1;
				}
			}
			for (int i = 0; i < 2; i++) {
				int cnt = 0;
				for (int j = 0; j < temp - 1; j++) {
					if (a[i][j] == 0)
						System.out.print("X" + " ");
					else {
						System.out.print("O" + " ");
						cnt++;
					}
				}
				if (a[i][temp - 1] == 0)
					System.out.print("X" + " ");
				else if (a[i][temp - 1] == 1) {
					System.out.print("O" + " ");
					cnt++;
				} else
					System.out.print("-" + " ");
				System.out.println(cnt);
			}
		}
	}
}