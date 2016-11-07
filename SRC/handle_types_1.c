/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 16:31:19 by shill             #+#    #+#             */
/*   Updated: 2016/09/17 16:31:23 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_zero_exception(t_param *param, uintmax_t nb, char *str, int display)
{
	if (nb == 0 && display == FALSE)
	{
		param->hash = 0;
		if (param->precision == 0)
			str[0] = '\0';
	}
}

int	decimal(va_list ap, t_param *param)
{	
	intmax_t 	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, SIGNED);
	str = ft_itoadup(nb, 10);
	check_zero_exception(param, nb, str, FALSE);
	if (nb < 0)
	{
		param->negative = TRUE;
		final_print(param, str, "", -1);
	}
	else 
	{
		final_print(param, str, "", 1);
	}
	return (END);
}

int	udecimal(va_list ap, t_param *param)
{	
	uintmax_t 	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, UNSIGNED);
	str = ft_utoadup(nb, 10);
	check_zero_exception(param, nb, str, FALSE);
	final_print(param, str, "", 0);
	return (END);
}

int hexadecimal(va_list ap, t_param *param)
{
	uintmax_t	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, UNSIGNED);	
	str = ft_utoadup(nb, 16);
	check_zero_exception(param, nb, str, FALSE);
	final_print(param, str, "0x", 0);	
	return (END);
}

int upper_hexadecimal(va_list ap, t_param *param)
{
	uintmax_t 	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, UNSIGNED);
	str = ft_utoadup(nb, 16);
	check_zero_exception(param, nb, str, FALSE);
	ft_str_toupper(str);
	final_print(param, str, "0X", 0);
	return (END);	
}

int octal(va_list ap, t_param *param)
{
	uintmax_t	nb;
	char		*str;
	t_ftab_cast	*ftab_cast;
	int			display_prefix;

	ftab_cast = init_cast_array();
	nb = ftab_cast[param->length](ap, UNSIGNED);
	str = ft_utoadup(nb, 8);
	display_prefix = FALSE;
	if (param->hash && nb == 0) //octal exception to display 0 if nb==0 && #
	{
		param->hash = FALSE;
		display_prefix = TRUE;
	}
	check_zero_exception(param, nb, str, display_prefix);
	final_print(param, str, "0", 0);
	return (END);
}


