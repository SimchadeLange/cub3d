/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:52:18 by side-lan          #+#    #+#             */
/*   Updated: 2025/05/29 17:56:05 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t			counter;
	unsigned char	*dest_str;
	unsigned char	*src_str;

	if (!dest && !src)
		return (NULL);
	counter = 0;
	dest_str = (unsigned char *)dest;
	src_str = (unsigned char *)src;
	if (dest_str < src_str)
	{
		while (counter < n)
		{
			dest_str[counter] = src_str[counter];
			counter++;
		}
	}
	else
	{
		counter = n;
		while (counter-- > 0)
			dest_str[counter] = src_str[counter];
	}
	return (dest);
}
