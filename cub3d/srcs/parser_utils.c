/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:12:12 by dcho              #+#    #+#             */
/*   Updated: 2021/04/27 18:17:08 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_size(char **input)
{
	int		len;

	len = 0;
	while (*input++)
		len++;
	return (len);
}

int			free_inside(char **ptr)
{
	int		i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	return (0);
}

int			free_value(void *ptr)
{
	free(ptr);
	return (0);
}

int			check_identifier(t_options op)
{
	int		i;
	int		result;

	result = 1;
	i = 0;
	while (i < 2)
	{
		if (op.r[i++] == 0)
			result = 0;
	}
	if (op.no == 0 || op.so == 0 || op.we == 0 || op.ea == 0 || op.s == 0)
		result = 0;
	i = 0;
	while (i < 3)
	{
		if (op.f[i] == -1 || op.c[i] == -1)
			result = 0;
		i++;
	}
	return (result);
}
