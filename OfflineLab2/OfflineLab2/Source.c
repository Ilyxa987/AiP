#include <stdio.h>
#include <math.h>


int factorial(n) {
	int g = 1;
	for (int i = 1; i <= n; i++) {
		g = g * i;
	}
	return g;
}



int main() {
	double x, eps;
	unsigned int n;
	double presum = 0;
	double num;
	scanf_s("%lf", &x);
	scanf_s("%lf", &eps);
	scanf_s("%d", &n);
	double sum = x;


	int j = 2;
	do {
		presum = sum;
		sum = sum + ((pow(-1.0, j+1) / factorial(j)) * pow(x, j));
		j++;
		printf("%d) %lf\n", j, sum);
	} while (abs(abs(sum) - abs(presum)) > eps);
	printf("Number 1 - %.15le\n", sum);


	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			sum = x;
		}
		else {
			presum = sum;
			num = (pow(-1.0, i + 1) / factorial(i)) * pow(x, i);
			sum = sum + num;
			printf("%d) %.15le\n", i, sum);
			if (sum != sum || 1.0 / sum == 0.0) {
				printf("Number 2.5 - %.15le\n", presum);
				break;
			}
		}
	}
	printf("Number 2 - %.15le\n", sum);


	int k = 2;
	sum = x;
	do {
		presum = sum;
		sum += ((pow(-1.0, k+1) / factorial(k)) * pow(x, k));
		k++;
		printf("%d) %.15le\n", k, sum);
		if (sum != sum || 1.0 / sum == 0.0) {
			printf("Number 3 - %.15le\n", presum);
			break;
		}
	} while(1);
}


