/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_treatment_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:47:48 by glecler           #+#    #+#             */
/*   Updated: 2019/10/19 12:50:38 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_easier(char c)
{
	char *str;

	if (!(str = ft_strnew(1)))
		return (NULL);
	*str = c;
	return (str);
}

char	*ft_strdup(char *str)
{
	char	*str_dup;
	int		i;

	i = 0;
	if (!(str_dup = ft_strnew(ft_strlen(str))))
		return (NULL);
	while (str[i])
	{
		str_dup[i] = str[i];
		i++;
	}
	return (str_dup);
}

char	*ft_minus_1_s(t_flags flags, char *str, char *buff, int len)
{
	int		i;
	char	c;

	i = 0;
	c = (flags.zero == 0 ? ' ' : '0');
	while (len-- > 0 && buff[i] && str[i])
	{
		buff[i] = str[i];
		i++;
	}
	while (flags.width - i > 0 && buff[i])
		buff[i++] = c;
	return (buff);
}

char	*ft_minus_0_s(t_flags flags, char *str, char *buff, int len)
{
	int		i;
	char	c;

	i = 0;
	c = (flags.zero == 0 ? ' ' : '0');
	while ((flags.width--) - len > 0 && buff[i])
		buff[i++] = c;
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
	if (!(str))
		return (ft_s("(null)", flags));
	len = (flags.dot > 0 ? flags.precision : ft_strlen(str));
	mallocsize = (flags.width > len ? flags.width : len);
	if (!(buff = ft_strnew(mallocsize)))
		return (NULL);
	if (flags.minus == 1)
		buff = ft_minus_1_s(flags, str, buff, len);
	else
		buff = ft_minus_0_s(flags, str, buff, len);
	free(str);
	return (buff);
}
