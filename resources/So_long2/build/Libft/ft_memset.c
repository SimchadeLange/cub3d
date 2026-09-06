/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:22:58 by side-lan          #+#    #+#             */
/*   Updated: 2025/05/28 21:00:09 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			counter;
	unsigned char	*str_temp;

	counter = 0;
	str_temp = (unsigned char *)str;
	while (counter < n)
	{
		str_temp[counter] = c;
		counter++;
	}
	return (str);
}
