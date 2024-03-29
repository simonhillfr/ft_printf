/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 12:22:18 by shill             #+#    #+#             */
/*   Updated: 2015/12/27 12:22:44 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	char		*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] != c)
		return (0);
	str = (char *)s;
	return (&str[i]);
}
