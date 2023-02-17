#include "ft_printf.h"
#include "libft.h"

/*1.If indicated width is less than length of converted string,
**	string remains the same
**2.If there is a minus sign, align left
**3.else align right
**4.check for allocation before returning*/
char	*conversion_width(char	*converted, t_format *f)
{
	char	*wconverted;

	if (f->width <= ft_strlen(converted))
		return (converted);
	if (f->minus)
		wconverted = align_left(converted, f);
	else
		wconverted = align_right(converted, f);
	if (!wconverted)
		return (NULL);
	return (wconverted);
}

static char	*align_right(char *cstr, t_format *f)
{
	char	*cfstr;
	int		i;
	int		j;
	int		plen;

	i = 0;
	j = 0;
	cfstr = ft_calloc(sizeof(char), f->width + 1);
	plen = my_printlen(cstr);
	if (!cfstr)
		return (NULL);
	if (cstr[0] == '-' && (f->zero && (!f->dot || f->pcs < 0)))
	{
		cfstr[i++] = cstr[j++];
		f->width++;
	}
	i = fill_prefix(cfstr, i, plen, f);
	if (plen == 1 && (f->dot && f->pcs == 0) && (*cstr == '0' || *cstr == 0))
		cfstr[i++] = ' ';
	while (j < plen)
		cfstr[i++] = cstr[j++];
	free(cstr);
	return (cfstr);
}
