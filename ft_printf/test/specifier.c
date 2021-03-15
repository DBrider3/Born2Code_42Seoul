#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(2, &c, 1);
}

static unsigned	ft_abs(int n)
{
	return (n > 0 ? n : -n);
}
int		main(void)
{
	char c = 'c';

	// ft_putchar(c);

	// int num = printf("%.-1d", 50);
	// int num = printf("%.0s",-1, "Hello");
	// int num = printf("%.*s",1, "");
	// int num = printf("%.-1u", 10);
	// int num = printf("%.*d",-1, 10);
	// int num = printf("%.*x",0, 0);

	// flags
	// int num = printf("%-10s", "Hello");
	// int num = printf("%00010%");
	// int num = printf("%000-*d",-12,15);

	// width

	// int num = printf("%-*c",-10,'c');
	int width = -7;
	int	precision = 9;
	// int num = printf("%0*d", width,-1234);
	// int num = printf("%0*.*d",width, precision,1234);
	// int num = printf("%0*.*d",width, precision,12345);
	int num = printf("%*.*s",width, precision,"abcde");
	printf("\nlength : %d",num);
	printf("\n---------------------------------");
	printf("\nwidth : %d\nprecision : %d\n", width, precision);
	if (num == (int)ft_abs(width)) printf("length == width\n");
	else if (num == (int)ft_abs(precision)) printf("length == precision\n");
	return (0);
}
