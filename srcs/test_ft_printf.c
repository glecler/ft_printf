/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created]: 2019/08/20 13:07:24 by glecler           #+#    #+#             */
/*   Upd]ated]: 2019/08/20 13:49:57 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	int a = 123456;
	void *p = &a;
	short int si = 456;
	long int li = 456456456;
	long long int lli = 456456456456;
	
	printf("ret : [%d]\n", ft_printf("[%p] \n", p));
	printf("ret : [%d]\n", printf("[%p] \n", p));
	
	ft_printf("[%50p] \n", p);
	printf("[%50p] \n\n", p);

	ft_printf("[%-50p] \n", p);
	printf("[%-50p] \n\n", p);

	ft_printf(" %-50d] \n", a);
	printf(" %-50d] \n\n", a);
	
	ft_printf(" %.7d] \n", a);
	printf(" %.7d] \n\n", a);
	
	ft_printf(" %10.8d] \n", a);
	printf(" %10.8d] \n\n", a);
	
	ft_printf(" %-5d] \n", a);
	printf(" %-5d] \n\n", a);
	
	ft_printf(" %-5.14d] \n", a);
	printf(" %-5.14d] \n\n", a);
	
	ft_printf(" [%+-5.14d] \n", a);
	printf(" [%+-5.14d] \n\n", a);
	
	ft_printf(" %05.14d] \n", a);
	printf(" %05.14d] \n\n", a);
	
	ft_printf(" % 5.14d] \n", a);
	printf(" % 5.14d] \n\n", a);
	
	ft_printf(" % 5.14ld] \n", li);
	printf(" % 5.14ld] \n\n", li);
	
	ft_printf(" % 5.14lld] \n", lli);
	printf(" % 5.14lld] \n\n", lli);

	ft_printf(" %5.14hu] \n", si);
	printf(" %5.14hu] \n\n", si);
	
	
	ft_printf(" %o] \n", a);
	printf(" %o] \n\n", a);
	
	ft_printf(" %5o] \n", a);
	printf(" %5o] \n\n", a);
	
	ft_printf(" %.7o] \n", a);
	printf(" %.7o] \n\n", a);
	
	ft_printf("[%10.8o] \n", a);
	printf("[%10.8o] \n\n", a);
	
	ft_printf(" %#5.14o] \n", a);
	printf(" %#5.14o] \n\n", a);
	
	ft_printf(" %5.14o] \n", a);
	printf(" %5.14o] \n\n", a);

	ft_printf(" %#x] \n", a);
	printf(" %#x] \n\n", a);
	
	ft_printf(" %5x] \n", a);
	printf(" %5x] \n\n", a);
	
	ft_printf(" %.7x] \n", a);
	printf(" %.7x] \n\n", a);
	
	ft_printf(" %10.8x] \n", a);
	printf(" %10.8x] \n\n", a);
	
	ft_printf("[%#14.5X] \n", a);
	printf("[%#14.5X] \n\n", a);
	
	ft_printf("[%27.10x] \n", a);
	printf("[%27.10x] \n\n", a);

	char c;
	c = 'A';

	ft_printf(" %c] \n", c);
	printf(" %c] \n\n", c);
	
	ft_printf("[%10c] \n", c);
	printf("[%10c] \n\n", c);
	
	ft_printf(" %-5c] \n", c);
	printf(" %-5c] \n\n", c);
	char *s = "bonjour\0";

	ft_printf(" [%s] \n", s);
	printf(" [%s] \n\n", s);
	
	ft_printf("[%10s] \n", s);
	printf("[%10s] \n\n", s);
	
	ft_printf(" [%-5s] \n", s);
	printf(" [%-5s] \n\n", s);

	ft_printf(" [%.2s] \n", s);
	printf(" [%.2s] \n\n", s);
	
	ft_printf("[%10.2s] \n", s);
	printf("[%10.2s] \n\n", s);
	
	ft_printf(" %.2147483646d] \n\n", a);
	printf(" %.2147483647d] \n\n", a);
	return (0);
}
