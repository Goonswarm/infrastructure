BADS setup
==========

BADS is our Bad Account Database Syncer. See [its repository][] for more
information.

BADS needs the password for the MariaDB user that it should use to manage the
forums database, this is currently supplied in the form of a Kubernetes config
map.

You can create such a map with
`kubectl create configmap bads-config --from-literal=mariadb.password=SuperSecretPW`.

All operations it performs on LDAP are written to the logs.

## Versioning

BADS is continually built by Travis.CI and before recreating the container you
should check for the current commit hash.

Images are built as `gcr.io/goonswarm-1303/bads:$(git rev-parse --short HEAD)`.

## Deployment

Use the `deploy.sh` script in the BADS repository on a checkout of the version
you want to deploy.

You need to ensure that the version built successfully on Travis.CI

## TODO

* Set up a log alert for repeated process terminations (this could be anything
  from MariaDB connections failing to the end of the world)
