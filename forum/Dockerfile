# Call me if somebody writes a non-terrible forum software

# phpBB writes files literally all over the place and I have no intention of
# playing Pokemon with it, therefore this image only contains the base
# dependencies for phpBB and the rest goes into a volume.

FROM php:5.6-apache

RUN apt-get update && apt-get install -y bzip2 imagemagick php5-mysqlnd && \
    docker-php-ext-install mysqli
