#include <stdio.h>
#include <systemd/sd-daemon.h>
#include <sys/socket.h>

#include "dbg.h"

#define PORT_NUM  24

int main(int argc, char *argv[]) {
	int fd, n;

	n = sd_listen_fds(1);
	check(n >= 0, "Failed to acquire sockets from systemd - %s",strerror(-n));

	fd = SD_LISTEN_FDS_START;

	printf("%d to %d\n", fd, PORT_NUM);

	return 0;

error:

	return n;

}
