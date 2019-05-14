#include "bench.h"
#include <openssl/sha.h>

void benchmark(char *input, size_t input_len, unsigned int loops) {
	SHA_CTX sha1;
	unsigned char md[SHA_DIGEST_LENGTH];

	for (unsigned int i=1; i<=loops; i++) {
		SHA1_Init(&sha1);
		SHA1_Update(&sha1, input, input_len);
		SHA1_Final(md, &sha1);
	}

}
