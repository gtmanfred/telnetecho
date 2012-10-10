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
