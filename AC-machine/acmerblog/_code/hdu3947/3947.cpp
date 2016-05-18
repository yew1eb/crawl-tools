class node {
		int be, ne;
		int id, val;
		node(int b, int e, int v) {
			be = b;
			ne = e;
			val = v;
		}
	}
	node buf[] = new node[maxn];
	int E[] = new int[maxn], len;
	void add(int a, int b, int v) {
		buf[len] = new node(b, E[a], v);
		id[b] = len;
		E[a] = len++;
	}
	Scanner scan = new Scanner(System.in);
	int n, m, id[] = new int[maxn], sum;
	boolean is[] = new boolean[maxn];
	MINCOST sp = new MINCOST();
	void init() {
		sp.init();
		len = 0;
		Arrays.fill(E, -1);
		Arrays.fill(is, true);
		sum = 0;
	}
	void run() {
		int cas = scan.nextInt();
		for (int k = 1; k <= cas; k++) {
			System.out.print("Case #" + k + ": ");
			n = scan.nextInt();
			init();
			int a, b, v;
			for (int i = 1; i < n; i++) {
				a = scan.nextInt();
				b = scan.nextInt();
				v = scan.nextInt();
				is[a] = false;
				add(b, a, v);
			}
			int root = -1;
			for (int i = 1; i <= n; i++)
				if (is[i]) {
					root = i;
					break;
				}
			id[root] = n - 1;
			int s, t, l, c;
			m = scan.nextInt();
			for (int i = 0; i < m; i++) {
				s = scan.nextInt();
				t = scan.nextInt();
				l = scan.nextInt();
				c = scan.nextInt();
				sp.addcap(id[s], id[t], l, c);
			}
			int temp = 0;
			for (int i = E[root]; i != -1; i = buf[i].ne) {
				temp += buf[i].val;
				sp.addcap(n - 1, i, inf, 0);
				dfs(i);
			}
			sp.addcap(n - 1, n + 1, temp, 0);
			int ans = sp.solve(n, n + 1);
			if (sp.maxflow == sum)
				System.out.println(ans);
			else
				System.out.println(-1);
		}
	}
	void dfs(int a) {
		int temp = buf[a].val;
		int v = buf[a].be;
		for (int i = E[v]; i != -1; i = buf[i].ne) {
			sp.addcap(a, i, inf, 0);
			temp -= buf[i].val;
			dfs(i);
		}
		if (temp > 0) {
			sp.addcap(n, a, temp, 0);
			sum += temp;
		} else
			sp.addcap(a, n + 1, -temp, 0);
	}