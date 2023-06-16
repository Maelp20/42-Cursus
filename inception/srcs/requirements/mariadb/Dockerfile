FROM debian:buster
RUN apt-get update && apt-get upgrade && apt-get install mariadb-server -y
COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/mariadb.sh /tmp/mariadb.sh
ENTRYPOINT [ "sh", "/tmp/mariadb.sh" ]