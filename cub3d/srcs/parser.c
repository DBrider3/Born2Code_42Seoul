/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:12:38 by dcho              #+#    #+#             */
/*   Updated: 2021/04/22 17:47:14 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "get_next_line.h"

static int		input_r(char **input, t_options *op)
{
	int		i;

	i = 0;
	if (sizeof(input) / sizeof(int) != 2)
		return (-1);
	while (i < 2)
	{
		op->r[i] = ft_atoi(*(input + i));
		// if (op->r[i] < 0 || op->r[i] > 255)
		// 	return (-1);
		i++;
	}
	return (1);
}

static int		input_file(char **input, t_options *op, int flag)
{
	printf("%lu\n", sizeof(input));
	// if (sizeof(input) / sizeof(int) != 1)
	// 	return (-1);
	printf("%s\n", *input);
	if (flag == 1)
		op->no = ft_strdup(*input);
	else if (flag == 2)
		op->so = ft_strdup(*input);
	else if (flag == 3)
		op->we = ft_strdup(*input);
	else if (flag == 4)
		op->ea = ft_strdup(*input);
	else
		op->s = ft_strdup(*input);
	return (1);
}

static int		input_fc(char **input, t_options *op, char flag)
{
	char	**comma;
	int		i;


	if (sizeof(input) / sizeof(int) == 1)
		return (-1);
	comma = ft_split(*input, ',');
	i = 0;
	while (i < 3)
	{
		if (flag == 'f')
		{
			op->f[i] = ft_atoi(comma[i]);
			if (op->f[i] < 0 || op->f[i] > 255)
			return (-1);
		}
		else if (flag == 'c')
		{
			op->c[i] = ft_atoi(comma[i]);
			if (op->c[i] < 0 || op->c[i] > 255)
			return (-1);
		}
		i++;
	}
	i = 0;
	while (i < 3)
		free(comma[i++]);
	free(comma);
	return (0);
}
static int		parse_indentifier(char *line, t_options *op)
{
	char	**input;
	char	*flag;

	input  = ft_split(line, ' ');
	flag = *input;
	input++;
	if (flag == 0)
		return (-1);
	if (ft_strncmp(flag, "R", 1) == 0)
		input_r(input, op);
	else if (ft_strncmp(flag, "NO", 2) == 0)
		input_file(input, op, 1);
	else if (ft_strncmp(flag, "SO", 2) == 0)
		input_file(input, op, 2);
	else if (ft_strncmp(flag, "WE", 2) == 0)
		input_file(input, op, 3);
	else if (ft_strncmp(flag, "EA", 2) == 0)
		input_file(input, op, 4);
	else if (ft_strncmp(flag, "S", 1) == 0)
		input_file(input, op, 5);
	else if (ft_strncmp(flag, "F", 1) == 0)
		input_fc(input, op, 'f');
	else if (ft_strncmp(flag, "C", 1) == 0)
		input_fc(input, op, 'c');
	else
		return (0);
	// free(input);
	return (1);
}


void	parse_main(int fd, t_options *op)
// void	parse_main(int fd)
{
	char	*line;
	int		ret;
	// char 	*flag;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		// printf("[%s]\n", line);
		parse_indentifier(line, op);
		free(line);
	}
}
