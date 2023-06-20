#!/bin/sh

#create database and user for wordpress
service mysql start
sleep 5
echo "hello"
mysql -e "CREATE DATABASE IF NOT EXISTS ${SQL_DATABASE};"
echo "2"
mysql -e "CREATE USER IF NOT EXISTS ${SQL_USER}@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
echo "3"
mysql -e "GRANT ALL PRIVILEGES ON ${SQL_DATABASE}.* TO ${SQL_USER}@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
echo "4"
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
echo "5"
mysql -e "FLUSH PRIVILEGES;"
echo $SQL_ROOT_PASSWORD
mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown
echo "6"
exec mysqld_safe