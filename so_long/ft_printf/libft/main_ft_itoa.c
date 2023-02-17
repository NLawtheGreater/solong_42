#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main(void)
{
	char	*res;

	printf("%s\n",ft_itoa(-5));
	printf("%s\n",ft_itoa(-15));
	printf("%s\n",ft_itoa(-698));
	printf("%s\n",ft_itoa(8));
	printf("%s\n",ft_itoa(10));
	printf("%s\n",ft_itoa(698));

	res = ft_itoa(-5);
	ft_print_result(res);
	ft_print_result("\n");
	free(res);
	res = ft_itoa(-15);
	ft_print_result(res);
	ft_print_result("\n");
	free(res);
	res = ft_itoa(-698);
	ft_print_result(res);
	ft_print_result("\n");
	free(res);
	res = ft_itoa(8);
	ft_print_result(res);
	ft_print_result("\n");
	free(res);
	res = ft_itoa(10);
	ft_print_result(res);
	ft_print_result("\n");
	free(res);
	res = ft_itoa(698);
	ft_print_result(res);
	ft_print_result("\n");
	free(res);
}