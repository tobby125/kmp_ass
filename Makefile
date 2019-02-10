CC = gcc
CFLAGS = -Wall -std=c99

all: test test_performance

string_matching_naive.o: string_matching_naive.c string_matching.h 
	$(CC) $(CFLAGS) -c string_matching_naive.c

string_matching_kmp.o: string_matching_kmp.c string_matching.h
	$(CC) $(CFLAGS) -c string_matching_kmp.c
	
test.o: test.c string_matching.h
	$(CC) $(CFLAGS) -c test.c
	
test_performance.o: test_performance.c string_matching.h
	$(CC) $(CFLAGS) -c test_performance.c
	
test: string_matching_naive.o string_matching_kmp.o test.o
	$(CC) $(CFLAGS) -o test string_matching_naive.o string_matching_kmp.o test.o
	
test_performance: string_matching_naive.o string_matching_kmp.o test_performance.o
	$(CC) $(CFLAGS) -o test_performance string_matching_naive.o string_matching_kmp.o test_performance.o
	
clean:
	rm *.o test test_performance
