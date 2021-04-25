/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:12:38 by dcho              #+#    #+#             */
/*   Updated: 2021/04/25 19:19:04 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

int				parse_main(int fd, t_options *op)
{
	char	*line;
	int		ret;
	int		flag;

	init_identifier(op);
	if (new_map(&op->map))
		return (ERROR);
	flag = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (check_identifier(*op) == 0)
		{
			if (parse_identifier(line, op))
				return (free_value(line) + ERROR);
		}
		else if (flag == 0)
		{
			if (find_map(line, &flag, op))
				return (free_value(line) + ERROR);
		}
		else
		{
			if (add_map_line(op->map, ft_strdup(line)))
				return (free_value(line) + ERROR);
		}
		free(line);
	}
	return (NO_ERROR);
}
