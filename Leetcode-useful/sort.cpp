#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;


void qsort(int *d, int a, int b) {
	if (a + 1 >= b) {
		return;
	}
	swap(d[rand() % (b - a) + a], d[a]);
	int tmp = d[a], i, j;
	for (i = a, j = b - 1; i < j;) {
		while (i < j && d[j] >= tmp) j --;
		swap(d[i], d[j]);
		while (i < j && d[i] <= tmp) i ++;
		swap(d[i], d[j]);
	}
	qsort(d, a, i);
	qsort(d, i + 1, b);
}

int main() {
	int te = 1;
	while (true) {
		int a[100], n = rand() % 90 + 1;
		for (int i = 0; i < n; ++ i) {
			a[i] = rand() % 100;
		//	printf("%d ", a[i]);
		}
		//puts("");
		qsort(a, 0, n);
		for (int i = 0; i < n - 1; i ++){
			assert(a[i] <= a[i + 1]);
		}
		printf("test %d passed!\n", te ++);
	}
}
