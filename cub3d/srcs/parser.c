/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:12:38 by dcho              #+#    #+#             */
/*   Updated: 2021/04/20 19:37:18 by dcho             ###   ########.fr       */
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
		op->r[i] = ft_atoi(*input++);
		if (op->r[i] < 0 || op->r[i] > 255)
			return (-1);
	}
	return (1);
}

static int		input_file(char **input, char *fn)
{
	if (sizeof(input) / sizeof(int) != 1)
		return (-1);
	// .xpm 확장자 검사 노상관
	fn = input;

	// 문자열을 그냥 포인터에 주소로 넘겨줘도 될까?
	return (1);
}

static int		input_fc(char **input, unsigned int arr[3])
{
	// ',' 개수 중요, input 개수도 중요
	if (sizeof(input) / sizeof(int) != 3)
		return (-1);
	// 딱 서브젝트에 있는 형식으로만 받겠다는 마인드 오케이 그러면 split으로 처리 가능
	// split(',') 가능

}
static int		parse_indentifier(char *line, t_options *op)
{
	char	**input;
	char	*flag;

	input  = ft_split(line, ' ');
	flag = *input;
	input++;
	if (ft_strncmp(flag, "R", ft_strlen(flag)) == 0)
		input_r();
	else if (ft_strncmp(flag, "NO", ft_strlen(flag)) == 0)
		input_file();
	else if (ft_strncmp(flag, "SO", ft_strlen(flag)) == 0)
		input_file();
	else if (ft_strncmp(flag, "WE", ft_strlen(flag)) == 0)
		input_file();
	else if (ft_strncmp(flag, "EA", ft_strlen(flag)) == 0)
		input_file();
	else if (ft_strncmp(flag, "S", ft_strlen(flag)) == 0)
		input_file();
	else if (ft_strncmp(flag, "F", ft_strlen(flag)) == 0)
		input_fc();
	else if (ft_strncmp(flag, "C", ft_strlen(flag)) == 0)
		input_fc();
	else
		return (0);
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
		parse_indentifier(line, op);
		free(line);
	}
}
