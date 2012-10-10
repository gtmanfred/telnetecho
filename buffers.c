/***
  This file is part of telnetecho.

  Copyright 2012 Daniel Wallace

  telnetecho is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  telnetecho is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with telnetecho; If not, see <http://www.gnu.org/licenses/>.
***/

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
