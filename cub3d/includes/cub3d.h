/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:06:04 by dcho              #+#    #+#             */
/*   Updated: 2021/04/22 17:22:37 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define ERROR -1;

typedef struct		s_options
{
	unsigned int	r[2];
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	unsigned int	f[3];
	unsigned int	c[3];
	char			**map;
}					t_options;

void				parse_main(int fd, t_options *op);
// void				parse_main(int fd);


#endif
