#include "string_matching.h"

int string_matching_kmp(char *text, int N, char* pattern, int M){
	int count = 0;
	int *overlap_list = overlap_array(pattern, M);	
	//printf("overlap function: ");
	//print_array(overlap_list,M);
	
	int n = 0;
	int m = 0;
	
	while (n < N) {
		if (text[n] == pattern[m]) {
			m++;
		}
		else if (m > 0) {
			n--;
			m = overlap_list[m - 1];
		}
		else {
			m = 0;
		}
		if (m == M) {
			count++;
			m = overlap_list[M - 1];
		}
		n++;
	}
	
	free(overlap_list);
	return count;
}
/*
int main() {
	char text[8] = {"ajfjeifl"};
	char pattern[4] = {"afei"};
	printf("%d", string_matching_kmp(text, 8, pattern, 4));
	return 0;
}
*/
	


 /*
    General computation of an overlap function in linear time:
    overlap function of position i is a length
    of the longest suffix in substring pattern[0:i]
    which is at the same time a prefix of pattern[0:i]
    parameters - pattern: string to be preprocessed, M: pattern length
    return: an array with the values of an overlap function for each pattern position
 */
int * overlap_array(char* pattern, int M){
	int *ol_list = calloc(M, sizeof(int));    

    int pos = 1;  // first is always zero
    while (pos < M){
        int ol_prev = ol_list[pos - 1];

        if (pattern[pos] == pattern[ol_prev])
            ol_list[pos] = ol_prev + 1;
        else {
            int found = 0;
            int j = ol_prev;
            int curr_overlap = ol_prev;
            while (!found && j >= 1){
                if (pattern[pos] == pattern[j]){
                    found = 1;
                    ol_list[pos] = curr_overlap + 1;
				}
                else {// try extend a smaller prefix - based on pattern [ol[pos-1]]
                    curr_overlap = ol_list[j-1];
                    j = ol_list[j-1];
				}
			}
            if (!found) { // compare with the first
                if (pattern[pos] == pattern[0])
                    ol_list[pos] = 1;
			}
		}
        pos++;
	}
    return ol_list;
}