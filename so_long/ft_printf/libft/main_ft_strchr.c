#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char test[7] = "bonjour";

    printf("%s\n", strchr("test", 'j'));
    printf("%s\n", ft_strchr("test", 'j'));
}
