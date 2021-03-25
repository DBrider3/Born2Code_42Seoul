#include "../includes/ft_printf.h"
#define PRINT "%p\n"
// #define OP "123456"

// int		main(void)
// {
// 	char 	*s;
// 	int		i;

// 	// i = ft_printf("%0*.*d",1,2, 7);
// 	i = ft_printf(PRINT,s);
// 	printf("%d\n",i);
// 	i = printf(PRINT,s);
// 	printf("%d\n",i);
// }

int main(void)
{
    char c;
    char *s;
    // char *p;
    int d;
    int i;
    // unsigned int u;
    unsigned int x;
    unsigned int X;

    int ret;
    int myret;

    // p = &c;
    c = 'a';
    s = "this is string";
    d = (int)2147483648;
    i = -20;
    // u = 4294967295;
    x = 0xfF1;
    X = 0xfF1;

    // ret = printf("org percent: [%5d]\n",5);
    // printf("{ret: %d}\n", ret);
    // myret = ft_printf("_my percent: [%5d]\n",5);
    // printf("{myret: %d}\n", myret);
    // printf("\n");

    // ret = printf("org c: %c\n", c);
    // printf("{ret: %d}\n", ret);
    // myret = ft_printf("_my c: %c\n", c);
    // printf("{myret: %d}\n", myret);
    // printf("\n");

    // ret = printf("org s: %s\n", s);
    // printf("{ret: %d}\n", ret);
    // myret = ft_printf("_my s: %s\n", s);
    // printf("{myret: %d}\n", myret);
    // printf("\n");

    // ret = printf("org p: %p\n", p);
    // printf("{ret: %d}\n", ret);
    // myret = ft_printf("_my p: %p\n", p);
    // printf("{myret: %d}\n", myret);
    // printf("\n");

    ret = printf("org d: %d\n", d);
    printf("{ret: %d}\n", ret);
    myret = ft_printf("_my d: %d\n", d);
    printf("{myret: %d}\n", myret);
    printf("\n");

    // ret = printf("org i: %i\n", i);
    // printf("{ret: %d}\n", ret);
    // myret = ft_printf("_my i: %i\n", i);
    // printf("{myret: %d}\n", myret);
    // printf("\n");

    // ret = printf("org u: %u\n", u);
    // printf("{ret: %d}\n", ret);
    // myret = ft_printf("_my u: %u\n", u);
    // printf("{myret: %d}\n", myret);
    // printf("\n");

    // ret = printf("org x: %x\n", x);
    // printf("{ret: %d}\n", ret);
    // myret = ft_printf("_my x: %x\n", x);
    // printf("{myret: %d}\n", myret);
    // printf("\n");

    // ret = printf("org X: %X\n", X);
    // printf("{ret: %d}\n", ret);
    // myret = ft_printf("_my X: %X\n", X);
    // printf("{myret: %d}\n", myret);
    // printf("\n");

    return (0);
}


// printf("\n\tflag:[%c]\n\
	// width: [%d]\n\
	// precision: [%d]\n\
	// type: [%c]\n\
	// sign: [%d]\n\
	// space: [%d]\n\
	// zero: [%d]\n", options.flag, options.width, options.precision, options.type,
	// options.sign, options.space, options.zero);
