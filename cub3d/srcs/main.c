/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:12:15 by dcho              #+#    #+#             */
/*   Updated: 2021/05/06 21:45:40 by dcho             ###   ########.fr       */
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

	if (argc != 2)
	{
		printf("Error\n: argument number is not appropriate");
		return (-1);
	}
	// else if (argc == 3)
	// {
	// 	fd = open(argv[1], O_)
	// }
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror("Error\n");
		return (-1);
	}
	if (parse_main(fd, &op) == ERROR)
	{
		printf("Error\n: not the correct parsing\n");
		return (-1);
	}
	printf("R: %d %d\n",op.r[0], op.r[1]);
	printf("NO: %s\n",op.no);
	printf("SO: %s\n",op.so);
	printf("WE: %s\n",op.we);
	printf("EA: %s\n",op.ea);
	printf("S: %s\n",op.s);
	printf("F: %d,%d,%d\n",op.f[0], op.f[1], op.f[2]);
	printf("C: %d,%d,%d\n",op.c[0], op.c[1], op.c[2]);

	int i = 0;
	while (i < op.map->index)
	{
		printf("%s\n", op.map->map[i]);
		i++;
	}
	printf("[%d]\n",map_check_main(op.map));
	del_map(op.map);
	// if ((mlx = mlx_init()) == NULL);
	// if ((win = mlx_new_window(start, 900, 900, "Test")) == NULL);
	// printf("%s\n",strerror(errno));
	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 900, 900, "Test");
	// mlx_loop(mlx);
	free(op.no);
	free(op.so);
	free(op.we);
	free(op.ea);
	free(op.s);
	close(fd);
	return (0);
}


