/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:45:13 by side-lan          #+#    #+#             */
/*   Updated: 2025/05/29 20:40:00 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			counter;
	unsigned char	*dest_str;
	unsigned char	*src_str;

	if (!src && !dest)
		return (NULL);
	counter = 0;
	dest_str = (unsigned char *)dest;
	src_str = (unsigned char *)src;
	while (counter < n)
	{
		dest_str[counter] = src_str[counter];
		counter++;
	}
	return (dest);
}
