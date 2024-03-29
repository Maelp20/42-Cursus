#!/bin/sh

#wait for MariaDB to start
sleep 10


if [ ! -e /var/www/wordpress/wp-config.php ]; then
	echo "Configuring wordpress..."
	echo "${SQL_DATABASE}<->${SQL_USER}<->${SQL_PASSWORD}"
	wp-cli.phar config create	--allow-root \
						--url=mpignet.42.fr \
						--dbname=$SQL_DATABASE \
						--dbuser=$SQL_USER \
						--dbpass=$SQL_PASSWORD \
						--dbhost=mariadb \
						--path='/var/www/wordpress'
sleep 4
wp-cli.phar core install     --allow-root --url=$SITE_URL --title=$SITE_TITLE --admin_user=$ADM_USER --admin_password=$ADM_PASSWORD --admin_email=$ADM_USER_EMAIL --path='/var/www/wordpress'
wp-cli.phar user create      --allow-root --role=author $WP_USER $WP_USER_EMAIL --user_pass=$WP_PASSWORD --path='/var/www/wordpress' >> /log.txt
fi

/usr/sbin/php-fpm7.3 -F