/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:33:57 by ede-roo           #+#    #+#             */
/*   Updated: 2025/05/07 23:07:09 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*fs1;
	const unsigned char	*fs2;

	fs1 = (unsigned char *) s1;
	fs2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (fs1[i] != fs2[i])
		{
			return (fs1[i] - fs2[i]);
		}
		i++;
	}
	return (0);
}
