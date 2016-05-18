import java.util.*;

public class Main {
	String ops = "+-*%";
	class Node {
		int n;
		String path;
	}
	int N, K, M, result, KM;
	Scanner input = new Scanner(System.in);
	LinkedList<Node> list = new LinkedList<Node>();
	boolean[] hash = new boolean[1000001];

	public static void main(String[] args) {
		new Main().work();
	}

	public int modulus(int a, int b) {
		return (a % b + b) % b;
	}

	public void work() {
		while (input.hasNext()) {
			N = input.nextInt();
			K = input.nextInt();
			M = input.nextInt();
			if (N == 0 && K == 0 && M == 0) {
				break;
			}
			KM = K * M;
			list.clear();
			Arrays.fill(hash, false);
			Node head = new Node();
			head.path = "";
			head.n = N;
			hash[modulus(N, KM)] = true;
			result = modulus(N + 1, K);
			list.add(head);
			bfs();
		}
		input.close();
	}

	public void bfs() {
		while (!list.isEmpty()) {
			Node node = list.poll();
			if (modulus(node.n, K) == result) {
				System.out.println(node.path.length());
				System.out.println(node.path);
				return;
			}
			for (int i = 0; i < ops.length(); i++) {
				doOp(ops.charAt(i), node);
			}
		}
		System.out.println(0);
	}

	public void doOp(char op, Node node) {
		int tmp = 0;
		switch (op) {
		case '+':
			tmp = modulus(node.n + M, KM);
			break;
		case '-':
			tmp = modulus(node.n - M, KM);
			break;
		case '*':
			tmp = modulus(node.n * M, KM);
			break;
		case '%':
			tmp = modulus(modulus(node.n, M), KM);
			break;
		}
		if (!hash[tmp]) {
			hash[tmp] = true;
			Node newNode = new Node();
			newNode.path = node.path + op;
			newNode.n = tmp;
			list.addLast(newNode);
		}
	}
}