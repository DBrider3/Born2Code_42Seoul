/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:06:16 by dcho              #+#    #+#             */
/*   Updated: 2021/04/25 19:33:19 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

static int		map_check_basic(char c)
{
	if (ft_strchr(FULLFLAG, c) == 0)
		return (ERROR);
	return (NO_ERROR);
}

int				map_validation(t_map *m)
{
	int		i;
	int		j;

	i = 0;
	while (i < m->index)
	{
		j = 0;
		if (ft_strlen(m->map[i]) == 0)
			return (ERROR);
		while (m->map[i][j] != 0)
		{
			if (map_check_basic(m->map[i][j]))
				return (ERROR);
			if (m->map[i][j] != '1' && m->map[i][j] != ' ')
			{
				int x;
				x = ft_strlen(m->map[i]);
				// 배열에 접근을 해도 세그
				if (j >= x - 1 || j > 0 || i >= m->index - 1 || i > 0)
					return (ERROR);

				// x[33] = ' ' x[32] - 1 = '1'
				// 유효성 검사
				if (ft_strchr(FLAG, m->map[i - 1][j]) == 0 ||
				ft_strchr(FLAG, m->map[i + 1][j]) == 0 ||
				ft_strchr(FLAG, m->map[i][j - 1]) == 0 ||
				ft_strchr(FLAG, m->map[i][j + 1]) == 0)
					return (2);

				// if (i - 1 < 0 || )
				// if (!(m->map[i - 1][j]) || !(m->map[i + 1][j])
				// || !(m->map[i][j - 1]) || !(m->map[i][j + 1]))
				// 	return (ERROR);

			}
			j++;
		}
		i++;
	}
	return (NO_ERROR);
}
