#include <stdio.h>

int main() {
	char min_char = 1;
	unsigned char min_uchar = 1;

	while (min_char > 0) {
		min_char = min_char * 2;
	}
	printf("Min char = %d\n", min_char);
	min_char--;
	printf("Max char = %d\n", min_char);

	while (min_uchar > 0) {
		min_uchar *= 2;
	}
	printf("Min unsigned char = %d\n", min_uchar);
	min_uchar--;
	printf("Max unsigned char = %d\n", min_uchar);


	short min_short = 1;
	unsigned short min_ushort = 1;

	while (min_short > 0) {
		min_short = min_short * 2;
	}
	printf("Min short = %d\n", min_short);
	min_short--;
	printf("Max short = %d\n", min_short);

	while (min_ushort > 0) {
		min_ushort *= 2;
	}
	printf("Min unsigned short = %d\n", min_ushort);
	min_ushort--;
	printf("Max unsigned short = %d\n", min_ushort);


	int min_int = 1;
	unsigned int min_uint = 1;

	while (min_int > 0) {
		min_int = min_int * 2;
	}
	printf("Min int = %d\n", min_int);
	min_int--;
	printf("Max int = %d\n", min_int);

	while (min_uint > 0) {
		min_uint *= 2;
	}
	printf("Min unsigned int = %u\n", min_uint);
	min_uint--;
	printf("Max unsigned int = %u\n", min_uint);

	long min_long = 1;
	unsigned long min_ulong = 1;

	while (min_long > 0) {
		min_long = min_long * 2;
	}
	printf("Min long = %ld\n", min_long);
	min_long--;
	printf("Max long = %ld\n", min_long);

	while (min_ulong > 0) {
		min_ulong *= 2;
	}
	printf("Min unsigned long = %ld\n", min_ulong);
	min_ulong--;
	printf("Max unsigned long = %lu\n", min_ulong);


	long long min_long_long = 1;
	unsigned long long min_ulong_long = 1;

	while (min_long_long > 0) {
		min_long_long = min_long_long * 2;
	}
	printf("Min long long = %lld\n", min_long_long);
	min_long_long--;
	printf("Max long long = %lld\n", min_long_long);

	while (min_ulong_long > 0) {
		min_ulong_long *= 2;
	}
	printf("Min unsigned long long = %llu\n", min_ulong_long);
	min_ulong_long--;
	printf("Max unsigned long long = %llu\n", min_ulong_long);
}