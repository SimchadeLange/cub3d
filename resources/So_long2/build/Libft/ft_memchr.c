/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:18:09 by side-lan          #+#    #+#             */
/*   Updated: 2025/05/28 20:57:09 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			counter;
	unsigned char	*str_temp;
	unsigned char	temp;

	temp = (unsigned char)c;
	counter = 0;
	str_temp = (unsigned char *)str;
	while (counter < n)
	{
		if (str_temp[counter] == temp)
			return ((void *)str_temp + counter);
		counter++;
	}
	return (NULL);
}
