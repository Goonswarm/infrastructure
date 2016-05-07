OpenLDAP setup
==============

This is a container image and Kubernetes configuration  for running OpenLDAP
with the custom `goons.schema`.

The schema includes fields for storing information about a user's character and
API credentials.

## Building

To build the image, simply run `docker build .` in this folder. The proper image
is built with the tag `gcr.io/goonswarm-1303/slapd` and can be pushed with the
`gcloud` tool.

## Local testing

If you are working with the `goon_auth` service locally you may want to run your
own LDAP server.

To do this, build the image and run it with port 389 exposed locally. You can
attach a Docker storage volume if you want to persist your test data. For
example, assuming you built the image with the `slapd` tag:

```
docker volume create --name slapd-data
docker run -v slapd-data:/var/lib/openldap/openldap-data -p 389:389 slapd
```

If you are starting the server for the first time you want to initialise it with
the default structure and set up your LDAP environment. Make sure you have the
OpenLDAP tools installed on your machine (check that `ldapadd` and `ldapmodify`
exist on your `$PATH`) and set up your `~/.ldaprc` like this:

```
BASE dc=tendollarbond,dc=com
BINDDN cn=admin,dc=tendollarbond,dc=com
HOST localhost:389
```

Then run `ldapadd -x -W -f initial.ldif` to initialise the structure.
