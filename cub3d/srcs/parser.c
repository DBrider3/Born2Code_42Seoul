/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:12:38 by dcho              #+#    #+#             */
/*   Updated: 2021/04/25 02:54:37 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "get_next_line.h"

static int		input_r(char **input, t_options *op)
{
	int		i;

	if (check_size(input) != 2)
		return (-1);
	i = 0;
	while (i < 2)
	{
		op->r[i] = ft_atoi(*(input + i));
		i++;
	}
	return (1);
}

static int		input_file(char **input, t_options *op, int flag)
{
	if (check_size(input) != 1)
		return (-1);
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


	if (check_size(input) != 1)
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

static int		parse_identifier(char *line, t_options *op)
{
	char	**input;

	input  = ft_split(line, ' ');
	if (input[0] == 0)
		return (-1);
	if (ft_strncmp(input[0], "R", 1) == 0)
		input_r(&input[1], op);
	else if (ft_strncmp(input[0], "NO", 2) == 0)
		input_file(&input[1], op, 1);
	else if (ft_strncmp(input[0], "SO", 2) == 0)
		input_file(&input[1], op, 2);
	else if (ft_strncmp(input[0], "WE", 2) == 0)
		input_file(&input[1], op, 3);
	else if (ft_strncmp(input[0], "EA", 2) == 0)
		input_file(&input[1], op, 4);
	else if (ft_strncmp(input[0], "S", 1) == 0)
		input_file(&input[1], op, 5);
	else if (ft_strncmp(input[0], "F", 1) == 0)
		input_fc(&input[1], op, 'f');
	else if (ft_strncmp(input[0], "C", 1) == 0)
		input_fc(&input[1], op, 'c');
	else
		return (0);
	free_input(input);
	return (1);
}

int		parse_main(int fd, t_options *op)
{
	char	*line;
	int		ret;
	int		i;
	int		flag;

	init_identifier(op);
	new_map(&op->map);
	flag = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (check_identifier(*op) == 0)
			parse_identifier(line, op);
		else if (flag == 0)
		{
			i = 0;
			while (*(line + i))
			{
				if (*(line + i) == '1')
					flag = 1;
				i++;
			}
			if (flag == 1)
				add_map_line(op->map, ft_strdup(line));
		}
		else
			add_map_line(op->map, ft_strdup(line));
		free(line);
	}
	return (1);
}
