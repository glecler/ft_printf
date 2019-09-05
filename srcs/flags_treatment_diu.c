/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_treatment_diu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 15:33:28 by glecler           #+#    #+#             */
/*   Updated: 2019/09/04 17:28:25 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_di(t_flags flags, char *nb)
{
	long	len;
	long	mallocsize;
	char	*buff;

	if (*nb == '-')
		flags = minus_flags(flags);
	if (flags.zero == 1 && flags.precision > 0)
		flags.zero = 0;
	len = flags.plus - (*nb == '-') + (ft_strlen(nb));
	mallocsize = (flags.width > len && flags.width >
			flags.precision ? flags.width : len);
	mallocsize = (flags.precision > mallocsize ? flags.precision : mallocsize);
	mallocsize += flags.space + flags.plus;
	if (!(buff = ft_strnew(mallocsize)))
		return (NULL);
	if (flags.minus == 0)
		buff = ft_minus_0(flags, nb, buff, len);
	else
		buff = ft_minus_1(flags, nb, buff, len);
	return (buff);
}

char	*ft_minus_0(t_flags flags, char *nb, char *buff, long len)
{
	int		i;
	char	c;

	i = 0;
	if (flags.space == 1 && *nb != '-')
		buff[i++] = ' ';
	c = (flags.zero == 1 && flags.minus == 0 ? '0' : ' ');
	if (*nb == '-' && flags.zero == 1 && flags.precision == 0)
		buff[i++] = *(nb++);
	while (flags.width > len + flags.signe + flags.space && flags.width >
			flags.precision + flags.plus + flags.signe + flags.space)
	{
		flags.width--;
		buff[i++] = c;
	}
	*nb == '-' && flags.zero == 0 ? buff[i++] = *(nb++) : 0;
	if (flags.zero == 0 && flags.plus == 1)
		buff[i++] = (*nb == '-' ? '-' : '+');
	nb = (*nb == '-' && flags.plus == 1 ? nb + 1 : nb);
	while (flags.precision-- > (len - flags.plus))
		buff[i++] = '0';
	while (buff[i] && *nb)
		buff[i++] = *(nb++);
	return (buff);
}

char	*ft_minus_1(t_flags flags, char *nb, char *buff, long len)
{
	int i;

	i = 0;
	if (flags.space == 1 && *nb != '-')
		buff[i++] = ' ';
	if (flags.plus == 1 && *nb != '-')
		buff[i++] = '+';
	if (*nb == '-')
	{
		buff[i++] = '-';
		nb++;
	}
	while (flags.precision - i + flags.plus > len -
			flags.plus - flags.space - flags.signe)
		buff[i++] = '0';
	while (*nb)
		buff[i++] = *(nb++);
	while (flags.width > len + flags.space + flags.signe && flags.width >
			flags.precision + flags.plus + flags.space + flags.signe)
	{
		flags.width--;
		buff[i++] = ' ';
	}
	return (buff);
}
