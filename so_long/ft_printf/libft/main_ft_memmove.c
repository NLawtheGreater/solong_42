#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
/*char arr[] = "doggy";
char	*src = &arr[3];
char	*dest = &arr[1];

//dest = src + 1;
dest = memmove(dest, src, 8);
write(1, dest, 22);
write(1, "\n", 1);
dest = src + 1;
dest = ft_memmove(dest, src, 8);

printf("%d\n",dest < src);*/

char *src = NULL;
char *dst = NULL;
dst = ft_memmove(dst, src, 8);
write(1, dst, 22);
write(1, "\n", 1);

}