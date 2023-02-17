#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    char dest[20];
				char d[20];

        strlcpy(dest, "lorem ipsum dolor sit amet", 0);
		write(1, "\n", 1);
		write(1, dest, 15);
		write(1, "\n", 1);
        ft_strlcpy(d, "lorem ipsum dolor sit amet", 0);
		write(1, "\n", 1);
		write(1, dest, 15);
		write(1, "\n", 1);
        return (0);
}