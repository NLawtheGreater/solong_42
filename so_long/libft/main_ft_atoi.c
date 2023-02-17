#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

int	main(void)
{
	printf("lib atoi = %d\n",atoi("-192233720368547759000"));
	printf("lib atoi = %d\n",atoi("+192233720368547759000"));
	printf("lib atoi = %d\n",atoi("-47"));
	printf("lib atoi = %d\n",atoi("+47"));
	printf("ft_atoi = %d\n",ft_atoi("-192233720368547759000"));
	printf("ft_atoi = %d\n",ft_atoi("+192233720368547759000"));
	printf("ft_atoi = %d\n",ft_atoi("-47"));
	printf("ft_atoi = %d\n",ft_atoi("+47"));
}