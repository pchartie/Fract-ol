/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 23:38:07 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:32:22 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;

	s1_tmp = (unsigned char*)s1;
	s2_tmp = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (*s1_tmp != '\0' && *s2_tmp != '\0' && *s1_tmp == *s2_tmp && n != 0)
	{
		n--;
		if (n == 0)
			return (*s1_tmp - *s2_tmp);
		s1_tmp++;
		s2_tmp++;
	}
	return (*s1_tmp - *s2_tmp);
}
