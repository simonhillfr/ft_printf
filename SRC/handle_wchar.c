/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:13:15 by shill             #+#    #+#             */
/*   Updated: 2016/11/07 19:13:17 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	w_character(va_list ap, t_param *param)
{
	int value =va_arg(ap, unsigned int);
	param->ret += ft_put_wchar(value);	
	return (END);

	return (END);

}

int	w_string(va_list ap, t_param *param)
{
	(void)(ap);
	(void)(param);
	return (END);
}