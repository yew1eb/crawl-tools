import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main {

	static long[] arr = new long[50];
	static long[] sum = new long[50];
	static {
		arr[0] = 1;
		arr[1] = 1;
		sum[0] = 1;
		sum[1] = 2;
	}

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(
				System.out));
		int n;

		for (int c = 2; c < arr.length; c++) {
			arr[c] = arr[c - 2] + arr[c - 1];
			sum[c] = arr[c] + sum[c - 1];
		}

		while ((n = Integer.parseInt(in.readLine())) != -1) {
			if(n==0)
				out.write("0 1\n");
			else
			out.write(sum[n-1] + " " + sum[n] + "\n");
		}

		out.flush();

	}

}