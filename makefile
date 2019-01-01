CC = gcc

CFLAGS =  -Wall\
          -Iinclude\

SOURCES = src/cCONFIG.c

example = cCONFIG_example

all: $(example)

$(example): example/example.c $(SOURCES)
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	rm $(example)
