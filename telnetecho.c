#include <stdio.h>
#include <stdlib.h>
#include <systemd/sd-daemon.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>

#include "dbg.h"
#include "helper.h"

#define	PORT_NUM	24
#define	MAXLEN		500

int main(int argc, char *argv[]) {
	int fd, rc, conn;

	fprintf(stderr, "%s\n", "socket activation ftw!");
	rc = sd_listen_fds(0);
	check(rc == 0 , "Failed to acquire sockets from systemd - %s",strerror(-rc));

	fd = SD_LISTEN_FDS_START;

	while ( 1 ) {

		struct sockaddr sa;
		socklen_t sa_len;

		conn = accept(fd, &sa, &sa_len);
		check( conn == 0, "ECHOSERV: Error calling accept()\n");

		check(close(conn) == 0, "ECHOSERV: Error calling close()\n");
	}

	return 0;

error:

	exit(rc);

}
