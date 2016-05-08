FROM debian
MAINTAINER Vincent Ambo <tazjin@gmail.com>

# Install all the depedencies
RUN apt-get update && \
    apt-get install -y mumble-server python-ldap python-zeroc-ice

# Add Murmur configuration
ADD murmur.ini /etc/mumble-server.ini

# Add LDAP authentication script
ADD ldap /opt/mumble-ldap
RUN ln -s /usr/share/slice/Murmur.ice /opt/mumble-ldap/Murmur.ice && \
    chmod +x /opt/mumble-ldap/LDAPauth.py

WORKDIR /opt/mumble-ldap/
EXPOSE 64738
USER mumble-server
CMD /usr/sbin/murmurd -fg -ini /etc/mumble-server.ini
