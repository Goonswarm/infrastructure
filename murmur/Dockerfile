FROM debian
MAINTAINER Vincent Ambo <tazjin@gmail.com>

# Install all the depedencies
RUN apt-get update && apt-get install -y mumble-server

EXPOSE 64738
USER mumble-server

CMD /usr/sbin/murmurd -fg -ini /etc/murmur/murmur.ini
