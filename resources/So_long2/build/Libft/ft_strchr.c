/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:22:30 by side-lan          #+#    #+#             */
/*   Updated: 2025/06/02 20:45:29 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				counter;
	unsigned char	_char;

	_char = (unsigned char)c;
	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] == _char)
			return ((char *)str + counter);
		counter++;
	}
	if (_char == '\0')
		return ((char *)str + counter);
	return (NULL);
}
