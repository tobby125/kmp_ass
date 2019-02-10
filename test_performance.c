#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "string_matching.h"

int main() {
	char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	for (int n = 10000; n <= 1000000; n += 50000) {
		
		char *text = malloc(n + 1);
		for (int i = 0; i < n; i++) {
			text[i] = chars[rand() % sizeof(chars) - 1];	
		}
		
		char *pattern = malloc(401);
		for (int i = 0; i < 400; i++) {
			pattern[i] = chars[rand() % sizeof(chars) - 1];
		}
		
		double begin = clock();
		string_matching_naive(text, n, pattern, 400);
		double end = clock();
		double naive_runtime = (end - begin) / CLOCKS_PER_SEC;
		
		double begin2 = clock();
		string_matching_kmp(text, n, pattern, 400);
		double end2 = clock();
		double kmp_runtime = (end2 - begin2) / CLOCKS_PER_SEC;
		
		printf("Text length %d runtime- naive: %f, kmp: %f\n", n, naive_runtime, kmp_runtime);
		free(text);
		free(pattern);
	}
	return 0;
}