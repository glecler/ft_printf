/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:03:28 by glecler           #+#    #+#             */
/*   Updated: 2019/09/02 18:09:19 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strnew(long i)
{
	char	*str;
	int		x;

	x = -1;
	if (!(str = (char*)malloc((char)(i + 1))))
		exit(0);
	while (++x < i)
		str[x] = '0';
	str[i] = '\0';
	return (str);
}

const char		*ft_end(const char *format)
{
	while (strchr2(*format, "% 01234.56789+-#hlL") == 1)
		format++;
	while (strchr2(*format, "diouxXpcs") == 1)
		format++;
	return (format);
}

int				get_nb(long long int nb, int base)
{
	int i;

	i = 1;
	nb < 0 ? i++ : 0;
	if (nb == 0)
		i = 0;
	while (nb / base != 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char			*ltoa(long long int n, char type)
{
	int		base;
	char	*nb;
	int		x;
	int		i;

	x = 0;
	i = 0;
	type == 'd' || type == 'i' || type == 'u' ? base = 10 : 0;
	type == 'o' ? base = 8 : 0;
	type == 'x' || type == 'X' ? base = 16 : 0;
	if (!(nb = ft_strnew(get_nb(n, base))))
		return (NULL);
	if (n < 0)
	{
		n = -1 * n;
		nb[i++] = '-';
	}
	while ((n / ft_pow(base, x) >= 10))
		x++;
	while (x >= 0)
	{
		if (base > 10 && (n / ft_pow(base, x) >= 10))
			nb[i] = n / ft_pow(base, x) + (type == 'x' ? 87 : 55);
		else
			nb[i] = (n / ft_pow(base, x) + 48);
		n = (n % ft_pow(base, x));
		x--;
		i++;
	}
	return (nb);
}
