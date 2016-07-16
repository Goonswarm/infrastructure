#!/bin/sh
set -ue

# Ejabberd start script
echo "Preparing ejabberd for startup..."

# Combine SSL certs into one file
cat /etc/ssl/ejabberd/* > /tmp/ejabberd.pem

# Ensure correct ownership for database and configuration
chown -R ejabberd:ejabberd /var/lib/ejabberd
chown -R ejabberd:ejabberd /etc/ejabberd
chown -R ejabberd:ejabberd /tmp/ejabberd.pem

# Set up pid file folder
mkdir -p /run/ejabberd
chown -R ejabberd:ejabberd /run/ejabberd

# Start ejabberd as ejabberd user
echo "Starting ejabberd"
su ejabberd -c 'ejabberdctl --default /etc/ejabberd/ejabberdctl.cfg foreground'
