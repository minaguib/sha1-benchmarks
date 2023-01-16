#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include "bench.h"

int main(int argc, char ** argv) {
	char input[MAXLEN+1] = {0};
	double rate;
	int interactive = isatty(fileno(stdout));

	setvbuf(stdout, NULL, _IONBF, 0);

	for (int len=1; len <= MAXLEN; len++) {
		input[len-1] = '0' + (len % 10);

		if (interactive) {
			printf("Benchmarking input length %3d: ", len);
		}
		int x=clock();
		benchmark(input, len, LOOPS);
		x = clock() - x;
		rate = (double)LOOPS / ((double)x/CLOCKS_PER_SEC);
		if (interactive) {
			printf(
					"%d reps in %d ticks (%.f/s)\n",
					LOOPS,
					x,
					rate
			      );
		}
		else {
			printf("%d,%.f\n", len, rate);
		}

	}
	return 0;
}

