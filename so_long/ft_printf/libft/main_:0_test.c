#include "libft.h"

char *test(void)
{
	char	*ptr;

	ptr = malloc(5);
ptr[0] = '\0';
return (ptr);
}
int	main(void)
{
	test();
}