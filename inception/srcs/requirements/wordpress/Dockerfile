FROM debian:buster
RUN apt-get update -y
RUn apt-get upgrade -y
RUN apt-get install -y wget
RUN apt-get install -y php7.3 \
php7.3-fpm \
php7.3-mysql \
mariadb-client
RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www
RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz
RUN	chown -R root:root /var/www/wordpress

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/

COPY /tools/auto_config.sh /tmp/auto_config.sh
RUN chmod +x /tmp/auto_config.sh

RUN mkdir -p /run/php /var/log/php7 /var/www/html/wordpress
ENTRYPOINT [ "sh", "/tmp/auto_config.sh" ]