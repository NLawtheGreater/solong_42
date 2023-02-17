#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
char *dst;
char *src;

dst = "bitch";
src = NULL;

//ft_memcpy(NULL, NULL, 3);
//write(1, , 5);
//write(1, "\n", 1);
ft_memcpy(dst, src, 3);
//write(1, dst, 5);
return (0);
}