#!/bin/bash

# phpmyadmin
wget -P Downloads https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-all-languages.tar.gz
mkdir -p /var/www/html/phpmyadmin && tar xvf /Downloads/phpMyAdmin-latest-all-languages.tar.gz --strip-components=1 -C /var/www/html/phpmyadmin
# sql setting
service mysql start
mysql < var/www/html/phpmyadmin/sql/create_tables.sql
# wordpress
wget -P Downloads https://wordpress.org/latest.tar.gz
tar xvf /Downloads/latest.tar.gz -C /var/www/html/ && rm -rf Downloads
# sql setting
mysql -e "create database wordpress"
mysql -e "grant all privileges on wordpress.* to dcho@localhost identified by '1234'"
mysql -e "flush privileges"
#
chown -R www-data:www-data /var/www/html/

# opensll
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/0=42Seoul/OU=Dcho/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/ && mv localhost.dev.key etc/ssl/private && chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key
mv tmp/default etc/nginx/sites-available/default && mv tmp/config.inc.php var/www/html/phpmyadmin/ && mv tmp/wp-config.php var/www/html/wordpress/

service nginx start && service php7.3-fpm start  && service mysql restart

bash

