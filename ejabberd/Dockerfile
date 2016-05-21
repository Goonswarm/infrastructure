FROM ubuntu:16.04
MAINTAINER Vincent Ambo <tazjin@gmail.com>

RUN apt-get update && apt-get install -y erlang-eldap ejabberd ejabberd-contrib

EXPOSE 5222 5269 5280

ADD start.sh /bin/ejabberd-start
RUN chmod +x /bin/ejabberd-start

# On container launch, concatenate the SSL certificate and ensure the data
# folder is owned by the correct user.
CMD /bin/ejabberd-start
