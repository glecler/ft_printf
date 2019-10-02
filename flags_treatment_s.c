/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_treatment_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:47:48 by glecler           #+#    #+#             */
/*   Updated: 2019/09/04 17:28:52 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_minus_1_s(t_flags flags, char *str, char *buff, int len)
{
	int	i;

	i = 0;
	while (len-- > 0 && buff[i] && str[i])
	{
		buff[i] = str[i];
		i++;
	}
	while (flags.width - i > 0 && buff[i])
		buff[i++] = ' ';
	return (buff);
}

char	*ft_minus_0_s(t_flags flags, char *str, char *buff, int len)
{
	int i;

	i = 0;
	while ((flags.width--) - len > 0 && buff[i])
		buff[i++] = ' ';
	while (len-- > 0 && buff[i])
	{
		buff[i] = *(str++);
		i++;
	}
	return (buff);
}

char	*ft_s(char *str, t_flags flags)
{
	char	*buff;
	int		mallocsize;
	int		len;

	buff = NULL;
	len = (flags.dot > 0 ? flags.precision : ft_strlen(str));
	mallocsize = (flags.width > len ? flags.width : len);
	if (!(buff = ft_strnew(mallocsize)))
		return (NULL);
	if (flags.minus == 1)
		buff = ft_minus_1_s(flags, str, buff, len);
	else
		buff = ft_minus_0_s(flags, str, buff, len);
	return (buff);
}
