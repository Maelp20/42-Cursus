#!/bin/sh

#wait for MariaDB to start
sleep 10

if [ ! -e /var/www/wordpress/wp-config.php ]; then
	echo "Configuring wordpress..."
	echo "${SQL_DATABASE}<->${SQL_USER}<->${SQL_PASSWORD}"
	wp core download --allow-root
	rm -f /var/www/html/wp-config.php
	wp config create	--allow-root \
						--url=mpignet.42.fr \
						--dbname=$SQL_DATABASE \
						--dbuser=$SQL_USER \
						--dbpass=$SQL_PASSWORD \
						--dbhost=mariadb \
						--path='/var/www/wordpress'
sleep 4
wp core install     --allow-root --url='mpignet.42.fr' --title='inception' --admin_user='mpignet' --admin_password='1234' --admin_email='mpignet20@gmail.com' --path='/var/www/wordpress'
wp user create      --allow-root --role=author mpignet mpignet20@gmail.com --user_pass='1234' --path='/var/www/wordpress' >> /log.txt
fi

/usr/sbin/php-fpm7.3 -F