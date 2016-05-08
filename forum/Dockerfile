# Call me if somebody writes a non-terrible forum software

# phpBB writes files literally all over the place and I have no intention of
# playing Pokemon with it, therefore this image only contains the base
# dependencies for phpBB and the rest goes into a volume.

FROM php:5.6-apache

RUN apt-get update && \
    apt-get install -y bzip2 imagemagick php5-mysqlnd libldap2-dev && \
    ln -fs /usr/lib/x86_64-linux-gnu/libldap.so /usr/lib && \
    docker-php-ext-install mysqli && \
    docker-php-ext-install ldap
