#include "buffers.h"
#include <sys/socket.h>

ssize_t readbuffer(int fd, void *buf, size_t count) {
	ssize_t n; 
	ssize_t rc;
	char    letter;
	char    *buffer;

	buffer = buf;

	for ( n = 1; n < count; n++ ) {

		if ( (rc = read(fd, &letter, 1)) == 1 ) {
			*buffer++ = letter;
			if ( letter == '\n' )
				break;
		}

	}

	*buffer = 0;
	return n;
}

ssize_t writebuffer(int fdd, const void *buf, size_t remain) {
	ssize_t     nwritten;
	const char *buffer;

	buffer = buf;

	while ( remain > 0 ) {
		nwritten = write(fdd, buffer, remain);
		remain -= nwritten;
		buffer += nwritten;
	}

	return 0;
}
