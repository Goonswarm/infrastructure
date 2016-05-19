FROM ubuntu:16.04
MAINTAINER tazjin

# For some stupid reason Kaiwa's dependencies are broken in prod mode.
# Web developers v0v
ENV NODE_ENV dev
EXPOSE 8000

# Fetch Kaiwa's dependencies
RUN apt-get update
RUN apt-get install -y uuid-dev npm nodejs git

# Fetch Kaiwa
RUN git clone https://github.com/digicoop/kaiwa.git /opt/kaiwa && \
    ln -s /usr/bin/nodejs /usr/bin/node
WORKDIR /opt/kaiwa
RUN npm install

ADD config.json /opt/kaiwa/dev_config.json

CMD sed -i "s/REPLACE_ME/${KAIWA_SECRET}/g" dev_config.json && node server
