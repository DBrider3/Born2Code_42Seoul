/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:06:04 by dcho              #+#    #+#             */
/*   Updated: 2021/04/25 02:35:51 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define ERROR -1
#define NO_ERROR 0
#define INITAIL_SIZE 8

typedef struct		s_map
{
	char	**map;
	int		index;
	int		size;
}					t_map;

typedef struct		s_options
{
	unsigned int	r[2];
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				f[3];
	int				c[3];
	t_map			*map;
}					t_options;

int					parse_main(int fd, t_options *op);
void				init_identifier(t_options *op);
int					check_size(char **input);
void				free_input(char **input);
int					check_identifier(t_options op);
int					new_map(t_map **m);
int		expand_map(t_map *m);
int		add_map_line(t_map *m, char *line);
void		del_map(t_map *m);
// int					parse_map_main(char *line, t_options *op, int index);

#endif
