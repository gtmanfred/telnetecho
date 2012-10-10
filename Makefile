PREFIX?=/usr
CFLAGS=-Wall -g -DNEBUG -I$(PREFIX)/include/systemd
LDFLAGS=-L$(PREFIX)/include/systemd
LDLIBS = -lsystemd-daemon
CC=gcc

all: telnetecho

clean:
	rm -f telnetecho

install:
	install -Dm755 telnetecho $(PREFIX)/bin/telnetecho
	install -Dm644 telnetecho.service /etc/systemd/system/telnetecho.service
	install -Dm644 telnetecho.socket /etc/systemd/system/telnetecho.socket

uninstall:
	rm -f $(PREFIX)/bin/telnetecho 
	rm -f /etc/systemd/system/telnetecho.service
	rm -f /etc/systemd/system/telnetecho.socket
