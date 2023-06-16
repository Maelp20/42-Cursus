#!/bin/sh

#create database and user for wordpress
service mysql start
mysql -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;" -p$SQL_ROOT_PASSWORD
mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';" -p$SQL_ROOT_PASSWORD
mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';" -p$SQL_ROOT_PASSWORD
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';" -p$SQL_ROOT_PASSWORD
mysql -e "FLUSH PRIVILEGES;" -p$SQL_ROOT_PASSWORD
mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown
exec mysqld_safe