/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:41:19 by ede-roo           #+#    #+#             */
/*   Updated: 2025/05/07 23:11:38 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*fsrc;
	unsigned char	*fdest;

	fdest = (unsigned char *)dest;
	fsrc = (unsigned char *)src;
	if (fdest == fsrc || n == 0)
		return (dest);
	if (fdest < fsrc)
	{
		i = 0;
		while (i < n)
		{
			fdest[i] = fsrc[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			fdest[i] = fsrc[i];
	}
	return (dest);
}
