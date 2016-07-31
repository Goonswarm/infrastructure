FROM ubuntu:16.04
MAINTAINER Vincent Ambo <tazjin@gmail.com>

RUN apt-get update && apt-get install -y gitit python

# Add Google Cloud SDK (for git credential helper)
ADD https://dl.google.com/dl/cloudsdk/channels/rapid/downloads/google-cloud-sdk-119.0.0-linux-x86_64.tar.gz /tmp/google-cloud-sdk.tar.gz
RUN tar xf /tmp/google-cloud-sdk.tar.gz -C /opt/ && /opt/google-cloud-sdk/install.sh

# Set locale (required by gitit)
RUN locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8

# Configure git & gitit
ADD gitconfig /root/.gitconfig
ADD gitit.conf /etc/gitit.conf
VOLUME /var/lib/gitit
WORKDIR /var/lib/gitit

EXPOSE 5000

ENTRYPOINT gitit -f /etc/gitit.conf
