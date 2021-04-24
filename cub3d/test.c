#include <stdio.h>
#include <string.h>

int main(void)
{
    if (printf("1\n") && printf("2\n"))
        printf("3\n");
    return (0);
}
