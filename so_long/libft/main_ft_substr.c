#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	*strsub;

	strsub = ft_substr(str, 400, 20);
	printf("%s\n",strsub);
	//ft_substr("tripouille", 100, 1);
	char * str2 = strdup("1");
	ft_substr(str2, 42, 42000000);
}