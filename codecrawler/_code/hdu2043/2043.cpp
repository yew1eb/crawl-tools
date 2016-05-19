import java.io.BufferedInputStream;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int n = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < n; i++) {
			String s = sc.nextLine();

			if (s.length() >= 8 && s.length() <= 16) {
				//匹配 大写字母 A-Z任意一个字母
				Pattern p1 = Pattern.compile("[A-Z]");
				Matcher m1 = p1.matcher(s);
				//匹配小写字母a-z任意一个字母
				Pattern p2 = Pattern.compile("[a-z]");
				Matcher m2 = p2.matcher(s);
				//匹配0-9任意一个数字
				Pattern p3 = Pattern.compile("\\d");
				Matcher m3 = p3.matcher(s);
				//匹配特殊字符
				Pattern p4 = Pattern.compile("~|!|@|#|\\$|%|\\^");
				Matcher m4 = p4.matcher(s);

				if (m1.find() && m2.find() && m3.find() && m4.find()) {
					System.out.println("YES");
				} else if (m1.find() && m2.find() && m3.find()) {
					System.out.println("YES");
				} else if (m1.find() && m2.find() && m4.find()) {
					System.out.println("YES");
				} else if (m1.find() && m3.find() && m4.find()) {
					System.out.println("YES");
				} else if (m2.find() && m3.find() && m4.find()) {
					System.out.println("YES");
				}

				else
					System.out.println("NO");
			} else
				System.out.println("NO");
		}
	}

}