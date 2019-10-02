#include "ft_printf.h"

char    *ft_f_nb(t_flags flags, va_list ap)
{
    if (flags.dot == 0 && flags.precision == 0)
        flags.precision = 6;
    if (flags.l == 1)
        return(ftoa(va_arg(ap, double), 0, flags.precision));
    if (flags.L == 1)
        return(ftoa(va_arg(ap, long double), 0, flags.precision));
    return (ftoa(va_arg(ap, double), 0, flags.precision));
}

char    *ft_floats(char *nb, t_flags flags)
{
    char    *buff;
    int     mallocsize;
    int     len;

    buff = NULL;
    if (*nb == '-')
		flags = minus_flags(flags);
    len = ft_strlen(nb) + flags.hash + (flags.plus - (*nb == 1));
    mallocsize = (flags.width > len ? flags.width : len);
    if (!(buff = ft_strnew(mallocsize)))
        return (NULL);
    if (flags.minus == 0)
        buff = ft_minus_0_f(flags, nb, buff, len);
    else
        buff = ft_minus_1_f(flags, nb, buff, len);
    return (buff);
}

char    *ft_minus_0_f(t_flags flags, char *nb, char *buff, long len)
{
    int	i;
	char	c;

	i = 0;
	if (flags.space == 1 && *nb != '-')
		buff[i++] = ' ';
	c = (flags.zero == 1 && flags.minus == 0 ? '0' : ' ');
	if (*nb == '-' && flags.zero == 1)
		buff[i++] = *(nb++);
	while (flags.width > len + flags.space)
	{
		flags.width--;
		buff[i++] = c;
	}
	*nb == '-' && flags.zero == 0 ? buff[i++] = *(nb++) : 0;
	if (flags.zero == 0 && flags.plus == 1)
		buff[i++] = (*nb == '-' ? '-' : '+');
	nb = (*nb == '-' && flags.plus == 1 ? nb + 1 : nb);
	while (buff[i] && *nb)
		buff[i++] = *(nb++);
    if (flags.hash == 1 && ft_c_in_str('.', nb) == 0)
        buff[i++] = '.';
	return (buff);
}

char	*ft_minus_1_f(t_flags flags, char *nb, char *buff, long len)
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
	while (*nb)
		buff[i++] = *(nb++);
    if (flags.hash == 1 && ft_c_in_str('.', nb) == 0)
        buff[i++] = '.';
	while (flags.width > len + flags.space)
	{
		flags.width--;
		buff[i++] = ' ';
	}
	return (buff);
}