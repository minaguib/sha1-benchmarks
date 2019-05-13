#include "bench.h"
#include "git-sha1.h"

void benchmark(char *input, size_t input_len) {
	blk_SHA_CTX sha1;
	unsigned char hashout[20];

	for (int i=1; i<=LOOPS; i++) {
		blk_SHA1_Init(&sha1);
		blk_SHA1_Update(&sha1, input, input_len);
		blk_SHA1_Final(hashout, &sha1);
	}

}
