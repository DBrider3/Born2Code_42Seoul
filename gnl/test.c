#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	char	*line;
	int		fd;
	int		ret;
	int		line_number;

	line_number = 0;
	fd = open("test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		printf("[line_number : %d], [ret : %d], [line : %s]\n", ++line_number, ret, line);
		free(line);
	}
	printf("[line_number : %d], [ret : %d], [line : %s]\n", ++line_number, ret, line);
	free(line);
	while (1)
	{

	}
	return (0);
}
