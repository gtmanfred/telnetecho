#ifndef _telnet_echo
#define _telnet_echo


#include <unistd.h>


ssize_t readbuffer(int fd, void *buf, size_t count);
ssize_t writebuffer(int fd, const void *buf, size_t count);


#endif
