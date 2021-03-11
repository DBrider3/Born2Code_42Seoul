#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_options{
	char	flag;
	int		width;
	int		precision;
	char	format;
} t_options;

static void		specifier();

int		ft_printf(const char *fmt, ...)
{
	t_options	sp;
	va_list		ap;
	int			i;
	va_start(ap, fmt);
	while (*fmt)
	{

		if (*fmt == '%')
		{

		}
		write(1, fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (0);
}

int		main(void)
{
	ft_printf("Hello World! %d\n", 12);
}

