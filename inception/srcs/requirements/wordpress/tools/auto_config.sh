#!/bin/sh

#wait for MariaDB to start
sleep 10

if [ ! -e /var/www/wordpress/wp-config.php ]; then
	echo "Configuring wordpress..."
	echo "${SQL_DATABASE}<->${SQL_USER}<->${SQL_PASSWORD}"
	wp config create	--allow-root \
						--url=mpignet.42.fr \
						--dbname=$SQL_DATABASE \
						--dbuser=$SQL_USER \
						--dbpass=$SQL_PASSWORD \
						--dbhost=mariadb \
						--path='/var/www/wordpress'
sleep 4
wp core install     --allow-root --url='mpignet.42.fr' --title='inception' --admin_user=$ADM_U --admin_password=$ADM_P --admin_email='mpignet' --path='/var/www/wordpress'
wp user create      --allow-root --role=author mpignet mpignet20@gmail.com --user_pass='1234' --path='/var/www/wordpress' >> /log.txt
fi

/usr/sbin/php-fpm7.3 -F