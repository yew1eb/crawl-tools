int main() {
    int cas;
    bign sum, num;
    char str[N];

    cin >> cas;
    while (cas--) {
	sum = 0;
	getchar();
	while (cin >> str ) {
	    if (strcmp(str, "0") == 0)
		break;
	    num = str;
	    sum = sum + num;
	}

	sum.put();
	cout << endl;
	if (cas)
	    cout << endl;
    }
    return 0;
}