/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:43:32 by glecler           #+#    #+#             */
/*   Updated: 2019/09/02 19:08:38 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			ret;

	ret = 0;
	va_start(ap, format);
	ret = ft_read(format, ap, ret);
	va_end(ap);
	return (ret);
}

int		ft_read(const char *restrict format, va_list ap, int ret)
{
	char	*nb;

	nb = NULL;
	while (*format)
	{
		if (*format != '%')
			ret += ft_putchar(*format);
		if (*format == '%')
		{
			if (*(format + 1) == '%')
			{
				format++;
				ret += ft_putchar('%');
			}
			else
			{
				nb = ft_fetch(format, ap);
				ret += ft_putstr(nb);
				free(nb);
				format = ft_end(format) - 1;
			}
		}
		format++;
	}
	return (ret);
}

char	*ft_fetch(const char *restrict format, va_list ap)
{
	t_flags		flags;
	char		type;

	ft_init_flags(&flags);
	flags = ft_get_flags(format, flags);
	format += flags.i + 1;
	flags = ft_get_ls(format, flags);
	format += flags.i;
	type = *format;
	return (ft_treat(flags, type, ap));
}
