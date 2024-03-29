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
	char	*str;

	(void)(ap);
	str = ft_strdup("%");
	if (!(str))
		exit(EXIT_FAILURE);
	param->alpha = TRUE;
	final_print(param, str, "", 0);
	ft_memdel((void*)&str);
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
