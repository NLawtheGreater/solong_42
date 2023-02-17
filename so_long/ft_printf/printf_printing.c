/*#include "printf.h"


1. check width ....(*check*)
**2. write character
**3. return length printed
int	print_char(char *converted, int w)
{
	int		i;

	i = 0;
	if (w == 0)
		w = 1;
	while (i < w)
	{
		write(1, &converted[i], 1);
		i++;
	}
	return (i);
}


*skip dot/pcs/width for now
**1. print string with putstr
**2.return length printed
int	print_str(char *converted, t_format *f)
{
	int		n;


	n = ft_strlen(converted);
	
		ft_putstr_fd(converted, 1);
	return (n);
}
print empty width
int	printf_empty(char *converted, t_format *f)
{
	int		n;

	n = 0;
	if (converted[0] == 0 && f->width)
		n = print_char(" ", 1);
	else if (converted[0] == 0 && f->dot && f->pcs < 0)
		n = print_char(S_EMPTY, S_EMPTY_L);
	else if (ft_strlen(converted) > 0 && f->width > 0)
	{
		while (n++ < f->width)
			ft_putchar_fd(' ', 1);
		n--;
	}
	return (n);
}*/
