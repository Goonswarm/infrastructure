FROM alpine
MAINTAINER Vincent Ambo <tazjin@gmail.com>

# Expose LDAP ports
EXPOSE 389 636

# Install OpenLDAP server
RUN apk update && apk add openldap openldap-clients ldapvi

# Add launch script
ADD start /usr/sbin/start-slapd
RUN chmod +x /usr/sbin/start-slapd

# Add slapd configuration
ADD slapd.conf /etc/openldap/slapd.conf

# Add schema
ADD goons.schema /etc/openldap/schema/goons.schema

# Verify configuration
RUN slaptest -u

# Run OpenLDAP
ENTRYPOINT ["/usr/sbin/start-slapd"]
