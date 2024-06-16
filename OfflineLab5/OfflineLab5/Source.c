#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#define N 78000

// sred = O(n * log n)\
   max = O(n^2)
void quicksort(int a[N], int lo, int hi, int *c, int *m) {
	int low = lo; int high = hi;
	int med = a[(low + high) / 2];
	while (low <= high) {
		while (a[low] < med) {
			low++;
			*c += 1;
		}
		while (a[high] > med) {
			high--;
			*c += 1;
		}
		if (low <= high) {
			int t = a[low];
			a[low] = a[high];
			a[high] = t;
			low++;
			high--;
			*m += 2;
		}
	}
	if (lo < high) {
		quicksort(a, lo, high, c, m);
	}
	if (hi > low) {
		quicksort(a, low, hi, c, m);
	}
}

// sred = O(n^3/2) \
   max = O(n^2)
void sort_Shell(int a[N], int *c, int *m) {
	for (int s = N / 2; s > 0; s /= 2) {
		for (int i = s; i < N; i++) {
			*c += 1;
			for (int j = i - s; j >= 0 && a[j] > a[j + s]; j -= s) {
				int t = a[j];
				a[j] = a[j + s];
				a[j + s] = t;
				*m += 2;
			}
		}
	}
}

// O(n^2)
void choice_sort(int a[N], unsigned long long *c, int *m) {
	for (int i = 0; i < N - 1; i++) {
		int min_index = i;
		for (int j = i; j < N; j++) {
			*c += 1;
			if (a[min_index] > a[j]) {
				min_index = j;
			}
		}
		if (min_index != i) {
			int t = a[min_index];
			a[min_index] = a[i];
			a[i] = t;
			*m += 2;
		}
	}
}

int main() {
	srand(56);
	int arr[N] = { 0 };
	for (int i = 0; i < N; i++) {
		arr[i] = rand();
	}

	int brr[N] = { 0 };
	for (int i = 0; i < N; i++) {
		brr[i] = rand();
	}

	int crr[N] = { 0 };
	for (int i = 0; i < N; i++) {
		crr[i] = rand();
	}
	
	int c1 = 0;
	int m1 = 0;
	clock_t t1 = 0;
	
	t1 = clock();
	quicksort(arr, 0, N - 1, &c1, &m1);
	t1 = clock() - t1;
	printf("QuickSort\nSravn = %d, Swaps = %d, Time = %d\n", c1, m1, t1);

	int c2 = 0;
	int m2 = 0;
	clock_t t2 = 0;
	t2 = clock();
	
	sort_Shell(brr, &c2, &m2);
	t2 = clock() - t2;
	printf("Shell\nSravn = %d, Swaps = %d, Time = %d\n", c2, m2, t2);

	unsigned long long c3 = 0;
	int m3 = 0;
	clock_t t3 = 0;
	t3 = clock();

	choice_sort(crr, &c3, &m3);
	t3 = clock() - t3;
	printf("Selection sort\nSravn = %lu, Swaps = %d, Time = %d", c3, m3, t3);
	return 0;
}