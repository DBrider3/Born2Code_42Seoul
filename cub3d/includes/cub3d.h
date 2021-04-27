/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:06:04 by dcho              #+#    #+#             */
/*   Updated: 2021/04/27 18:19:27 by dcho             ###   ########.fr       */
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
#define FULLFLAG " 012EWSN"
#define FLAG "012EWSN"

typedef struct		s_map
{
	char	**map;
	int		index;
	int		size;
	int		max_col;
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
int					parse_identifier(char *line, t_options *op);
int					input_fc(char **input, int *op);
int					input_file(char **input, t_options *op, int flag);
int					input_r(char **input, t_options *op);
int					check_size(char **input);
int					free_inside(char **input);
int			 		free_value(void *ptr);
int					check_identifier(t_options op);
int					new_map(t_map **m);
int					add_map_line(t_map *m, char *line);
void				del_map(t_map *m);
int					find_map(char *line, int *flag, t_options *op);
int					map_check_main(t_map *m);

#endif
