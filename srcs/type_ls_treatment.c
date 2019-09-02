/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ls_treatment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:23:01 by glecler           #+#    #+#             */
/*   Updated: 2019/09/02 18:56:15 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_easier(char c)
{
	char *nb;

	if (!(nb = ft_strnew(1)))
		exit(0);
	*nb = c;
	return (nb);
}

char	*ft_treat(t_flags flags, char type, va_list ap)
{
	char *buff;

	flags = flags_comp(flags, type);
	if (strchr2(type, "di") == 1)
		buff = ft_di(flags, ft_di_nb(flags, ap, type));
	if (strchr2(type, "oxX") == 1)
		buff = ft_oxx(flags, ft_ouxx_nb(flags, ap, type), type);
	if (strchr2(type, "u") == 1)
		buff = ft_di(flags, ft_ouxx_nb(flags, ap, type));
	if (type == 'c')
		buff = ft_di(flags, ft_easier(va_arg(ap, int)));
	if (type == 's')
		buff = ft_s(va_arg(ap, char*), flags);
	if (type == 'p')
		buff = ft_oxx(flags, ft_fetch("%#llx", ap), type);
	return (buff);
}

/*
	if (type == 'f')
		buff = ft_float(flags, ft_float_nb(ap, flags));
*/

t_flags	flags_comp(t_flags flags, char type)
{
	if (strchr2(type, "oxX") == 1)
	{
		flags.space = 0;
		flags.plus = 0;
	}
	if (flags.plus == 1)
		flags.space = 0;
	return (flags);
}

char	*ft_di_nb(t_flags flags, va_list ap, char type)
{
	long long int	lli;

	if (flags.h == 1)
	{
		lli = (long long int)(va_arg(ap, int));
		return (ltoa(lli, type));
	}
	if (flags.hh == 1)
		return (ltoa(va_arg(ap, int), type));
	if (flags.l == 1)
		return (ltoa(va_arg(ap, long int), type));
	if (flags.ll == 1)
		return (ltoa(va_arg(ap, long long int), type));
	return (ltoa(va_arg(ap, int), type));
}

char	*ft_ouxx_nb(t_flags flags, va_list ap, char type)
{
	char *nb;

	if (flags.h == 1)
		return (nb = ltoa(va_arg(ap, int), type));
	if (flags.hh == 1)
		return (nb = ltoa(va_arg(ap, int), type));
	if (flags.l == 1)
		return (nb = ltoa(va_arg(ap, unsigned long int), type));
	if (flags.ll == 1)
		return (nb = ltoa(va_arg(ap, unsigned long long int), type));
	if (type == 'u')
		nb = ltoa(va_arg(ap, unsigned int), type);
	else
		nb = ltoa(va_arg(ap, int), type);
	return (nb);
}
