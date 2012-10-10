#  This file is part of telnetecho.
#
#  Copyright 2012 Daniel Wallace
#
#  telnetecho is free software; you can redistribute it and/or modify it
#  under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation; either version 2.1 of the License, or
#  (at your option) any later version.
PREFIX?=/usr

install:
	install -Dm644 telnetecho@.service /etc/systemd/system/telnetecho@.service
	install -Dm644 telnetecho.socket /etc/systemd/system/telnetecho.socket

uninstall:
	rm -f /etc/systemd/system/telnetecho@.service
	rm -f /etc/systemd/system/telnetecho.socket
