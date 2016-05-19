#include <stdio.h>
#include <string.h>
const int N = 105;
const char song[16][10] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

char name[N][N];

void sing(int n) {
	int flag = 1;
	for (int i = 0; flag || i % 16; i++) {
		if (i >= n && i % 16 == 0) return;
		printf("%s: %s\n", name[i % n], song[i % 16]);
	}
}

int main () {
	int n;

	while (scanf("%d", &n) == 1)  {
		for (int i = 0; i < n; i++)
			scanf("%s", name[i]);
		sing(n);
	}
	return 0;
}