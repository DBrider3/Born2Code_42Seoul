#include "mlx.h"
#include "cub3d.h"
// #include "get_next_line.h"

int		main(void)
{
	void	*mlx;
	void	*win;

	// if ((start = mlx_init()) == NULL);
	// if ((windows = mlx_new_window(start, 900, 900, "Test")) == NULL);

	// char	*line;
	// int		ret;
	// int		fd;

	// if ((fd = open("map.cub", O_RDONLY)) == -1)
	// {
	// 	perror("Error\n");
	// 	return (-1);
	// }
	// while ((ret = get_next_line(fd, &line)) > 0)
	// {
	// 	if (line[0] == 'R')
	// 	{

	// 	}
	// 	printf("%s\n", line);
	// 	free(line);
	// }

	// printf("%s\n",strerror(errno));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 900, 900, "Test");
	mlx_loop(mlx);
	return (0);
}


