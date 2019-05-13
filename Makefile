BINS:=bench-openssl bench-git bench-nayuki
CFLAGS+=-O2 -Wall -fomit-frame-pointer

all: $(BINS)

bench.o: bench.h

bench-openssl.o: bench.h
bench-openssl: LDLIBS+=-lcrypto
bench-openssl: bench.o

git-sha1.o: git-sha1.h
bench-git.o: bench.h
bench-git: bench.o git-sha1.o

bench-nayuki.o: bench.h
bench-nayuki: bench.o nayuki-sha1-fast.o

clean:
	-rm $(BINS)
	-rm *.o
