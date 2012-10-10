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
#include <systemd/sd-daemon.h>

#include "buffers.h"

#define	MAXLEN		10

int main(int argc, char *argv[]) {
	int fd, rc;
	char buffer[MAXLEN];

	fprintf(stderr, "%s\n", "socket activation ftw!");
	rc = sd_listen_fds(0);
	if (rc < 0) err(EXIT_FAILURE, "Failed to acquire sockets from systemd - %s",strerror(-rc));

	fd = SD_LISTEN_FDS_START;
	
	while ( 1 ) {
		
		readbuffer(fd, buffer, MAXLEN-1);
		writebuffer(fd, buffer, strlen(buffer));

	}

	exit(0);

}
