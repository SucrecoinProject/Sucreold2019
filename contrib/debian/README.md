
Debian
====================
This directory contains files used to package sucrecoind/sucrecoin-qt
for Debian-based Linux systems. If you compile sucrecoind/sucrecoin-qt yourself, there are some useful files here.

## sucrecoin: URI support ##


sucrecoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install sucrecoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your sucrecoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/sucrecoin128.png` to `/usr/share/pixmaps`

sucrecoin-qt.protocol (KDE)

