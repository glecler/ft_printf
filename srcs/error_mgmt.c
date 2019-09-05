/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:04:19 by glecler           #+#    #+#             */
/*   Updated: 2019/09/04 17:29:37 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	minus_flags(t_flags flags)
{
	flags.plus = 0;
	flags.signe = 1;
	flags.space = 0;
	return (flags);
}

t_flags	flags_comp(t_flags flags, char type)
{
	if (strchr2(type, "oxX") == 1)
		;
	if (flags.plus == 1)
		flags.space = 0;
	return (flags);
}
