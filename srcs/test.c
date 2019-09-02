/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:17:30 by glecler           #+#    #+#             */
/*   Updated: 2019/09/02 13:22:47 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <float.h>
void	ft_init_flags(t_flags *flags)
{
	flags->hh = 0;
	flags->h = 0;
	flags->ll = 0;
	flags->l = 0;
	flags->L = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->dot = 0;
	flags->i = 0;
	flags->signe = 0;
}

long long int	ft_pow(int base, int x)
{
	if (x != 0)
		return (base * ft_pow(base, x - 1));
	else
		return (1);
}

char			*ft_strnew(int i)
{
	char	*str;
	int		x;

	x = -1;
	if (!(str = (char*)malloc((char)(i + 1))))
		return (NULL);
	while (++x < i)
		str[x] = '0';
	str[i] = '\0';
	return (str);
}

char			*ft_ll_btoa(long long int n)
{
	int		x;
	int		i;
	char	*nb;

	i = 0;
	x = 0;
	nb = ft_strnew(8);
	while ((n / ft_pow(2, x) >= 2) && x < 8)
		x++;
	x = 7;
	while (x >= 0)
	{
		nb[i] = (n / ft_pow(2, x) + 48);
		n = (n % ft_pow(2, x));
		x--;
		i++;
	}
	nb[i] = '\0';
	return (nb);
}

int				ft_bintoi(char *str, int x)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (str[i] != '\0')
	{
		sum = sum + ((str[i] - 48) * ft_pow(2, x));
		printf("str[i] [%c], x [%d], sum [%d]\n", str[i], x, sum);
		x--;
		i++;
	}
	return (sum);
}

char			**ft_copy_bits(float f, char **sstr)
{
	unsigned char	*str;
	int	i;
	
	i = 0;
	str = (unsigned char*)malloc(sizeof(unsigned char) * 5);
	str[4] = '\0';
	str = memcpy(str, &f, 4);
	printf("str : %hhu, %hhu, %hhu, %hhu \n", str[0], str[1], str[2], str[3]);
	sstr = (char**)malloc(sizeof(char*) * 5);
	sstr[4] = NULL;
	while (i < 4)
	{
		sstr[i] = ft_ll_btoa(str[i]);
		i++;
	}
	if (str)
		free(str);
	printf("bin : %s %s %s %s \n", sstr[3], sstr[2], sstr[1], sstr[0]);
	printf("s/exp/sigd : %c, %s%c, %s%s%s\n", ((sstr[3])[0]), (&(sstr[3])[1]), ((sstr[2])[0]), (&(sstr[2])[1]), sstr[1], sstr[0]);
	return (sstr);
}

char			*ft_strcat(char *s1, char *s2, char *dst)
{
	int i;

	i = 0;
	while (*s1 != '\0' && dst[i] != '\0')
	{
		dst[i] = *(s1++);
		i++;
	}
	while (*s2 != '\0' && dst[i] != '\0')
	{
		dst[i] = *(s2++);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char			*ft_float_nb(t_float f, t_flags flags)
{
	char			**str;
	char			*temp;
	char			*nb;


	temp = ft_strnew(16);
	str = ft_copy_bits(f.nb, str);
	f.sign = ft_strnew(1);
	f.sigd = ft_strnew(24);
	f.exp = ft_strnew(8);

	*(f.sign) = (str[3])[0];
	f.exp = ft_strcat((&(str[3])[1]), (&(str[2])[0]), f.exp);
	f.sigd = ft_strcat((&(str[2])[1]), ft_strcat(str[1], str[0], temp), f.sigd);
	printf("sign : [%c]\n", *(f.sign));
	printf("exp : [%s]\n", f.exp);
	printf("sigd : [%s]\n", f.sigd);
	f.exp_int = ft_bintoi(f.exp, 7) - 127;
	f.sigd_int = ft_bintoi(f.sigd, 22);
	printf("exp = [%d]\n", f.exp_int);
	printf("sigd = [%d]\n", f.sigd_int);
/*
	trouver exp
	2 ^ (precision - exp) = diviseur
	calculer sigd (prendre en compte bit implicite) = dividende (rentre dans long)
	
*/


	return (NULL);	
}

char			*ft_float(t_flags flags, char *nb)
{
	return (NULL);
}

int	main()
{
	t_flags flags;
	t_float	f;
	char	*nb;
	char	*buff;

	f.exp = NULL;
	f.sign = NULL;
	f.sigd = NULL;
	f.nb = FLT_MAX;
	ft_init_flags(&flags);
	flags.precision = 6;
	nb = ft_float_nb(f, flags);
	printf("nb : [%s]\n\n", nb);
	buff = ft_float(flags, nb);
	printf("real buff: [%f]\n", f.nb);
	printf("buff: [%s]\n", buff);
	return (0);
}
