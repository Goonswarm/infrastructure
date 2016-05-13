BADS setup
==========

BADS is our Bad Account Database Syncer. See [its repository][] for more
information.

There is nothing special about the BADS setup and it has no volumes or other
things of note.

All operations it performs on LDAP are written to the logs.

## TODO

* Set up a log alert for repeated process terminations (this could be anything
  from MariaDB connections failing to the end of the world)
