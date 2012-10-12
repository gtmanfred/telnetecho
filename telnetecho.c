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

#include <stdlib.h>
#include <stdio.h>
#include <systemd/sd-daemon.h>
#include <sys/socket.h>
#include <string.h>
#include <err.h>
#include <pthread.h>

#include "buffers.h"

#define	MAXLEN		10


void *threader( void *d ) {
	char buffer[MAXLEN];
	int fd = (int)d;
	while ( 1 ) {
		readbuffer(fd, buffer, MAXLEN-1);
		writebuffer(fd, buffer, strlen(buffer));
	}
}

int main(int argc, char *argv[]) {
	int  fd, conn, rc, i;
	pthread_t thread[50];

	rc = sd_listen_fds(0);
	if (rc < 0) err(EXIT_FAILURE, "Failed to acquire sockets from systemd - %s",strerror(-rc));

	fd = SD_LISTEN_FDS_START;

	i = 0;
	
	while ( 1 ){

		conn = accept(fd, NULL, NULL);
		if (conn < 0) err(EXIT_FAILURE, "Failed to accept socket - %s", strerror(-conn));
		pthread_create(&(thread[i++]), NULL, threader, (void *)conn);

	}

	exit(0);

}
