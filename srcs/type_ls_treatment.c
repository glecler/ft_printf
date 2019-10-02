/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ls_treatment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:23:01 by glecler           #+#    #+#             */
/*   Updated: 2019/09/04 17:04:47 by glecler          ###   ########.fr       */
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
	char *nb;

	nb = NULL;
	flags = flags_comp(flags, type);
	if (strchr2(type, "di") == 1)
	{
		nb = ft_di_nb(flags, ap);
		buff = ft_di(flags, nb);
	}
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
	if (type == 'f')
		buff = ft_floats(ft_f_nb(flags, ap), flags);
	return (buff);
}

char	*ft_di_nb(t_flags flags, va_list ap)
{
	if (flags.h == 1)
		return (ltoa((va_arg(ap, int)), 0, 0));
	if (flags.hh == 1)
		return (ltoa(va_arg(ap, int), 0, 0));
	if (flags.l == 1)
		return (ltoa(va_arg(ap, long int), 0, 0));
	if (flags.ll == 1)
		return (ltoa(va_arg(ap, long long int), 0, 0));
	return (ltoa(va_arg(ap, int), 0, 0));
}

char	*ft_ouxx_nb(t_flags flags, va_list ap, char type)
{
	char *nb;

	if (flags.h == 1)
	{
		nb = u_ltoa(va_arg(ap, int), type, 0, 0);
		return (nb);
	}
	if (flags.hh == 1)
		return (nb = u_ltoa(va_arg(ap, int), type, 0, 0));
	if (flags.l == 1)
		return (nb = u_ltoa(va_arg(ap, unsigned long int), type, 0, 0));
	if (flags.ll == 1)
		return (nb = u_ltoa(va_arg(ap, unsigned long long int), type, 0, 0));
	if (type == 'u')
		nb = u_ltoa(va_arg(ap, unsigned int), type, 0, 0);
	else
		nb = u_ltoa(va_arg(ap, int), type, 0, 0);
	return (nb);
}
