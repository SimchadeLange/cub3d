/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:18:25 by side-lan          #+#    #+#             */
/*   Updated: 2025/05/28 20:58:32 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			counter;
	unsigned char	*temp_1;
	unsigned char	*temp_2;

	counter = 0;
	temp_1 = (unsigned char *) s1;
	temp_2 = (unsigned char *)s2;
	while (counter < n)
	{
		if (temp_1[counter] != temp_2[counter])
			return (temp_1[counter] - temp_2[counter]);
		counter++;
	}
	return (0);
}
