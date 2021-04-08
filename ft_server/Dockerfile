# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 13:51:37 by dcho              #+#    #+#              #
#    Updated: 2021/04/08 14:55:22 by dcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster
MAINTAINER dcho

RUN sed -i 's/deb.debian.org/ftp.kr.debian.org/g' etc/apt/sources.list
RUN apt update && apt upgrade -y


RUN apt install -y nginx mariadb-server php-mysql wget vim php-{mbstring,zip,gd,xml,fpm} openssl
# apt install nginx mariadb-server php-mysql php-fpm wget vim php-{mbstring,zip,gd,xml} -y

COPY srcs/default etc/nginx/sites-available/default
# phpmyadmin
RUN wget -P Downloads https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-all-languages.tar.gz
RUN mkdir -p /var/www/html/phpmyadmin && tar xvf /Downloads/phpMyAdmin-latest-all-languages.tar.gz --strip-components=1 -C /var/www/html/phpmyadmin
COPY srcs/config.inc.php var/www/html/phpadmin/

RUN service mysql start
RUN mysql < var/www/html/phpmyadmin/sql/create_tables.sql

# wordpress
RUN wget -P Downloads https://wordpress.org/latest.tar.gz
RUN tar xvf /Downloads/latest.tar.gz -C /var/www/html/ && rm -rf Downloads
COPY srcs/wp-config.php var/www/html/wordpress/

RUN mysql -e "create database wordpress"
RUN mysql -e "grant all privileges on wordpress.* to dcho@localhost identified by '1234'"
RUN mysql -e "flush privileges"

RUN chown -R www-data:www-data /var/www/html/

# openssl
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/0=42Seoul/OU=Dcho/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
RUN mv localhost.dev.crt etc/ssl/certs/ && mv localhost.dev.key etc/ssl/private && chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key
RUN service nginx start && service php7.3-fpm start  && service mysql restart

EXPOSE 80 443
