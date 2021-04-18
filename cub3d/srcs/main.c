/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:12:15 by dcho              #+#    #+#             */
/*   Updated: 2021/04/18 14:24:32 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"
#include "get_next_line.h"
#include "libft.h"

int		main(void)
{
	// void	*mlx;
	// void	*win;
	t_options	op;
	int			fd;

	if ((fd = open("map.cub", O_RDONLY)) == -1)
	{
		perror("Error\n");
		return (-1);
	}
	parsing(fd, &op);

	// if ((start = mlx_init()) == NULL);
	// if ((windows = mlx_new_window(start, 900, 900, "Test")) == NULL);
	// printf("%s\n",strerror(errno));
	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 900, 900, "Test");
	// mlx_loop(mlx);
	return (0);
}


