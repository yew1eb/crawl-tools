package hdu2019;

import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		List<Integer> list = new ArrayList<Integer>();

		while (cin.hasNext()) {
			int n = cin.nextInt();
			int m = cin.nextInt();
			if (n + m == 0)
				break;
			list.clear();
			for (int i = 0; i < n; i++) {
				list.add(cin.nextInt());  //添加元素
			}
			list.add(m);
			Collections.sort(list);  //排序
			for (int i = 0; i<list.size(); i++){
				if(i==0){
					System.out.print(list.get(i));
				}else{
					System.out.print(" "+list.get(i));
				}
			}
			System.out.println();
		}
	}

}