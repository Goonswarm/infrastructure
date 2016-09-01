FROM node:6.5.0
MAINTAINER reluctant tazjin

EXPOSE 8000

# Fetch Kaiwa
RUN git clone https://github.com/ForNeVeR/kaiwa.git /opt/kaiwa --single-branch --branch master && \
    ln -s /usr/bin/nodejs /usr/bin/node
WORKDIR /opt/kaiwa
RUN npm install

# Bake config into static files
ADD config.json /opt/kaiwa/dev_config.json
RUN npm run compile

# Run in production mode (whatever that means)
ENV NODE_ENV prod
CMD sed -i "s/REPLACE_ME/${KAIWA_SECRET}/g" dev_config.json && npm start
