/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:02:34 by ede-roo           #+#    #+#             */
/*   Updated: 2025/05/07 23:07:05 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*fs;
	unsigned char		c2;

	c2 = (unsigned char)c;
	fs = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (fs[i] == c2)
		{
			return ((void *)&fs[i]);
		}
		i++;
	}
	return (NULL);
}
