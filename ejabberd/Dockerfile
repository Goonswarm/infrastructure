FROM debian
MAINTAINER Vincent Ambo <tazjin@gmail.com>

RUN apt-get update && apt-get install -y ejabberd erlang-eldap

EXPOSE 5222 5280

# On container launch, concatenate the SSL certificate and ensure the data
# folder is owned by the correct user.
CMD cat /etc/ssl/ejabberd/* > /etc/ssl/ejabberd/combined.pem && \
    chown -R ejabberd:ejabberd /var/lib/ejabberd &&\
    /usr/sbin/ejabberdctl live
