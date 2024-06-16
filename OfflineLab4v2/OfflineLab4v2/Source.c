#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define COUNT 10000
#define N 1000

void sum(int a[COUNT], int b[COUNT]) {
	for (int i = 0; i < N + 1; i++) {
		a[i] += b[i];
		if (a[i] > 9) {
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
	}
}

int bolsh(char a[N], char b[N]) {
	for (int i = N - 1; i > -1; i--) {
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return 0;
	}
	return 1;
}

void razn(int a[COUNT], int b[COUNT]) {
	for (int i = 0; i < COUNT; i++) {
		if (a[i] - b[i] < 0) {
			a[i] = a[i] - b[i] + 10;
			int j = i + 1;
			while (1) {
				if (a[j] == 0) {
					a[j] = 9;
					j++;
				}
				else {
					a[j] -= 1;
					break;
				}
			}
		}
		else {
			a[i] -= b[i];
		}
	}
}

void vivod(int a[COUNT]) {
	int flag = 0;
	for (int i = COUNT - 1; i > -1; i--) {
		if (a[i] != 0 && !flag) {
			printf("%d", a[i]);
			flag = 1;
		}
		else if (flag) {
			printf("%d", a[i]);
		}
	}
	if (!flag) printf("0");
}

void umnozh(int a[COUNT], int b[COUNT]) {
	int c[COUNT] = { 0 };
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	for (int i = 0; i < COUNT; i++) {
		if (c[i] > 9) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
		a[i] = c[i];
	}
}

int sumstr(int a[COUNT]) {
	int f = 0;
	for (int i = 0; i < COUNT; i++) {
		f += a[i];
	}
	return f;
}

void stepen(int a[COUNT], int b[COUNT]) {
	int c[COUNT] = { 0 };
	for (int i = 0; i < COUNT; i++) {
		c[i] = a[i];
	}
	int d[COUNT] = { 0 };
	d[0] = 1;
	while (sumstr(b) - 1 || b[0] != 1) {
		umnozh(c, a);
		razn(b, d);
	}
	for (int i = 0; i < COUNT; i++) {
		a[i] = c[i];
	}
}

int ravn(int a[COUNT], int b[COUNT]) {
	for (int i = 0; i < COUNT; i++) {
		if (a[i] > b[i]) return 0;
		if (a[i] < b[i]) return 0;
	}
	return 1;
}

void fact(int a[COUNT]) {
	int b[COUNT] = { 0 };
	int c[COUNT] = { 0 };
	int d[COUNT] = { 0 };
	d[0] = 1;
	b[0] = 1;
	c[0] = 2;
	if (ravn(a, d)) {
		for (int i = 0; i < COUNT; i++) {
			a[i] = 0;
		}
		a[0] = 1;
	}
	else {
		while (!ravn(a, c)) {
			umnozh(b, c);
			sum(c, d);
		}
		umnozh(b, c);
		for (int i = 0; i < COUNT; i++) {
			a[i] = b[i];
		}
	}
}

void progress(int a[COUNT], int b[COUNT], int minusa, int minusb) {
	int ed[COUNT] = { 0 };
	ed[0] = 1;
	int g = 0;
	int d[COUNT] = { 0 };
	if (minusa == minusb) {
		int c[COUNT] = { 0 };
		sum(c, a);
		sum(c, b);
		if (c[0] % 2 != 0 && bolsh(b, a)) {
			razn(c, ed);
			razn(b, ed);
			g = 1;
		}
		if (c[0] % 2 != 0 && bolsh(a, b)) {
			razn(c, ed);
			razn(a, ed);
			g = 1;
		}
		int h = 0;
		for (int i = COUNT - 1; i > -1; i--) {
			if (c[i] != 0 && !h) {
				d[i] = c[i] / 2;
				c[i - 1] += (c[i] % 2) * 10;
				h = 1;
			}
			else if (h) {
				d[i] = c[i] / 2;
				if (i != 0) {
					c[i - 1] += (c[i] % 2) * 10;
				}
			}
		}
		if (bolsh(b, a)) {
			int bb[COUNT] = { 0 };
			for (int i = 0; i < COUNT; i++) {
				bb[i] = b[i];
			}
			razn(bb, a);
			sum(bb, ed);
			umnozh(d, bb);
			if (g) {
				sum(b, ed);
				sum(d, b);
			}
		}
		if (bolsh(a, b)) {
			int aa[COUNT] = { 0 };
			for (int i = 0; i < COUNT; i++) {
				aa[i] = a[i];
			}
			razn(aa, b);
			sum(aa, ed);
			umnozh(d, aa);
			if (g) {
				sum(a, ed);
				sum(d, a);
			}
			printf("-");
		}
	}
	else if (minusa) {
		int c[COUNT] = { 0 };
		int l[COUNT] = { 0 };
		progress(c, a, 0, 0);
		progress(l, b, 0, 0);
		//if (ravn(l, c)) {
		//	printf("0");
		//}
		if (bolsh(l, c)) {
			razn(l, c);
			for (int i = 0; i < COUNT; i++) {
				d[i] = l[i];
			}
		}
		else if (bolsh(c, l)) {
			razn(c, l);
			for (int i = 0; i < COUNT; i++) {
				d[i] = c[i];
			}
			printf("-");
		}
	}
	for (int i = 0; i < COUNT; i++) {
		a[i] = d[i];
	}
}

int main() {
	char znak = 0;
	char a_string[N] = { 0 };
	char b_string[N] = { 0 };
	scanf("%c", &znak);
	scanf("%s", &a_string);
	if (znak != '!') scanf("%s", &b_string);
	int minusa = 0;
	int minusb = 0;
	int nulla = 0;
	int nullb = 0;
	if (a_string[0] == '0') nulla = 1;
	if (b_string[0] == '0') nullb = 1;
	if (a_string[0] == '-') {
		minusa = 1;
		for (int i = 1; i < N; i++) {
			a_string[i - 1] = a_string[i];
		}
	}
	if (b_string[0] == '-') {
		minusb = 1;
		for (int i = 1; i < N; i++) {
			b_string[i - 1] = b_string[i];
		}
	}
	int a[COUNT] = { 0 };
	int b[COUNT] = { 0 };
	int ha = 0;
	int hb = 0;
	for (int i = N - 1; i > -1; i--) {
		if (a_string[i] != 0) {
			a[ha] = a_string[i] - 48;
			ha++;
		}
		if (b_string[i] != 0) {
			b[hb] = b_string[i] - 48;
			hb++;
		}
	}

	int vel = bolsh(a_string, b_string);

	int nu[COUNT] = { 0 };

	if (znak == '+' && minusa == minusb) {
		sum(a, b);
		if (minusa && !ravn(a, nu)) printf("-");
		vivod(a);
	}

	else if (znak == '+' &&  vel) {
		razn(a, b);
		if (minusa && !ravn(a, nu)) printf("-");
		vivod(a);
	}

	else if (znak == '+' && !vel) {
		razn(b, a);
		if (minusb) printf("-");
		vivod(b);
	}

	else if (znak == '-' && vel && minusa == minusb) {
		razn(a, b);
		if (minusa && !ravn(a, nu)) printf("-");
		vivod(a);
	}

	else if (znak == '-' && !vel && minusa == minusb) {
		razn(b, a);
		if (!minusa && !ravn(a, nu)) printf("-");
		vivod(b);
	}

	else if (znak == '-') {
		sum(a, b);
		if (minusa && !ravn(a, nu)) printf("-");
		vivod(a);
	}

	else if (znak == '*' && (nulla || nullb)) {
		printf("0");
	}

	else if (znak == '*' && minusa == minusb) {
		umnozh(a, b);
		vivod(a);
	}

	else if (znak == '*') {
		umnozh(a, b);
		printf("-");
		vivod(a);
	}

	else if (znak == '^' && nullb && !nulla) {
		printf("1");
	}

	else if (znak == '^' && !nullb && nulla) {
		printf("0");
	}

	else if (znak == '^' && nullb && nulla) {
		printf("Error");
	}

	else if (znak == '^') {
		if (minusa && b[0] % 2 != 0) printf("-");
		stepen(a, b);
		vivod(a);
	}

	else if (znak == '!' && minusa) {
		printf("Error");
	}

	else if (znak == '!') {
		if (nulla) printf("1");
		else {
			fact(a);
			vivod(a);
		}
	}

	else if (znak == 'E' && vel && !minusa && !minusb) {
		printf("Error");
	}

	else if (znak == 'E' && !minusa && minusb) {
		printf("Error");
	}

	else if (znak == 'E') {
		progress(a, b, minusa, minusb);
		vivod(a);
	}
	return 0;
} // нет нуля