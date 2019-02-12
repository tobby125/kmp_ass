#include <stdio.h>
#include <sys/time.h>
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
		
		struct timeval begin, end, begin2, end2;
		
		gettimeofday (&begin, NULL);
		string_matching_naive(text, n, pattern, 400);
		gettimeofday (&end, NULL);
		double naive_runtime = (end.tv_sec - begin.tv_sec)
           + (end.tv_usec - begin.tv_usec) / 1000000.;
		
		gettimeofday (&begin2, NULL);
		string_matching_kmp(text, n, pattern, 400);
		gettimeofday (&end2, NULL);
		double kmp_runtime = (end2.tv_sec - begin2.tv_sec)
           + (end2.tv_usec - begin2.tv_usec) / 1000000.;
		
		printf("Text length %d runtime- naive: %f, kmp: %f\n", n, naive_runtime, kmp_runtime);
		free(text);
		free(pattern);
	}
	return 0;
}