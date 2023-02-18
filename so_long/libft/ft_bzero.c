/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:13:17 by niclaw            #+#    #+#             */
/*   Updated: 2022/09/02 16:13:20 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	ind;

	ind = 0;
	if (n != 0)
	{
		while (ind < n)
		{
			*(char *)(s + ind) = 0;
			ind++;
		}
	}
}
/*for(ind = 0; ind < n; ++ind)
{
*(char*)(s + ind) = 0;
}*/