phpBB setup
===========

This contains the setup for our forum software. The forum configuration in this
repository is minimal because phpBB likes to write configuration all over the
place (including its database) and configuring it includes frequently editing
files on disk.

For this reason phpBB is currently installed on a persistent storage volume and
the container image just sets up the base system.

## MariaDB

The MariaDB setup simply uses the unmodified official MariaDB Docker image with
persistent storage attached.

## TODO

We should move the theme setup into the container and maybe even the DB
configuration.
