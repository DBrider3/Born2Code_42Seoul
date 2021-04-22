/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:12:15 by dcho              #+#    #+#             */
/*   Updated: 2021/04/22 17:28:53 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"
#include "get_next_line.h"

int		main(int argc, char *argv[])
{
	// void	*mlx;
	// void	*win;
	t_options	op;
	int			fd;
	// char	*line;
	// int		ret;

	if (argc != 2)
		printf("error\n");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror("Error\n");
		return (-1);
	}
	// while ((ret = get_next_line(fd, &line)) > 0)
	// {
	// 	printf("[%s]\n", line);
	// 	free(line);
	// }

	parse_main(fd, &op);
	printf("R: %d %d\n",op.r[0], op.r[1]);
	printf("NO: %s\n",op.no);
	printf("SO: %s\n",op.so);
	printf("WE: %s\n",op.we);
	printf("EA: %s\n",op.ea);
	printf("S: %s\n",op.s);
	printf("F: %d,%d,%d\n",op.f[0], op.f[1], op.f[2]);
	printf("C: %d,%d,%d\n",op.c[0], op.c[1], op.c[2]);
	// if ((start = mlx_init()) == NULL);
	// if ((windows = mlx_new_window(start, 900, 900, "Test")) == NULL);
	// printf("%s\n",strerror(errno));
	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 900, 900, "Test");
	// mlx_loop(mlx);
	return (0);
}


