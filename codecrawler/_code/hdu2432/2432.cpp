int n;
void dfs(int x1, int y1, int x2, int y2) {
    if (y1 + y2 <= n) {
        dfs(x1, y1, x1 + x2, y1 + y2);
        printf("%d/%d\n", x1 + x2, y1 + y2);
        dfs(x1 + x2, y1 + y2, x2, y2);
    }
}
void print_farey(int n) {
    printf("0/1\n");
    dfs(0, 1, 1, 1);
    printf("1/1\n");
}

int main() {
    freopen("data.in", "r", stdin);
    while(scanf("%d", &n) == 1) {
        print_farey(n);
    }
    return 0;
}