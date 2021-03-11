#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(2, &c, 1);
}

int		main(void)
{
	// char c = 'c';

	// ft_putchar(c);

	int num = printf("%.9s", "Hello");
	printf("\n %d",num);
	return (0);
}
