/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_treatment_oxx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 09:10:11 by glecler           #+#    #+#             */
/*   Updated: 2019/09/04 17:28:37 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int		hash_diff(char type, int len, int prec, int hash)
{
	if (hash == 0)
		return (0);
	if (type == 'o' && prec > len)
		return (0);
	if (type == 'x')
		return (2);
	if (type == 'X')
		return (3);
	return (1);
}

char	*ft_oxx(t_flags flags, char *nb, char type)
{
	int		len;
	int		mallocsize;
	char	*buff;

	buff = NULL;
	len = ft_strlen(nb);
	flags.hash = hash_diff(type, len, flags.precision, flags.hash);
	mallocsize = (flags.width > len && flags.width
			> flags.precision ? flags.width : len);
	mallocsize = (flags.precision > mallocsize ? flags.precision : mallocsize);
	if (flags.width <= len + (flags.hash - (flags.hash == 3)) && flags.hash > 0)
		mallocsize += (flags.hash - (flags.hash == 3));
	if (!(buff = ft_strnew(mallocsize)))
		return (NULL);
	if (flags.minus == 0)
		buff = ft_minus_0_oxx(flags, nb, buff, len);
	else
		buff = ft_minus_1_oxx(flags, nb, buff, len);
	return (buff);
}

char	*ft_minus_0_oxx(t_flags flags, char *nb, char *buff, int len)
{
	int		i;

	i = 0;
	while (flags.width > len && flags.width > flags.precision
			+ (flags.hash > 0) + (flags.hash > 1) && buff[i])
	{
		flags.width--;
		buff[i++] = ' ';
	}
	if ((flags.hash > 0))
	{
		if (flags.hash != 1 || (flags.hash == 1 && flags.precision < len))
			buff[i++] = '0';
		flags.hash == 2 ? buff[i++] = 'x' : 0;
		flags.hash == 3 ? buff[i++] = 'X' : 0;
	}
	while ((flags.precision > len) && (buff[i]))
	{
		flags.precision--;
		buff[i++] = '0';
	}
	while (*nb && buff[i])
		buff[i++] = *(nb++);
	return (buff);
}

char	*ft_minus_1_oxx(t_flags flags, char *nb, char *buff, int len)
{
	int	i;

	i = 0;
	if (flags.hash >= 1)
		buff[i++] = '0';
	if (flags.hash == 2)
		buff[i++] = 'x';
	if (flags.hash == 3)
		buff[i++] = 'X';
	while ((flags.precision - i + (flags.hash > 0) + (flags.hash > 1))
			> len && buff[i])
		buff[i++] = '0';
	while (*nb)
		buff[i++] = *(nb++);
	while (flags.width > len && flags.width > flags.precision && buff[i])
	{
		flags.width--;
		buff[i++] = ' ';
	}
	buff[i] = '\0';
	return (buff);
}
