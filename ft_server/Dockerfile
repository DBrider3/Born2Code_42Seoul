# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 13:51:37 by dcho              #+#    #+#              #
#    Updated: 2021/04/08 16:48:55 by dcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	debian:buster
LABEL	MAINTAINER="dcho"

RUN		sed -i 's/deb.debian.org/ftp.kr.debian.org/g' etc/apt/sources.list && \
		apt-get update && apt-get upgrade -y && \
		apt-get install -y \
		nginx \
		mariadb-server \
		php-mysql \
		wget \
		openssl \
		vim \
		php-mbstring \
		php-zip \
		php-gd \
		php-xml \
		php-fpm

COPY	srcs/run.sh			./
COPY	srcs/default		tmp
COPY	srcs/config.inc.php	tmp
COPY	srcs/wp-config.php	tmp

# RUN ./run.sh

# CMD [ "bash", "run.sh" ]
CMD		bash run.sh
# ENTRYPOINT [ "/bin/bash" ]

EXPOSE	80 443
