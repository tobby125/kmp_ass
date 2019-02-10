#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "string_matching.h"

int main() {
	char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	for (int n = 10000; n <= 10000000; n += 50000) {
		
		char text[n];
		for (int i = 0; i < n; i++) {
			text[i] = chars[rand() % sizeof(chars)];	
		}
		
		char pattern[400];
		for (int i = 0; i < 400; i++) {
			pattern[i] = chars[rand() % sizeof(chars)];
		}
		
		clock_t begin = clock();
		string_matching_naive(text, n, pattern, 400);
		clock_t end = clock();
		double naive_runtime = (end - begin) / CLOCKS_PER_SEC;
		
		clock_t begin2 = clock();
		string_matching_kmp(text, n, pattern, 400);
		clock_t end2 = clock();
		double kmp_runtime = (end2 - begin2) / CLOCKS_PER_SEC;
		
		printf("Text length %d runtime- naive: %f, kmp: %f", n, naive_runtime, kmp_runtime);
	}
	return 0;
}