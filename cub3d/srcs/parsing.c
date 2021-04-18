/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:12:38 by dcho              #+#    #+#             */
/*   Updated: 2021/04/18 16:03:39 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "get_next_line.h"

void	parsing(int fd, t_options *op)
{
	char	*line;
	int		ret;
	char	**input;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == 'R')
		{
			input = ft_split(line, ' ');
			while (*input[0])
			{

				*input[0]++
			}
		}
		printf("%s\n", line);
		free(line);
	}
}
