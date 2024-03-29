/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:46:32 by dcho              #+#    #+#             */
/*   Updated: 2021/02/03 00:35:25 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		exception(int read_size, char **backup, char **line)
{
	int			len;

	if (read_size == -1)
		return (-1);
	if ((len = newlinefind(*backup)) >= 0)
	{
		line_input(line, backup, len);
		return (1);
	}
	else
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
}

int		newlinefind(char *backup)
{
	int		i;

	i = 0;
	while (*(backup + i))
	{
		if (*(backup + i) == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		line_input(char **line, char **backup, int len)
{
	char		*tmp;

	(*backup)[len] = 0;
	*line = ft_strdup(*backup);
	tmp = ft_strdup(*backup + len + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*backup[1024];
	char			buf[BUFFER_SIZE + 1];
	int				read_size;
	int				len;
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (backup[fd] == NULL)
	{
		backup[fd] = ft_strdup("");
	}
	while ((len = newlinefind(backup[fd])) < 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			return (exception(read_size, &backup[fd], line));
		buf[read_size] = 0;
		tmp = backup[fd];
		backup[fd] = ft_strjoin(backup[fd], buf);
		free(tmp);
	}
	return (line_input(line, &backup[fd], len));
}
