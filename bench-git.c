#include "bench.h"
#include "git-sha1.h"

void benchmark(char *input, size_t input_len, unsigned int loops) {
	blk_SHA_CTX sha1;
	unsigned char hashout[20];

	for (unsigned int i=1; i<=loops; i++) {
		blk_SHA1_Init(&sha1);
		blk_SHA1_Update(&sha1, input, input_len);
		blk_SHA1_Final(hashout, &sha1);
	}

}
