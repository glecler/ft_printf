/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:00:20 by ravernhe          #+#    #+#             */
/*   Updated: 2019/09/04 17:49:12 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_float
{
	char		*sign;
	char		*exp;
	char		*sigd;
	float		nb;
	int			exp_int;
	int			sign_int;
	int			sigd_int;
}				t_float;

typedef	struct	s_flags
{
	int			hh;
	int			h;
	int			ll;
	int			l;
	int			L;
	int			hash;;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	int			precision;
	int			i;
	int			signe;
	int			dot;
}				t_flags;

/* floats.c */

char			*ft_ll_btoa(long long int n);
char			**ft_copy_bits(float f, char **sstr);
char			*ft_float_nb(t_float f, t_flags flags);
char			*ft_float(t_flags flags, char *nb);

/* printf.c */

int				ft_read(const char *restrict format, va_list ap, int ret);
int				ft_printf(const char *restrict format, ...);
char			*ft_fetch(const char *restrict format, va_list ap);

/* flags_finder.c */

int				ft_get_width(const char *format);
int				ft_get_precision(const char *format);
t_flags			ft_get_flags(const char *format, t_flags flags);
t_flags			ft_get_ls(const char *format, t_flags flags);
void			ft_init_flags(t_flags *flags);


/* flags_treatment_diu.c */

char			*ft_di(t_flags flags, char *nb);
char			*ft_minus_0(t_flags flags, char *nb, char *buff, long len);
char			*ft_minus_1(t_flags flags, char *nb, char *buff, long len);

/* flags_treatment_oxx.c */

char			*ft_oxx(t_flags flags, char *nb, char type);
char			*ft_minus_0_oxx(t_flags flags, char *nb, char *buff, int len);
char			*ft_minus_1_oxx(t_flags flags, char *nb, char *buff, int len);

/* flags_treatment_s.c */

char			*ft_s(char *str, t_flags flags);
char			*ft_minus_1_s(t_flags flags, char *str, char *buff, int len);
char			*ft_minus_0_s(t_flags flags, char *str, char *buff, int len);

/* type_ls_treatment.c */

char			*ft_treat(t_flags flags, char type, va_list ap);
char			*ft_di_nb(t_flags flags, va_list ap);
char			*ft_ouxx_nb(t_flags flags, va_list ap, char type);
char			*ft_easier(char c);

/* error_mgmt.c */

t_flags			minus_flags(t_flags flags);
t_flags			flags_comp(t_flags flags, char type);

/* utilitaries.c */

char			*ltoa(long long int n, int x, int i);
char			*u_ltoa(unsigned long long int n, char type, int x, int i);
char			*ft_strnew(long i);
int				get_nb(long long int nb, int base);
int				u_get_nb(unsigned long long int nb, int base);

long long int	ft_pow(int base, int x);
int				ft_putchar(char c);
int				ft_putstr(char *str);	
int				strchr2(int c, char *s);
const char		*ft_end(const char *format);

int				ft_strlen(char *str);

#endif
