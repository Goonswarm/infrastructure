GoonSwarm Infrastructure
========================

This repository contains configuration files for our infrastructure and services,
hosted on Google's Container Engine using [Kubernetes][].

## nginx

The nginx web server is used as the main external entrypoint to our services,
meaning that it currently tunnels both HTTP(S) as well as generic TCP traffic.

Its configuration is stored in [nginx/conf](nginx/conf) and can be updated using
the `replace-config` script, assuming you have `kubectl` configured locally.

*Note: After the Google Cloud trial we will be able to have multiple external
IPs, at which point nginx will not tunnel TCP traffic anymore.*

## slapd

The OpenLDAP server is used for user and group information. It is set up with
the default core LDAP schemas and an additional one for our custom attributes.

Check out the slapd folder for more information.

## DNS

The zone files for our DNS zone `tendollarbond.com` is contained in the DNS
folder, check the folder for more information.

## Murmur

Murmur is the server component of the Mumble project. This folder contains
the base setup and a terrifying Python blob from some other website that can
delegate authentication to LDAP.

## Ejabberd

The Erlang Jabber server, this provides our XMPP service.

## Forum

phpBB forum setup. Check the folder for more information.

## Other information

TLS certificates are retrieved from Letsencrypt using DNS-based challenges, this is done using [k8s-acme][] and is currently not scheduled to happen automatically.

[Kubernetes]: http://kubernetes.io/
[k8s-acme]: https://git.tazj.in/tazjin/k8s-acme/
