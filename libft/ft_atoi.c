/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:19:46 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/19 14:04:52 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int var;
	int rslt;

	var = 0;
	rslt = 0;
	while (*str == ' ' || *str == '\r' || *str == '\v' || *str == '\f'
		|| *str == '\t' || *str == '\n')
		str++;
	if (*str == '-')
		var = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		rslt = (rslt * 10) + (*str - 48);
		str++;
	}
	if (var == 1)
		return (-rslt);
	else
		return (rslt);
}
