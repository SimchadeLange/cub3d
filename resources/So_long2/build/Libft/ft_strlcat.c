/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:15:34 by side-lan          #+#    #+#             */
/*   Updated: 2025/05/29 18:06:03 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	counter;
	size_t	src_len;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	counter = 0;
	if (size <= dst_len)
		return (size + src_len);
	while (dst_len + counter < size - 1 && src[counter] != '\0')
	{
		dst[dst_len + counter] = src[counter];
		counter++;
	}
	dst[dst_len + counter] = '\0';
	return (dst_len + src_len);
}
