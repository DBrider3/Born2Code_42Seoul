/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:12:38 by dcho              #+#    #+#             */
/*   Updated: 2021/04/19 22:13:11 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "get_next_line.h"

static int		parse_indentifier(char *line, t_options *op)
{
	char	**input;
	char	*flag;

	input  = ft_split(line, ' ');
	flag = *input;
	input++;
	if (ft_strncmp(flag, "R", ft_strlen(flag)) == 0)
	{
		input_R();
	}
	else if (ft_strncmp(flag, "NO", ft_strlen(flag)) == 0)
	{

	}
	else if (ft_strncmp(flag, "SO", ft_strlen(flag)) == 0);
	else if (ft_strncmp(flag, "WE", ft_strlen(flag)) == 0);
	else if (ft_strncmp(flag, "EA", ft_strlen(flag)) == 0);
	else if (ft_strncmp(flag, "S", ft_strlen(flag)) == 0);
	else if (ft_strncmp(flag, "F", ft_strlen(flag)) == 0);
	else if (ft_strncmp(flag, "C", ft_strlen(flag)) == 0);
	else;
}


void	parse_main(int fd, t_options *op)
{
	char	*line;
	int		ret;
	char 	*flag;
	char	**input;
	int		i;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		input = ft_split(line, ' ');
		flag = *input;
		input++;
		i = 0;


		printf("%s\n", line);
		free(line);
	}
}
