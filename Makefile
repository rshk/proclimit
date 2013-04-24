CC = c99
CFLAGS = -g -Wall -O3
PROGNAME = proclimit

all: $(PROGNAME)

$(PROGNAME): $(PROGNAME).c
	$(CC) $< $(CFLAGS) -o $@

clean:
	rm -f $(PROGNAME)
