/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 22:35:39 by dcho              #+#    #+#             */
/*   Updated: 2021/04/25 02:44:26 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

// int		parse_map_main(char *line, t_options *op, int index)
// {
// 	int		j;

// 	j = 0;
// 	if (!(op->map[index] = malloc(sizeof(char) * (ft_strlen(line) + 1))))
// 		return (-1);
// 	while (*line)
// 	{
// 		if (*line != ' ' || *line != '1' || *line != '2' || *line != '0' ||
// 			*line != 'N' || *line != 'S' || *line != 'E' || *line != 'W')
// 			return (-1);
// 		op->map[index][j++] = *line++;
// 	}
// 	return (1);
// }

int		new_map(t_map **m)
{
	if (!(*m = malloc(sizeof(t_map))))
		return (-1);
	if (!((*m)->map = malloc(sizeof(char*) * INITAIL_SIZE)))
		return (-1);
	(*m)->index = 0;
	(*m)->size = INITAIL_SIZE;
	return (0);
}

int		expand_map(t_map *m)
{
	char	**tmp;

	tmp = m->map;
	m->size *= 2;
	if (!(m->map = malloc(sizeof(char*) * m->size)))
	{
		free(tmp);
		return (-1);
	}
	int i = 0;
	while (i < m->index)
	{
		m->map[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (0);
}
int		add_map_line(t_map *m, char *line)
{
	if (m->index == m->size && expand_map(m))
		return (ERROR);
	m->map[m->index] = line;
	m->index++;
	return (NO_ERROR);
}

void		del_map(t_map *m)
{
	int		i;

	i = 0;
	while (i < m->index)
		free(m->map[i++]);
	free(m->map);
	free(m);
}
