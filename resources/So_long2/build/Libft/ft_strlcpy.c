/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:17:23 by side-lan          #+#    #+#             */
/*   Updated: 2025/05/29 17:44:48 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_length;
	size_t	counter;

	counter = 0;
	src_length = ft_strlen(src);
	if (size == 0)
		return (src_length);
	while (counter < size - 1 && src[counter] != '\0')
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (src_length);
}
