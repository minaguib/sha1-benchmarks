BINS:=bench-openssl bench-nayuki bench-git
CFLAGS+=-O2 -Wall -Wextra -fomit-frame-pointer

all: $(BINS)

bench-openssl: LDLIBS+=-lcrypto
bench-openssl: bench-openssl.c bench.c

bench-nayuki: nayuki-sha1-fast-x8664.S bench-nayuki.c bench.c

bench-git: git-sha1.c bench-git.c bench.c

clean:
	-rm $(BINS)

