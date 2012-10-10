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
#ifndef _telnet_echo
#define _telnet_echo


#include <unistd.h>


ssize_t readbuffer(int fd, void *buf, size_t count);
ssize_t writebuffer(int fd, const void *buf, size_t count);


#endif
