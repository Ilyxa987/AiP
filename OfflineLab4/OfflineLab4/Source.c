#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 2000
#define ASCII 48

void razn(int a[N], int b[N]) {
	int p = 0;
	for (int i = N - 1; i > -1; i--) {
		if (a[i] != 0 && b[i] != 0) {
			char p = a[i] - b[i];
			if (p < 0) {
				int j = 1;
				while (1) {
					if (a[i - j] == 0) {
						a[i - j] = 9;
						j++;
					}
					else {
						a[i - j] -= 1;
						break;
					}
				}
				a[i] = 10 + p;
			}
			else {
				a[i] = p;
			}
		}
	}
}

void sum(int a[N], int b[N]) {
	int p = 0;
	for (int i = N - 1; i > -1; i--) {
		if (a[i] != 0 && b[i] != 0) {
			p = a[i] + b[i];
			a[i] = p % 10;
			if (a[i - 1] == 0 && p / 10 != 0) {
				a[i - 1] = p / 10;
			}
			else a[i - 1] += p / 10;
		}
		else if (a[i] == 0) {
			a[i] = b[i];
		}
	}

}

void preob(int a[N], int minus) {
	if (minus) {
		a[0] = -1;
	}
}

int bolsh(int a[N], int b[N]) {
	for (int i = 0; i < N; i++) {
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return 0;
	}
}

int sumstr(int a[N]) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] != 0) {
			sum += a[i] - ASCII;
		}
	}
	return sum;
}

void umnozh(int a[N], int b[N], int c[N]) {
	for (int i = N - 1; i > -1; i--) {
		for (int j = N - 1; j > -1; j--) {
			if (a[i] != 0 && b[j] != 0) {
				int p = a[i] * b[j];
				c[i + j] += p;
			}
			else if (b[j] == 0) break;
		}
		if (a[i] == 0) break;
	}
	for (int i = N - 1; i > -1; i--) {
		c[i - 1] += c[i] / 10;
		c[i] %= 10;
	}
}

void pr(int a[N]) {
	if (a[0] == -1) {
		printf("%c", '-');
	}
	int g = 0;
	for (int i = 1; i < N; i++) {
		if (a[i] != 0 && !g) {
			printf("%d", a[i]);
			g = 1;
		}
		else if (g) {
			printf("%d", a[i]);
		}
	}
}

void prc(int a[N * 2 - 1]) {
	if (a[0] == -1) {
		printf("%c", '-');
	}
	int g = 0;
	for (int i = 1; i < N * 2 - 1; i++) {
		if (a[i] != 0 && !g) {
			printf("%d", a[i]);
			g = 1;
		}
		else if (g) {
			printf("%d", a[i]);
		}
	}
}

void stepen(int a[N], unsigned int b, int c[N]) {
	for (int i = 0; i < N; i++) {
		c[i] = a[i];
	}
	for (int i = 0; i < b; i++) {
		int d[N] = { 0 };
		umnozh(c, a, d);
		for (int j = 0; j < N; j++) {
			c[j] = d[j];
		}
	}
}

int main() {
	char znak = 0;
	char ab[N] = { 0 };
	char bb[N] = { 0 };
	int a[N] = { 0 };
	int b[N] = { 0 };
	int ste = 0;
	int minusa = 0;
	int minusb = 0;
	scanf("%c", &znak);
	scanf("%s", &ab);
	if (znak != '^') scanf("%s", &bb);
	else scanf("%d", &ste);
	int ha = N - 1;
	int hb = N - 1;
	if (ab[0] == '-') {
		minusa = 1;
		ab[0] = 0;
	}
	if (bb[0] == '-') {
		minusb = 1;
		bb[0] = 0;
	}
	for (int i = 0; i < N; i++) {
		a[i] = ab[i] - ASCII;
		b[i] = bb[i] - ASCII;
	}
	for (int i = N - 1; i > -1; i--) {
		if (a[i] >= 0) {
			a[ha] = a[i];
			a[i] = 0;
			ha--;
		}
		if (a[i] == -48) {
			a[i] = 0;
		}
		if (b[i] >= 0) {
			b[hb] = b[i];
			b[i] = 0;
			hb--;
		}
		if (b[i] == -48) {
			b[i] = 0;
		}
	}

	int flag = bolsh(a, b);

	if (znak == '+' && (minusa && minusb || !minusa && !minusb)) {
		sum(a, b);
		preob(a, minusa);
		pr(a);
	}

	else if (znak == '+' && flag) {
		razn(a, b);
		preob(a, minusa);
		pr(a);
	}

	else if (znak == '+' && !flag) {
		razn(b, a);
		preob(b, minusb);
		pr(b);
	}

	else if (znak == '-' && flag && (!minusa && !minusb || minusa && minusb)) {
		razn(a, b);
		preob(a, minusa);
		pr(a);
	}

	else if (znak == '-' && flag && minusa && minusb) {
		razn(a, b);
		preob(a, minusa);
		pr(a);
	}

	else if (znak == '-' && flag) {
		sum(a, b);
		preob(a, minusa);
		pr(a);
	}

	else if (znak == '-' && !flag && (!minusa && !minusb || minusa && minusb)) {
		razn(b, a);
		preob(b, !minusb);
		pr(b);
	}

	else if (znak == '-' && !flag) {
		sum(a, b);
		preob(a, minusa);
		pr(a);
	}

	else if (znak == '*' && minusa == minusb) {
		int c[N] = {0};
		umnozh(a, b, c);
		prc(c);
	}

	else if (znak == '*') {
		int c[2 * N - 1] = { 0 };
		umnozh(a, b, c);
		c[0] = -1;
		prc(c);
	}

	else if (znak == '^') {
		int c[N] = { 0 };
		stepen(a, ste, c);
		pr(c);
	}

	return 0;
}