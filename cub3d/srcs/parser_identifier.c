/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_identifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:27:52 by dcho              #+#    #+#             */
/*   Updated: 2021/04/25 16:39:19 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static int			separate_identifier(t_options *op, char **input)
{
	int		res;

	if (ft_strncmp(input[0], "R", 1) == 0)
		res = input_r(&input[1], op);
	else if (ft_strncmp(input[0], "NO", 2) == 0)
		res = input_file(&input[1], op, 1);
	else if (ft_strncmp(input[0], "SO", 2) == 0)
		res = input_file(&input[1], op, 2);
	else if (ft_strncmp(input[0], "WE", 2) == 0)
		res = input_file(&input[1], op, 3);
	else if (ft_strncmp(input[0], "EA", 2) == 0)
		res = input_file(&input[1], op, 4);
	else if (ft_strncmp(input[0], "S", 1) == 0)
		res = input_file(&input[1], op, 5);
	else if (ft_strncmp(input[0], "F", 1) == 0)
		res = input_fc(&input[1], (op->f));
	else if (ft_strncmp(input[0], "C", 1) == 0)
		res = input_fc(&input[1], (op->c));
	else
		res = ERROR;
	return (res);
}

int					input_r(char **input, t_options *op)
{
	int		i;

	if (check_size(input) != 2)
		return (ERROR);
	i = 0;
	while (i < 2)
	{
		op->r[i] = ft_atoi(*(input + i));
		i++;
	}
	return (NO_ERROR);
}

int					input_file(char **input, t_options *op, int flag)
{
	if (check_size(input) != 1)
		return (ERROR);
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
	return (NO_ERROR);
}

int					input_fc(char **input, int *op)
{
	char	**comma;
	int		i;

	if (check_size(input) != 1)
		return (ERROR);
	if (!(comma = ft_split(*input, ',')))
		return (ERROR);
	i = 0;
	while (i < 3)
	{
		*op = ft_atoi(comma[i]);
		if (*op < 0 || *op > 255)
		{
			free_inside(comma);
			return (ERROR);
		}
		op++;
		i++;
	}
	free_inside(comma);
	return (NO_ERROR);
}

int					parse_identifier(char *line, t_options *op)
{
	char	**input;
	int		res;

	input = ft_split(line, ' ');
	if (input[0] == 0)
	{
		free_inside(input);
		return (NO_ERROR);
	}
	res = separate_identifier(op, input);
	free_inside(input);
	return (res);
}
