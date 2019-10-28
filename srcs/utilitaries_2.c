/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaries_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 17:15:03 by glecler           #+#    #+#             */
/*   Updated: 2019/10/19 12:54:11 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				strchr2(int c, char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int				ft_putstr(char *str, char const *format)
{
	int		i;
	t_flags	flags;

	i = 0;
	ft_init_flags(&flags);
	flags = ft_get_flags(format + 1, flags);
	if (str[i] == '0' && flags.precision == 0 && flags.dot == 1)
		return (0);
	if (str[i] == 0)
		return (1);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int				ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

long long int	ft_pow(int base, int x)
{
	if (x != 0)
		return (base * ft_pow(base, x - 1));
	else
		return (1);
}

const char		*ft_end(const char *format)
{
	while (strchr2(*format, "% 01234.56789+-#hlzL") == 1)
		format++;
	while (strchr2(*format, "diouxXpcsf") == 1)
		format++;
	return (format);
}
