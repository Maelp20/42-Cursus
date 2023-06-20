FROM debian:buster
RUN apt-get update -y
RUn apt-get upgrade -y
RUN apt-get install -y wget
RUN apt-get install -y php7.3 \
php7.3-cli \
php7.3-common \
php7.3-curl \
php7.3-mbstring \
php7.3-mysql \
php7.3-xml \
php7.3-fpm \
mariadb-client
RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www
RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz
RUN	chown -R root:root /var/www/wordpress

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

COPY /tools/auto_config.sh /tmp/auto_config.sh

RUN mkdir /run/php
ENTRYPOINT [ "sh", "/tmp/auto_config.sh" ]