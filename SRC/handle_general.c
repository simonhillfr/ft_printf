/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_general.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 16:39:06 by shill             #+#    #+#             */
/*   Updated: 2016/09/18 16:41:25 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		placeholder(va_list ap, t_param *param)
{
	(void)(ap);
	if (param->minus == FALSE && param->width)
		print_width(param, 1);
	param->ret += ft_putchar('%');
	if (param->minus == TRUE && param->width)
		print_width(param, 1);
	return (END);
}

int		empty(va_list ap, t_param *param)
{
	(void)(ap);
	(void)(param);
	return (EMPTY);
}

int		digit(va_list ap, t_param *param)
{
	(void)(ap);
	(void)(param);
	return (DIGIT);
}
