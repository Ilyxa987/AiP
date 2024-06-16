#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 10000

int main() {
	FILE* file = fopen("include.c", "r");
	FILE* out = fopen("out.c", "w");
	char code[N] = { 0 };
	int f = 0;
	int g = 0;
	int p = 0;
	int space = 0;
	int comment = 0;
	int cont = 0;
	do {
		f = 1;
		space = 0;
		comment = 0;
		if (g) f = 0;
		fgets(code, 1000, file);
		int i = 0;
		if (cont) {
			f = 0;
			cont = 0;
			comment = 1;
		}
		while (code[i]) {
			if (code[i] != '\t' && code[i] != '/' && !comment) {
				space = 1;
			}
			if (code[i] != '\t' && code[i + 1] != '*' && code[i] != '/' && !comment) {
				space = 1;
			}
			if (code[i] == '"' && !p) {
				p = 1;
				i++;
				continue;
			}
			if (code[i] == 92 && !p) {
				if (comment && code[i + 1] == '\n') {
					cont = 1;
				}
				if (code[i + 1] == 92) i++;
				else i += 2;
				continue;
			}
			if (code[i] == '"' && p) p = 0;
			if (code[i] == '/' && code[i + 1] == '/' && !p) {
				comment = 1;
				if (space == 0) {
					f = 0;
				}
				else {
					f = 1;
					code[i] = '\n';
					code[i + 1] = '\0';
				}
			}
			if (code[i] == '/' && code[i + 1] == '*' && !p && !comment) {
				g = 1;
				if (space == 0) f = 0;
				else {
					f = 1;
					code[i] = '\n';
					code[i + 1] = '\0';
				}
			}
			if (code[i] == '*' && code[i + 1] == '/' && !p && !comment) {
				g = 0;
				code[i] = '\n';
				code[i + 1] = ' ';
			}
			i++;
		}
		i = 0;
		while (code[i] && f) {

			fputc(code[i], out);
			i++;
		}
	} while (code[0] != '}');
	return 0;
}