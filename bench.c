#include <time.h>
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include "bench.h"

int main(int argc, char ** argv) {
	char input[MAXLEN+1] = {0};

	setvbuf(stdout, NULL, _IONBF, 0);

	for (int len=1; len <= MAXLEN; len++) {
		input[len-1] = '0' + (len % 10);

		printf("Benchmarking input length %3d: ", len);
		int x=clock();
		benchmark(input, len);
		x = clock() - x;
		printf(
				"%d reps in %d ticks (%f/s)\n",
				LOOPS,
				x,
				(double)LOOPS / ((double)x/CLOCKS_PER_SEC)
		      );

	}
	return 0;
}

