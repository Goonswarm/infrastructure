FROM debian
MAINTAINER Vincent Ambo <tazjin@gmail.com>

RUN apt-get update && apt-get install -y ejabberd erlang-eldap

EXPOSE 5222 5280

CMD /usr/sbin/ejabberdctl live
