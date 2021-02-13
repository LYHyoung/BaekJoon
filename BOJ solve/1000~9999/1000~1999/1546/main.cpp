#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, score[1000];
	int max = 0;
	double newScore[1000], sum = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &score[i]);
		if (score[i] > max) max = score[i];
	}
	for (int i = 0; i < n; i++) {
		newScore[i] = (double)score[i] / (double)max * 100;
		sum += newScore[i];
	}
	printf("%.4lf\n", (double)(sum / n));
	return 0;
}