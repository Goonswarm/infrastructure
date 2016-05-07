GoonSwarm Infrastructure
========================

This repository contains configuration files for our infrastructure and services,
hosted on Google's Container Engine using [Kubernetes][].

## nginx

The nginx web server is used as the main external entrypoint to our services.

Its configuration is stored in [nginx/conf](nginx/conf) and can be updated using
the `replace-config` script, assuming you have `kubectl` configured locally.

## Other information

TLS certificates are retrieved from Letsencrypt using DNS-based challenges, this is done using [k8s-acme][] and is currently not scheduled to happen automatically.

[Kubernetes]: http://kubernetes.io/
[k8s-acme]: https://git.tazj.in/tazjin/k8s-acme/
