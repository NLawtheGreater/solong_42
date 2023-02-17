/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:59:38 by niclaw            #+#    #+#             */
/*   Updated: 2022/10/28 21:24:29 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_format
{
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	int		dot;
	int		width;
	int		pcs;
	char	type;
}			t_format;

# define F_TYPE "cspdiuxX%"

int		ft_printf(const char *str, ...);
void	reset_format(t_format *f);
int		set_format1(char c, t_format *f);
char	*set_format2(char *format, char c, int i);
char	*conversion_type(va_list ptr, t_format *f);
char	*conversion_c(char c);
char	*conversion_s(char *s);
char	*conversion_p(size_t ptr);
char	*conversion_d(int d);
char	*conversion_u(unsigned int d);
char	*conversion_x(unsigned int nb, int is_upper);
char	*hexconvert(size_t nb, int is_upper);
int		hexlen(size_t nb);
#endif
