/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:40:43 by side-lan          #+#    #+#             */
/*   Updated: 2025/05/28 21:26:28 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			counter;
	unsigned char	*str;

	counter = 0;
	str = (unsigned char *)s;
	while (counter < n)
	{
		str[counter] = '\0';
		counter++;
	}
}
