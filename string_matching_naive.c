#include "string_matching.h"

int string_matching_naive(char *text, int N, char* pattern, int M) {
	int matches = 0;
	int match;
	for (int n = 0; n < N; n++) {
		match = 1;
		for (int m = 0; m < M; m++) {
			if (text[n + m] != pattern[m]) {
				match = 0;
			}
		}
		matches += match;
	}
	return matches;
}
/*
int main() {
	char text[5] = {"bobob"};
	char pattern[3] = {"bob"};
	printf("%d", string_matching_naive(text, 5, pattern, 3));
	return 0;
}
*/